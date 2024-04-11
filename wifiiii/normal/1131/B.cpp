#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
const ll mod = 1e9+7;

int l[10005],r[10005];
int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;++i) cin>>l[i]>>r[i];
    int ans=0,L=0,R=0;
    for(int i=1;i<=n;++i)
    {
        int hi=min(l[i],r[i]),lo=max(R,L);
        ans += hi-lo+1>0?min(l[i],r[i])-max(R,L)+1:0;
        L=l[i],R=r[i];
        if(L==R) ans--;
    }
    if(L==R) ans++;
    cout << ans << endl;
}