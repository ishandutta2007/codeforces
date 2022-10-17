#include<iostream>
#include<cstring>
#include<stdio.h>
#include<math.h>
#include<iomanip>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
#define pb push_back
#define clr(i) memset(i,0,sizeof(i))
#define scsz(s,a,b) for(int i=a,j=1;i<=b;++i){cout<<s[i];if(j++%10)cout<<"\n";else cout<<" ";}cout<<endl;
typedef long long ll;

int main()
{
    cout << fixed;
    ll l,r,ans;
    cin>>l>>r;
    if(l==r) {cout<<0<<endl;return 0;}
    for(ll i=60;i>=0;--i)
    {
        ll m = 0;
        for(ll j=0;j<=i;++j) m |= (1LL<<j);
        ll Max = max((r&m), (l&m)), Min = min((r&m), (l&m));
        if( (1LL<<i) <= Max && ((1LL<<i)-1) >= Min) {ans = (1LL<<(i+1))-1;break;}
    }
    cout << ans << endl;
}