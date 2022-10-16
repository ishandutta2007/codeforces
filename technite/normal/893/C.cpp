#include<bits/stdc++.h>
using namespace std;
vector<long long> c(1e5+5);
vector<long long> link(1e5+5),sz(1e5+5),mn(1e5+5);
long long sum=0;
int find(int x) {
if (x == link[x]) return x;
return link[x] = find(link[x]);
}
void unite(int a, int b) 
{
    a = find(a);
    b = find(b);
    if(a==b) return;
    if (sz[a] < sz[b]) swap(a,b);
    sz[a] += sz[b];
    link[b] = a;
    if(mn[a]>mn[b])
    {
        sum-=mn[a];
        mn[a]=mn[b];
    }
    else
    {
        sum-=mn[b];
        mn[b]=mn[a];
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    
    for (int i = 1; i <= n; i++) link[i] = i;
    for (int i = 1; i <= n; i++) sz[i] = 1;
        for(int i=1;i<=n;i++)
        {
            cin>>c[i];
            sum+=c[i];
        }
         for(int i=1;i<=n;i++) mn[i]=c[i];
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            unite(a,b);
        }
        cout<<sum<<'\n';
}