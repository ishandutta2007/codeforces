#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e9+7;
int inv2=(p+1)/2;
const int maxn=(1<<20);
int a[maxn];int b[maxn];int res[maxn];
int po[maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    po[0]=1;for(int i=1;i<maxn;++i) {po[i]=(po[i-1]*2)%p;}
    int n;cin>>n;
    string s;cin>>s;for(int i=0;i<(1<<n);++i) {a[i]=s[i]-'1';b[i]=a[i];}
    for(int j=0;j<n;++j) for(int i=0;i<(1<<n);++i) if(!(i & (1<<j))) {int x=a[i];int y=a[i+(1<<j)];a[i]=(x+y);a[i+(1<<j)]=(x-y);if(a[i]>=p) a[i]-=p;if(a[i+(1<<j)]<0) a[i+(1<<j)]+=p;}
    for(int j=0;j<n;++j) for(int i=0;i<(1<<n);++i) if(!(i & (1<<j))) {int x=b[i];int y=b[i+(1<<j)];b[i]=(x+y);b[i+(1<<j)]=(x-y);if(b[i]>=p) b[i]-=p;if(b[i+(1<<j)]<0) b[i+(1<<j)]+=p;}
    for(int i=0;i<(1<<n);++i) res[i]=(a[i]*1LL*b[i])%p;
    for(int j=0;j<n;++j) for(int i=0;i<(1<<n);++i) if(!(i & (1<<j))) {int x=res[i];int y=res[i+(1<<j)];res[i]=((x+y)*1LL*inv2)%p;res[i+(1<<j)]=((x-y+p)*1LL*inv2)%p;}
    int answ=0;
    for(int i=0;i<(1<<n);++i)
    {
        int cnt=__builtin_popcount(i);
        answ+=(res[i]*po[n-cnt]);
        answ%=p;
    }
    cout<<((3*answ)%p+p)%p;
    return 0;
}