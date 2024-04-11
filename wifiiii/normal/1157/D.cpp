
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
#include <assert.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5+5;
ll ans[maxn];
int main()
{
    ll n,k;
    cin>>n>>k;
    if(n < k*(k+1)/2) {cout<<"NO"<<endl;return 0;}
    ll lo = 1, hi = n;
    while(lo < hi)
    {
        ll m = (lo+hi+1)/2;
        if(n-(2*m+k-2)*(k-1)/2 > lo+k-2) lo=m;
        else hi=m-1;
    }
    ll l = n;
    for(int i=1;i<k;++i) ans[i]=lo+i-1,l-=lo+i-1;ans[k]=l;
    while(ans[k]<ans[k-1])
    {
        lo--;
        l = n;
        for(int i=1;i<k;++i) ans[i]=lo+i-1,l-=lo+i-1;ans[k]=l;
    }
    if(ans[k]==ans[k-1])
    {
        ans[1]--,ans[2]--,ans[k]++,ans[k]++;
    }
    for(int i=2;i<=k;++i)
    {
        if(ans[i] <= ans[i-1] || ans[i] > ans[i-1] * 2)
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    for(int i=1;i<=k;++i) cout<<ans[i]<<" ";
    cout<<endl;
}