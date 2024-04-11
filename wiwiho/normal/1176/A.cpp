#include <bits/stdc++.h>

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

#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

#define MAX 1000000001

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;

    for(int testcase = 0; testcase < q; testcase++){

        ll n;
        cin >> n;

        ll ans = 0;
        while(n % 5 == 0){
            ans++;
            n = n * 4 / 5;
        }
        while(n % 3 == 0){
            ans++;
            n = n * 2 / 3;
        }
        while(n % 2 == 0){
            ans++;
            n /= 2;
        }
        if(n > 1){
            cout << "-1\n";
        }
        else{
            cout << ans << "\n";
        }

    }
    
    return 0;
}