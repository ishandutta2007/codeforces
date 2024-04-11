#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
const int maxn=1e5+5;
#define vi vector <int>
bool operator <(vi a,vi b)
{
    bool ok=true;for(int i=0;i<a.size();++i) ok=(ok && a[i]<b[i]);
    return ok;
}
bool operator >(vi a,vi b)
{
    bool ok=true;for(int i=0;i<a.size();++i) ok=(ok && a[i]>b[i]);
    return ok;
}
vi mi(vi a,vi b)
{
    for(int i=0;i<a.size();++i) a[i]=min(a[i],b[i]);
    return a;
}
vi ma(vi a,vi b)
{
    for(int i=0;i<a.size();++i) a[i]=max(a[i],b[i]);
    return a;
}
tuple<int,vi,vi> z[maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    vi a[n];
    for(int i=0;i<n;++i) {a[i].resize(k);for(auto &h:a[i]) cin>>h;}
    rope <int> u;
    for(int i=0;i<n;++i)
    {
        vi cur=a[i];
        int low1=(-1);int up1=u.size();
        while(up1-low1>1)
        {
            int mid1=(low1+up1)/2;
            vi z1=get<1>(z[u[mid1]]);
            if(z1<cur) up1=mid1;
            else low1=mid1;
        }
        int low2=(-1);int up2=u.size();
        while(up2-low2>1)
        {
            int mid2=(low2+up2)/2;
            vi z2=get<2>(z[u[mid2]]);
            if(z2>cur) low2=mid2;
            else up2=mid2;
        }
        //cout<<low2<<' '<<up1<<endl;
        int sum=1;vi u1=cur;vi u2=cur;
        for(int i=low2+1;i<up1;++i)
        {
            //cout<<z[i]<<" z[i] "<<endl;
            int x=get<0>(z[u[i]]);
            vi z1=get<1>(z[u[i]]);
            vi z2=get<2>(z[u[i]]);
            sum+=x;
            u1=ma(u1,z1);u2=mi(u2,z2);
        }
        //cout<<sum<<" sum "<<endl;
        if(low2+1!=up1) u.erase(low2+1,up1-low2-1);
        z[i]=make_tuple(sum,u1,u2);
        u.insert(low2+1,i);
        auto [x,z1,z2]=z[u[0]];
        cout<<x<<'\n';
    }
    return 0;
}