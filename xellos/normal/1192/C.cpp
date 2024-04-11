#include <bits/stdc++.h>
using namespace std;
 
class Solver {
    constexpr static unsigned long long MOD = 998244353;
    constexpr static int MAX_L = 10;
    constexpr static int MAX_CHAR_ID = 62;
 
    vector<string> words[MAX_L+1];
 
    unsigned char rotations[1<<24];
 
    inline int encode_char(char c) {
        if(c >= 'a' && c <= 'z')
            return c-'a';
        else if(c >= 'A' && c <= 'Z')
            return c-'A'+26;
        else // if(c >= '0' && c <= '9')
            return c-'0'+52;
    }
 
    inline bool unpack(int packed_seq, int * seq) {
        for(int i = 0; i < 4; i++) {
            seq[3-i] = packed_seq & 63;
            if(seq[3-i] >= MAX_CHAR_ID) return false;
            packed_seq >>= 6;
        }
        return true;
    }
 
    inline int pack(int * seq) {
        int ret = 0;
        for(int i = 0; i < 4; i++) ret = (ret << 6) | seq[i];
        return ret;
    }
 
    unsigned long long solve(int L) {
        unsigned int cnt_by_end_chars[MAX_CHAR_ID][MAX_CHAR_ID];
        memset(cnt_by_end_chars, 0, sizeof(cnt_by_end_chars));
        set<string> w;
        for(string & word : words[L]) {
            w.insert(word);
            reverse(word.begin(), word.end());
            w.insert(word);
        }
        for(const string & word : w) {
            int start_char_id = encode_char(word[0]);
            int end_char_id = encode_char(word[L-1]);
            cnt_by_end_chars[start_char_id][end_char_id]++;
        }
 
        unsigned int cnt_by_vertices[MAX_CHAR_ID][MAX_CHAR_ID][MAX_CHAR_ID];
        memset(cnt_by_vertices, 0, sizeof(cnt_by_vertices));
        int seq[4];
        for(int i = 0; i < (1<<18); i++) {
            if(!unpack(i<<6, seq)) continue;
            unsigned long long sum_cnt = 0;
            for(int j = 0; j < MAX_CHAR_ID; j++) {
                unsigned long long cnt = 1;
                for(int k = 0; k < 3; k++)
                    cnt = cnt * cnt_by_end_chars[seq[k]][j];
                sum_cnt += cnt;
                if(sum_cnt >= 5*MOD*MOD) sum_cnt -= 5*MOD*MOD;
            }
            cnt_by_vertices[seq[0]][seq[1]][seq[2]] = sum_cnt % MOD;
        }
 
        unsigned long long ret = 0;
        for(int i = 0; i < (1<<24); i++) if(rotations[i]) {
            if(!unpack(i, seq)) continue;
            unsigned long long cnt = rotations[i];
            int V_seq[3];
            for(int j = 0; j < 3; j++) V_seq[j] = seq[j];
            for(int j = 0; j < 4; j++) {
                cnt = cnt * cnt_by_vertices[V_seq[0]][V_seq[1]][V_seq[2]] % MOD;
                if(j < 3) V_seq[2-j] = seq[3-j];
            }
            ret += cnt;
            if(ret >= MOD) ret -= MOD;
        }
 
        return ret;
    }
 
public:
    Solver(vector<string> words_) {
        for(int i = 0; i < (int)words_.size(); i++) {
            string w = words_[i];
            words[w.length()].push_back(w);
        }
 
        memset(rotations, 0, sizeof(rotations));
        int seq_sorted[4];
        for(int i = 0; i < (1<<24); i++) {
            if(!unpack(i, seq_sorted)) continue;
            for(int j = 0; j < 3; j++) for(int k = 1; k < 4; k++)
                if(seq_sorted[j] > seq_sorted[k]) swap(seq_sorted[j], seq_sorted[k]);
            rotations[pack(seq_sorted)]++;
        }
    }
 
    unsigned long long solve() {
        unsigned long long ret = 0;
        for(int l = 2; l <= MAX_L; l++) {
            ret += solve(l);
            if(ret >= MOD) ret -= MOD;
        }
        return ret;
    }
};
 
int main() {
    cin.sync_with_stdio(0);
    int N;
    cin >> N;
    vector<string> words(N);
    for(int i = 0; i < N; i++) cin >> words[i];
    Solver solver(words);
    cout << solver.solve() << "\n";
}