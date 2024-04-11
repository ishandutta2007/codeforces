//#define NDEBUG

#include <bits/stdc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define F first
#define S second
#define B back()
#define FR front()
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tiii tuple<int, int, int>
#define mt make_tuple
#define gt(t, i) get<i>(t)

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

int main(){
    StarBurstStream

    int T;
    cin >> T;

    while(T--){

        int r, c;
        cin >> r>> c;

        vector<string> p(r);
        bool ans = false;
        for(int i = 0; i < r; i++){
            cin >> p[i];
            for(int j = 0; j < c; j++) if(p[i][j] == 'A') ans = true;
        }

        if(!ans){
            cout << "MORTAL\n";
            continue;
        }

        ans = true;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j ++) if(p[i][j] == 'P') ans = false;
        }
        if(ans){
            cout << "0\n";
            continue;
        }


        ans = true;
        for(int i = 0; i < c; i++) if(p[0][i] == 'P') ans = false;
        if(ans){
            cout << "1\n";
            continue;
        }
        ans = true;
        for(int i = 0; i < c; i++) if(p[r - 1][i] == 'P') ans = false;
        if(ans){
            cout << "1\n";
            continue;
        }
        ans = true;
        for(int i = 0; i < r; i++) if(p[i][0] == 'P') ans = false;
        if(ans){
            cout << "1\n";
            continue;
        }
        ans = true;
        for(int i = 0; i < r; i++) if(p[i][c - 1] == 'P') ans = false;
        if(ans){
            cout << "1\n";
            continue;
        }


        if(p[0][0] == 'A' || p[r - 1][c - 1] == 'A' || p[r - 1][0] == 'A' || p[0][c - 1] == 'A'){
            cout << "2\n";
            continue;
        }

        for(int i = 0; i < r; i++){
            ans = true;
            for(int j = 0; j < c; j++) if(p[i][j] == 'P') ans = false;
            if(ans){
                cout << "2\n";
                break;
            }
        }
        if(ans) continue;

        for(int i = 0; i < c; i++){
            ans = true;
            for(int j = 0; j < r; j++) if(p[j][i] == 'P') ans = false;
            if(ans){
                cout << "2\n";
                break;
            }
        }
        if(ans) continue;


        ans = false;
        for(int i = 0; i < c; i++) if(p[0][i] == 'A') ans = true;
        for(int i = 0; i < c; i++) if(p[r - 1][i] == 'A') ans = true;
        for(int i = 0; i < r; i++) if(p[i][0] == 'A') ans = true;
        for(int i = 0; i < r; i++) if(p[i][c - 1] == 'A') ans = true;
        if(ans){
            cout << "3\n";
            continue;
        }

        cout << "4\n";

    }

    return 0;
}