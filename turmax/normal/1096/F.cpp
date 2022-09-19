#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
int po(int a,int b)
{
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2==0)
    {
        int u=po(a,b/2);
        return (u*u)%p;
    }
    else
    {
        int u=po(a,b-1);
        return (u*a)%p;
    }
}
int inv(int x) {return po(x,p-2);}
int slv(vector <int> v)
{
    int n=v.size();
    if(n<=1) return 0;
    vector <int> v1,v2;
    for(int i=0;i<n/2;++i) v1.push_back(v[i]);
    for(int i=n/2;i<n;++i) v2.push_back(v[i]);
    int ans=slv(v1)+slv(v2);
    sort(v2.begin(),v2.end());
    for(auto h:v1) ans+=(lower_bound(v2.begin(),v2.end(),h)-v2.begin());
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    set <int> o1;
    for(int i=0;i<n;++i) o1.insert(i);
    int c=0;
    int a[n];
    vector <int> v;
    for(int i=0;i<n;++i) {cin>>a[i];if(a[i]!=(-1)) {a[i]--;v.push_back(a[i]);o1.erase(a[i]);} else ++c;}
    vector <int> o;
    for(auto h:o1) o.push_back(h);
    int ans=slv(v);
    ans%=p;
    int c1=0;
    int h=inv(c);
    ans+=((c*(c-1))%p)*inv(4);
    ans%=p;
    for(int i=0;i<n;++i)
    {
        if(a[i]==(-1)) {++c1;}
        else
        {
            int x=a[i];
            int r=lower_bound(o.begin(),o.end(),x)-o.begin();
            ans+=(((c-c1)*r+c1*(o.size()-r))%p)*h;
            ans%=p;
        }
    }
    cout<<(ans%p+p)%p;
    return 0;
}