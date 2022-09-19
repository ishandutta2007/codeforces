#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=3e5+5;
int p;
int val[maxn];
int a[maxn];
set <int> nz;
void pl(int pos,int val)
{
    if(a[pos]) nz.erase(pos);
    a[pos]+=val;a[pos]%=p;a[pos]+=p;a[pos]%=p;
    if(a[pos]) nz.insert(pos);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,q;
    cin>>n>>q>>p;
    int fib[n+1]={0};
    fib[0]=0;fib[1]=1;for(int i=2;i<=n+1;++i) {fib[i]=(fib[i-1]+fib[i-2])%p;}
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<n;++i) {int x;cin>>x;a[i]-=x;}
    for(int i=0;i<=n+1;++i) {val[i]=a[i];if(i>=1) val[i]-=a[i-1]; if(i>=2) val[i]-=a[i-2]; val[i]%=p;val[i]+=p;val[i]%=p;}
    for(int i=0;i<=n+1;++i) a[i]=val[i];
    for(int i=0;i<n;++i) if(val[i]) nz.insert(i);
    while(q--)
    {
        char typ;int l,r;
        cin>>typ>>l>>r;--l;
        int x=1;if(typ=='B') x=(-1);
        pl(l,x*1);
        pl(r,x*(-fib[r-l+1]));
        pl(r+1,x*(-fib[r-l]));
        puts(nz.empty() ? "YES" : "NO");
    }
    return 0;
}