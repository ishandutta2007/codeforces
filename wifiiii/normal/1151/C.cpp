
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <deque>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
ll solve(ll n)
{
    if(!n) return 0;
    ll ret = 0;
    int k = 0;
    ll odd = 2, even = 1;
    while(1)
    {
        n -= 1LL<<k;
        if(k%2==0)
        {
            ret += (even + (1LL<<k) - 1) % mod * ((1LL<<k) % mod) % mod;
            even = even + (1LL<<(k+1)) % mod;
            even %= mod;
        }
        else
        {
            ret += (odd + (1LL<<k) - 1) % mod * ((1LL<<k) % mod) % mod;
            odd = odd + (1LL<<(k+1)) % mod;
            odd %= mod;
        }
        k++;
        if(n - (1LL<<k) <= 0)
        {
            if(k%2==0) ret += (even+n-1)%mod*(n%mod)%mod;
            else ret += (odd+n-1)%mod*(n%mod)%mod;
            break;
        }
    }
    ret %= mod;
    return ret;
}
int main()
{
    ll l,r;
    cin>>l>>r;
    ll ans = solve(r)-solve(l-1);
    ans %= mod;
    if(ans<0) ans+=mod;
    cout<<ans<<endl;
}