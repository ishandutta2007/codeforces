#pragma GCC optimize("O3","Ofast","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=256;
const int u=10;
int nxt[maxn][maxn][maxn];
int symb[maxn][maxn][2];
int dp[maxn][1<<u];
int pos[maxn][maxn];
/*int has(vector <int> v)
{
    int ans=0;
    int mul=1;
    for(int i=0;i<v.size();++i)
    {
        ans+=(mul*v[i]);
        mul*=maxn;
    }
    return ans;
}*/
pair <int,int> pr[maxn][1<<u];
char t1[maxn][1<<u];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    vector <int> v3;
    for(auto h='a';h<='z';++h) v3.push_back(h);
    for(auto h='A';h<='Z';++h) v3.push_back(h);
    v3.push_back('$');
    v3.push_back('$');
    int t;
    cin>>t;
    while(t--)
    {
        for(int i=0;i<maxn;++i) for(int j=0;j<(1<<u);++j) pr[i][j]={-1,-1};
        for(int i=0;i<maxn;++i) for(int j=0;j<(1<<u);++j) dp[i][j]=0;
        for(int i=0;i<maxn;++i) for(int j=0;j<maxn;++j) for(int k=0;k<maxn;++k) nxt[i][j][k]=1e18;
        int n;
        cin>>n;
        string s[n];
        for(int i=0;i<n;++i) cin>>s[i];
        for(int i=0;i<n;++i)
        {
            s[i].insert(s[i].begin(),'$');
            int sz=s[i].size();
            for(int j=sz-1;j>=0;--j)
            {
                for(int k=0;k<maxn;++k)
                {
                    if(s[i][j]==k)
                    {
                        nxt[i][j][k]=j;
                    }
                    else
                    {
                        nxt[i][j][k]=nxt[i][j+1][k];
                    }
                }
            }
        }
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<maxn;++j)
            {
                for(int c=0;c<2;++c)
                {
                    int pos1=nxt[i][0][j];
                    if(c==0)
                    {
                        symb[i][j][c]=pos1;if(pos1!=(1e18)) pos[i][pos1]=0; continue;
                    }
                    if(pos1==1e18) {symb[i][j][c]=1e18;continue;}
                    pos1=nxt[i][pos1+1][j];if(pos1!=(1e18)) pos[i][pos1]=1;symb[i][j][c]=pos1;
                }
            }
        }
        vector <pair<int,pair<int,int> > > v;
        for(int i=0;i<maxn;++i)
        {
            for(int mask=0;mask<(1<<n);++mask)
            {
                if(mask & 1)
                {
                    v.push_back({symb[0][i][1],{i,mask}});
                }
                else
                {
                    v.push_back({symb[0][i][0],{i,mask}});
                }
            }
        }
        sort(v.begin(),v.end());
        for(auto h:v)
        {
            int ch=h.second.first;int mask=h.second.second;
            bool ok=true;
            for(int i=0;i<n;++i)
            {
                if(symb[i][ch][(bool) (mask & (1<<i))]==1e18) ok=false;
            }
            if(!ok) continue;
            for(auto j:v3)
            {
                if(!((j>='A' && j<='Z') || (j>='a' && j<='z'))) continue;
                int ch1=j;
                int mask1=0;
                bool ok=true;
                for(int i=0;i<n;++i)
                {
                    int pos2=nxt[i][symb[i][ch][(bool) (mask & (1<<i))]+1][ch1];
                    if(pos2==1e18) {ok=false;break;}
                    if(pos[i][pos2]==1) mask1+=(1<<i);
                }
                if(!ok) continue;
                int val=dp[ch][mask]+1;
                if(val>dp[ch1][mask1]) {dp[ch1][mask1]=val;
                t1[ch1][mask1]=ch1;
                pr[ch1][mask1]={ch,mask};}
           }
        }
        int ma=(-1);pair <int,int> u;
        for(int i=0;i<maxn;++i) for(int j=0;j<(1<<n);++j) {if(dp[i][j]>ma) {u={i,j};ma=dp[i][j];}}
        cout<<ma<<endl;
        string ans;
        while(pr[u.first][u.second]!=((pair<int,int>) {-1,-1}))
        {
            ans.push_back(t1[u.first][u.second]);u=pr[u.first][u.second];
        }
        reverse(ans.begin(),ans.end());
        cout<<ans<<endl;
    }
    return 0;
}