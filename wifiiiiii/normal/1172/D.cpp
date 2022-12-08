
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
const int maxn = 1005;
struct P
{
    int a,b,c,d;
    P(int a,int b,int c,int d):a(a),b(b),c(c),d(d){}
};
vector<P> ans;
int a[maxn],b[maxn],ra[maxn],rb[maxn],c[maxn],rc[maxn],d[maxn],rd[maxn];
void swap2(int *a,int *ra,int i,int j)
{
    int t1=a[i],t2=a[j];
    swap(a[i],a[j]);
    swap(ra[t1],ra[t2]);
}
int main()
{
    int n;
    cin>>n;
    rep(i,n) cin>>b[i],rb[b[i]]=i;
    rep(i,n) cin>>a[i],ra[a[i]]=i;
    
    rep(i,n) c[i]=d[i]=rc[i]=rd[i]=i;
    rep(i,n)
    {
        if(c[i]==ra[i] && d[i]==rb[i]) continue;
        ans.push_back(P{i,rc[ra[i]],rd[rb[i]],i});
        int t1 = c[i];
        int t2 = d[i];
//        swap(c[i], c[rc[ra[i]]]);
//        swap(d[i], d[rd[rb[i]]]);
//        swap(rc[ra[i]], rc[t1]);
//        swap(rd[rb[i]], rd[t2]);
        swap2(c,rc,i,rc[ra[i]]);
        swap2(d,rd,i,rd[rb[i]]);
    }
    cout<<ans.size()<<endl;
    for(auto p:ans) cout<<p.a<<" "<<p.b<<" "<<p.c<<" "<<p.d<<endl;
}