#include <bits/stdc++.h>

#define iter(a) a.begin(), a.end()
#define lsort(a) sort(cont(a))
#define gsort(a) sort(cont(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)

//#define TEST

#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    for(int testcase = 0; testcase < t; testcase++){

        ll n, k;
        cin >> n >> k;

        ll ans = 0;

        while(n > 0){
            if(n % k == 0){
                n /= k;
                ans++;
                continue;
            }
            ll temp = n / k * k;
            ans += n - temp;
            n = temp;
        }

        cout << ans << "\n";

    }
    
    return 0;
}