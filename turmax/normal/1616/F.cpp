#ifndef LOCAL
#pragma GCC optimize("O3","unroll-loops","inline")
#pragma GCC target("avx","avx2","fma","abm","mmx")
#endif
#include <bits/stdc++.h>

using namespace std;
int t[3][3];
bool ok=true;
vector <int> slv(vector <vector <int> > v1,int m)
{
    /*for(auto h:v)
    {
        for(auto h1:h) cout<<h1<<' ';
        cout<<endl;
    }*/
    int n=v1.size();
    for(int i=0;i<n;++i) assert(v1[i].size()==(m+1));
    vector <int> ans(m);
    for(int i=0;i<m;++i) ans[i]=0;
    if(v1.empty()) return ans;
    int v[n][v1[0].size()+1];
    for(int i=0;i<n;++i) for(int j=0;j<=v1[0].size();++j) v[i][j]=v1[i][j];
    int cur=0;
    int curs[n];for(int i=0;i<n;++i) curs[i]=(-1);
    for(int i=0;i<n;++i)
    {
        for(int j=(i+1);j<n;++j)
        {
            if(cur==(m+1)) break;
            if(v[j][cur])
            {
                for(int k=cur;k<m+1;++k)
                {
                   swap(v[i][k],v[j][k]);
                }
                break;
            }
        }
        if(cur==(m+1)) break;
        if(!v[i][cur]) {if(cur==m) break;++cur;--i;continue;}
        curs[i]=cur;
        if(cur==(m+1)) break;
        if(cur==m)
        {
        ok=false;return ans;
        }
        for(int j=i+1;j<n;++j)
        {
            if(v[j][cur]!=0)
            {
                if(v[i][cur]==v[j][cur])
                {
                    for(int h=cur;h<m+1;++h) {v[j][h]-=v[i][h];if(v[j][h]<0) v[j][h]+=3;}
                }
                else
                {
                    for(int h=cur;h<m+1;++h) {v[j][h]+=v[i][h];if(v[j][h]>=3) v[j][h]-=3;}
                }
            }
        }
    }
    //cout<<curs[0]<<" curs[0] "<<endl;
    for(int i=(n-1);i>=0;--i)
    {
        if(curs[i]>=m+1 || curs[i]==(-1)) continue;
        int bal=(333+v[i][m])%3;
        vector <int> nz;
        int cur1=curs[i];
        for(int j=cur1+1;j<m;++j) {bal-=ans[j]*v[i][j];bal%=3;bal+=3;bal%=3;}
        bal%=3;bal+=3;bal%=3;
        //cout<<bal<<" bal "<<endl;
        if(v[i][cur1]==1) {ans[cur1]=bal;}
        else {ans[cur1]=((3-bal)%3+3)%3;}
    }
    //for(auto h:ans) cout<<h<<" h "<<endl;
    return ans;
}
bool f(int x,int y,vector <int> v)
{
    return (v[0]==x && v[1]==y);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    t[1][1]=1;t[1][2]=2;t[2][1]=2;t[2][2]=1;
    int t;
    cin>>t;
    while(t--)
    {
        ok=true;
        int n,m;
        cin>>n>>m;
        int a[n][n];for(int i=0;i<n;++i) for(int j=0;j<n;++j) a[i][j]=(-1);
        vector <int> b[m];
        for(int i=0;i<m;++i) {int x,y,w;cin>>x>>y>>w;if(x>y) swap(x,y);x--;y--;a[x][y]=i;a[y][x]=i;b[i]={x,y,w};}
        vector <vector <int> > d;
        int cyc=0;
        for(int i=0;i<n;++i) for(int j=(i+1);j<n;++j) for(int k=(j+1);k<n;++k)
        {
            ++cyc;
            vector <int> v;
            int o=0;
            int z=0;
            int l1=a[i][j];int l2=a[j][k];int l3=a[i][k];
            if(l1==(-1) || l2==(-1) || l3==(-1)) continue;
            for(int l=0;l<m;++l)
            {
                if(f(i,j,b[l]) || f(i,k,b[l]) || f(j,k,b[l]))
                {
                    ++o;
                    if(b[l][2]==(-1)) {v.push_back(1);continue;}
                    else z+=b[l][2];
                    v.push_back(0);
                    continue;
                }
                v.push_back(0);
            }
            if(o!=3) continue;
            v.push_back((333-z)%3);
            d.push_back(v);
        }
        vector <int> u=slv(d,m);
        if(!ok)
        {
            cout<<(-1)<<'\n';
            continue;
        }
        for(int i=0;i<m;++i)
        {
            if(b[i][2]!=(-1)) cout<<b[i][2]<<' ';
            else {int ans=u[i];ans%=3;ans+=3;ans%=3;if(ans==0) ans=3;cout<<ans<<' ';}
        }
        cout<<'\n';
        continue;
    }
    return 0;
}
/*
10
64 1
1 2 1
100 1
1 2 1
100 1
1 2 1
100 1
1 2 1
100 1
1 2 1
100 1
1 2 1
100 1
1 2 1
100 1
1 2 1
100 1
1 2 1
100 1
1 2 1
*/