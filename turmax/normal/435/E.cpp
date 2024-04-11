#include <bits/stdc++.h>

using namespace std;
#define int long long
#define vvi vector <vector <int> >
pair <bool,vvi> slv1(vvi a,int x,int y,int z,int t)
{
    int n=a[0].size();
    for(int i=0;i<2;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(j%2==0)
            {
                if(a[i][j]!=0 && a[i][j]!=x && a[i][j]!=y) return {false,{}};
                if(a[i][j]==0) {if(a[i^1][j]!=0) a[i][j]=x+y-a[i^1][j]; else {a[i^1][j]=x;a[i][j]=y;}}
            }
            else
            {
                if(a[i][j]!=0 && a[i][j]!=z && a[i][j]!=t) return {false,{}};
                if(a[i][j]==0) {if(a[i^1][j]!=0) a[i][j]=z+t-a[i^1][j]; else {a[i^1][j]=z;a[i][j]=t;}}
            }
        }
    }
    for(int i=0;i<2;++i) for(int j=0;j<n;++j) if(a[i][j]==a[i^1][j]) return {false,{}};
    return {true,a};
}
pair<bool,vvi> slv(vvi a)
{
    int n=a[0].size();
    //cout<<n<<" n "<<endl;
    //for(int i=0;i<2;++i) {for(int j=0;j<n;++j) cout<<a[i][j]<<' '; cout<<endl;}
    //cout<<endl;
    if(n==0) return {true,a};
    pair <bool,vvi> o;
    o=slv1(a,1,2,3,4);if(o.first) return o;
    o=slv1(a,1,3,2,4);if(o.first) return o;
    o=slv1(a,1,4,2,3);if(o.first) return o;
    o=slv1(a,2,3,1,4);if(o.first) return o;
    o=slv1(a,2,4,1,3);if(o.first) return o;
    o=slv1(a,3,4,1,2);if(o.first) return o;
    return {false,{}};
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    string s[n];
    for(int i=0;i<n;++i) cin>>s[i];
    int ans[n][m];
    int d[n][2];for(int i=0;i<n;++i) {d[i][0]=0;d[i][1]=0;}
    int u[2][m];for(int i=0;i<m;++i) {u[0][i]=0;u[1][i]=0;}
    bool ok1=true,ok2=true;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            int o=s[i][j]-'0';
            if(o)
            {
                if(d[i][j%2] && d[i][j%2]!=o) ok1=false;
                d[i][j%2]=o;
                if(u[i%2][j] && u[i%2][j]!=o) ok2=false;
                u[i%2][j]=o;
            }
        }
    }
    vector <vector <int> > a1(2);vector <vector<int> > a2(2);
    a1[0].resize(m);a1[1].resize(m);a2[0].resize(n);a2[1].resize(n);
    for(int i=0;i<2;++i) for(int j=0;j<m;++j) a1[i][j]=u[i][j];
    for(int i=0;i<2;++i) for(int j=0;j<n;++j) a2[i][j]=d[j][i];
    if(ok2)
    {
        pair <bool,vector <vector<int> > > z=slv(a1);
        if(z.first)
        {
            //cout<<" ok2 "<<endl;
            vector <vector <int> > o=z.second;
            for(int i=0;i<n;++i) for(int j=0;j<m;++j) ans[i][j]=o[i%2][j];
            for(int i=0;i<n;++i) {for(int j=0;j<m;++j) cout<<ans[i][j]; cout<<endl;}
            return 0;
        }
    }
    //cout<<" tger "<<endl;
    if(ok1)
    {
        //cout<<" rtgjg "<<endl;
        pair <bool,vector <vector<int> > > z=slv(a2);
        if(z.first)
        {
            //cout<<" ok1 "<<endl;
            //for(int i=0;i<2;++i) {for(int j=0;j<m;++j) cout<<a2[i][j]<<' '; cout<<endl;}
            //cout<<" a2 "<<endl;
            vector <vector <int> > o=z.second;
            for(int i=0;i<n;++i) for(int j=0;j<m;++j) ans[i][j]=o[j%2][i];//???
            for(int i=0;i<n;++i) {for(int j=0;j<m;++j) cout<<ans[i][j]; cout<<endl;}
            return 0;
        }
    }
    cout<<0;
    return 0;
}