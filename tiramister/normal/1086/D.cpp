#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

map<char, int> hand = {{'R', 0}, {'S', 1}, {'P', 2}};

class BIT {
public:
    // Nv
    explicit BIT(int N, int v) : V_NUM(N) {
        data.resize(N);
        fill(data.begin(), data.end(), v);
    }

    // [1, i]
    int query(int i) {
        int ret = 0;
        while (i > 0) {
            ret += data[i];
            i -= (i & -i);
        }
        return ret;
    }

    // data[i]v
    void update(int i, int v) {
        while (i < V_NUM) {
            data[i] += v;
            i += (i & -i);
        }
    }

    int V_NUM;
    vector<int> data;
};

int main() {
    int N, Q;
    string S;
    cin >> N >> Q >> S;

    S = "$" + S;

    vector<BIT> bit(3, BIT(N + 1, 0));
    vector<set<int>> pos(3);

    for (int i = 1; i <= N; ++i) {
        bit[hand[S[i]]].update(i, 1);
        pos[hand[S[i]]].insert(i);
    }

    for (int q = 0; q <= Q; ++q) {
        int lose = 0;

        int emp = 0;
        for (int h = 0; h < 3; ++h) {
            if (pos[h].empty()) ++emp;
        }

        if (emp == 1) {
            for (int h = 0; h < 3; ++h) {
                if (pos[h].empty() || pos[(h + 1) % 3].empty()) continue;
                lose = pos[(h + 1) % 3].size();
            }
        } else if (emp == 0) {
            for (int h = 0; h < 3; ++h) {
                int w = (h + 1) % 3, l = (h + 2) % 3;

                int wpos = *(pos[w].begin()), lpos = *(pos[l].begin());
                lose += max(0, bit[h].query(wpos) - bit[h].query(lpos));

                wpos = *(--pos[w].end()), lpos = *(--pos[l].end());
                lose += max(0, bit[h].query(lpos) - bit[h].query(wpos));
            }
        }

        cout << N - lose << endl;

        if (q == Q) break;

        int p;
        char c;
        cin >> p >> c;

        bit[hand[S[p]]].update(p, -1);
        pos[hand[S[p]]].erase(p);

        bit[hand[c]].update(p, 1);
        pos[hand[c]].insert(p);

        S[p] = c;
    }

    return 0;
}