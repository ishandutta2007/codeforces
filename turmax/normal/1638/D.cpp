#pragma GCC optimize("O3","Ofast","unroll-loops")
#pragma GCC target("avx","avx2")
#include <bits/stdc++.h>

using namespace std;
const int maxn=1e3+5;
int a[maxn][maxn];
int c;
bool ok(int x,int y)
{
    set <int> col;
    col.insert(a[x][y]);col.insert(a[x+1][y]);col.insert(a[x][y+1]);col.insert(a[x+1][y+1]);
    if(col.count(-1)) col.erase(-1);
    if(col.size()==1) c=(*col.begin());
    return col.size()==1;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i) for(int j=0;j<m;++j) cin>>a[i][j];
    vector <vector <int> > v;
    stack <pair<int,int> > d;
    for(int i=0;i<n;++i) for(int j=0;j<m;++j) d.push({i,j});
    while(!d.empty())
    {
        pair <int,int> o=d.top();
        int i=o.first;int j=o.second;
        d.pop();
        if(i<0 || j<0 || i>=n-1 || j>=m-1) continue;
            if(ok(i,j))
            {
                v.push_back({c,i,j});
                a[i][j]=(-1);a[i+1][j]=(-1);a[i][j+1]=(-1);a[i+1][j+1]=(-1);
                for(int k=(-1);k<2;++k) for(int l=(-1);l<2;++l) d.push({i+k,j+l});
            }
    }
    for(int i=0;i<n;++i) for(int j=0;j<m;++j) {if(a[i][j]!=(-1)) {cout<<(-1);return 0;}}
    reverse(v.begin(),v.end());
    cout<<v.size()<<endl;
    for(auto h:v)
    {
        cout<<h[1]+1<<' '<<h[2]+1<<' '<<h[0]<<'\n';
    }
    return 0;
}