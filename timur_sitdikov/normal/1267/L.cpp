#include <bits/stdc++.h>
using namespace std;


#define file "file"
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef complex<double> point;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define DEBUG 0
#define dout if(DEBUG) cout

const int MAXN = 1e3 + 5;
const int ALP = 26;

char ans[MAXN][MAXN];
int n, L, k;
int cnt[ALP];
char s[MAXN * MAXN];
int mx_exist_let, mn_exist_let;

void rec_sol(int pos, int from, int to, bool differ){
    if(pos == L || from > to) return;
    if(differ){
        for(int i = to; i >= from; i--){
            while(mx_exist_let >= 0 && !cnt[mx_exist_let]) mx_exist_let--;
            ans[i][pos] = 'a' + mx_exist_let;
            cnt[mx_exist_let]--;
        }
        rec_sol(pos + 1, from, to, differ);
    }
    else{
        for(int i = from; i <= k; i++){
            while(mn_exist_let < ALP && !cnt[mn_exist_let]) mn_exist_let++;
            ans[i][pos] = 'a' + mn_exist_let;
            cnt[mn_exist_let]--;
        }
        for(int i = to; i > k; i--){
            while(mx_exist_let >= 0 && !cnt[mx_exist_let]) mx_exist_let--;
            ans[i][pos] = 'a' + mx_exist_let;
            cnt[mx_exist_let]--;
        }
        int same_from, same_to;
        for(int i = k; i <= to; i++){
            if(ans[i][pos] == ans[k][pos]) same_to = i;
        }
        for(int i = k; i >= from; i--){
            if(ans[i][pos] == ans[k][pos]) same_from = i;
        }
        rec_sol(pos + 1, from, same_from - 1, 1);
        rec_sol(pos + 1, same_from, same_to, 0);
        rec_sol(pos + 1, same_to + 1, to, 1);
    }
}

void solve(){
    cin >> n >> L >> k;
    k--;
    scanf("%s", s);
    int sn = strlen(s);
    for(int i = 0; i < sn; i++){
        cnt[s[i] - 'a']++;
    }
    mx_exist_let = 25;
    mn_exist_let = 0;
    rec_sol(0, 0, n - 1, 0);

    for(int i = 0; i < n; i++){
        printf("%s\n", ans[i]);
    }
}

int main() {
    #ifdef NASTYA
        assert(freopen("input.txt", "r", stdin)); assert(freopen("output.txt", "w", stdout));
    #else
    // assert(freopen(file".in", "r", stdin)); assert(freopen(file".out", "w", stdout));
    #endif
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}