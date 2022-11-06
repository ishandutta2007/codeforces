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

const int MAXN = 200 + 1;

int win[MAXN][MAXN];
vi v;

int ask(int i, int j){
    if(win[i][j]) return win[i][j];
    printf("? %d %d\n", i, j);
    fflush(stdout);
    char ans[4];
    scanf("%s", ans);
    if(ans[0] == '<'){
        win[i][j] = -1;
        win[j][i] = 1;
    }
    else{
        win[i][j] = 1;
        win[j][i] = -1;
    }
    return win[i][j];
}

void full_ask(vi &v){
    for(int i = 0; i < (int)v.size(); i++){
        for(int j = 0; j < (int)v.size(); j++){
            if(i == j) continue;
            ask(v[i], v[j]);
        }
    }
}

void solve(){
    int n;
    scanf("%d", &n);
    int n2 = 2 * n;
    for(int i = 1; i <= n2; i++){
        for(int j = 1; j <= n2; j++){
            win[i][j] = 0;
        }
    }
    v.clear();
    for(int i = 1; i < n2; i += 2){
        if(ask(i, i + 1) < 0) v.pb(i);
        else v.pb(i + 1);
    }
    full_ask(v);
    int middle = 0; // our "4"
    int top_among_weak = 0; // our "2"
    for(int i = 0; i < n; i++){
        int cand = v[i];
        int lose_cnt = 0;
        for(int j = 1; j <= n2; j++){
            if(cand != j && win[j][cand] > 0){
                lose_cnt++;
            }
        }
        if(lose_cnt == 1){
            top_among_weak = cand;
        }
        if(lose_cnt == 2){
            middle = cand;
        }
    }
    for(int i = 1; i <= n2; i += 2){
        if(ask(i, i + 1) > 0) ask(i, middle);
        else ask(i + 1, middle);
    }

    int in_deg = 0;
    for(int i = 1; i <= n2; i++){
        if(i == middle) continue;
        if(ask(i, middle) > 0) in_deg++;
    }
    if(in_deg == n + 1){
        // middle is (n+2)^th player
        // need to eliminate one top player from list
        v.clear();

        int winner_of_strong_weak = (top_among_weak & 1) ?
                top_among_weak + 1 : top_among_weak - 1;
        for(int i = 1; i <= n2; i += 2){
            if(i == winner_of_strong_weak || i + 1 == winner_of_strong_weak) continue;
            if(ask(i, i + 1) > 0) v.pb(i);
            else v.pb(i + 1);
        }
        full_ask(v);
        // need to find the weakest among v (our "7")
        int weakest = -1, weakest_in_deg;
        for(int i = 0; i < (int)v.size(); i++){
            in_deg = 0;
            for(int j = 0; j < (int)v.size(); j++){
                if(i == j) continue;
                if(ask(v[i], v[j]) < 0) in_deg++;
            }
            if(weakest == -1 || weakest_in_deg < in_deg){
                weakest = v[i];
                weakest_in_deg = in_deg;
            }
        }

        ask(top_among_weak, weakest);
    }
    else{
        v.clear();
        for(int i = 1; i <= n2; i++){
            if(i == middle) continue;
            if(ask(middle, i) > 0){
                v.pb(i);
            }
        }
        full_ask(v);
    }
    printf("!\n");
    fflush(stdout);
}

int main() {
    #ifdef NASTYA
      //  assert(freopen("input.txt", "r", stdin)); assert(freopen("output.txt", "w", stdout));
    #else
    // assert(freopen(file".in", "r", stdin)); assert(freopen(file".out", "w", stdout));
    #endif
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}