#include <bits/stdc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define printv(a, b) bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n"

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 1000000001;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    ll ans = 0;
    int llast = -1;
    int last;
    cin >> last;
    for(int i = 1; i < n; i++){
        int a;
        cin >> a;
        if(last == 1){
            if(a == 2){
                ans += 3;
            }
            else{
                ans += 4;
            }
        }
        else if(last == 2){
            if(a == 1){
                ans += 3;
            }
            else{
                ans = -1;
                break;
            }
        }
        else{
            if(a == 1){
                ans += 4;
            }
            else{
                ans = -1;
                break;
            }
        }

        if(a == 2 && llast == 3){
            ans--;
        }
        llast = last;
        last = a;
    }

    if(ans == -1){
        cout << "Infinite\n";
    }
    else{
        cout << "Finite\n" << ans << "\n";
    }

    return 0;
}