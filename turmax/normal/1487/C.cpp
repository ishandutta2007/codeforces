#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <vector <int> > a;
vector <int> ptr;
vector <int> f;
vector <vector <bool> > use;
void dfs(int x)
{
    for(int i=ptr[x];i<a[x].size();++i)
    {
        ptr[x]++;
        int v=a[x][i];
        if(use[x][v]) continue;
        use[x][v]=true;use[v][x]=true;
        dfs(v);
    }
    f.push_back(x);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        a.clear();
        vector <vector <int> > b(n);
        ptr.resize(n);
        use.resize(n);
        f.clear();
        a.resize(n);
        use.clear();
        for(int i=0;i<n;++i) {b[i].resize(n);ptr[i]=0;}
        for(int i=0;i<n;++i) for(int j=0;j<n;++j) {use[i].push_back(false);if(i!=j) a[i].push_back(j);}
        if(n%2==0)
        {
            for(int i=0;i<n;i+=2)
            {
                b[i][i+1]=0;
                b[i+1][i]=0;
                a[i].erase(a[i].begin()+i);
                a[i+1].erase(a[i+1].begin()+i);
            }
        }
        dfs(0);
        //for(auto h:f) cout<<h<<' ';
        //cout<<endl;
        for(int i=0;i<f.size()-1;++i) {b[f[i]][f[(i+1)%f.size()]]=1;b[f[(i+1)%f.size()]][f[i]]=(-1);}
        for(int i=0;i<n;++i)
        {
            for(int j=(i+1);j<n;++j)
            {
                cout<<b[i][j]<<' ';
            }
        }
        cout<<'\n';
    }
    return 0;
}