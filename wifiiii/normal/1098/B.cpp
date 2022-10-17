#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forjj for(int j=1;j<=m;++j)
#define forij for(int i=1;i<=m;++i)


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<char>> g(n+1,vector<char>(m+1));
    vector<vector<char>> ans[50];
    forii forjj cin>>g[i][j];
    string s = "ACGT";
    int tot=0;
    do
    {
        ans[++tot].resize(n+1,vector<char>(m+1));
        forii
        {
            char a=s[0],b=s[1];
            if(i&1) a=s[2],b=s[3];
            int cnt1=0,cnt2=0;
            forjj
            {
                if(j&1)
                {
                    if(g[i][j]==a) cnt1++;
                    if(g[i][j]==b) cnt2++;
                }
                if(!(j&1))
                {
                    if(g[i][j]==b) cnt1++;
                    if(g[i][j]==a) cnt2++;
                }
            }
            if(cnt1<cnt2) swap(a,b);
            forjj if(j&1) ans[tot][i][j]=a;else ans[tot][i][j]=b;
        }
    }while(next_permutation(s.begin(), s.end()));
    s = "ACGT";
    do
    {
        ans[++tot].resize(n+1,vector<char>(m+1));
        for(int i=1;i<=m;++i)
        {
            char a=s[0],b=s[1];
            if(i&1) a=s[2],b=s[3];
            int cnt1=0,cnt2=0;
            for(int j=1;j<=n;++j)
            {
                if(j&1)
                {
                    if(g[j][i]==a) cnt1++;
                    if(g[j][i]==b) cnt2++;
                }
                if(!(j&1))
                {
                    if(g[j][i]==b) cnt1++;
                    if(g[j][i]==a) cnt2++;
                }
            }
            if(cnt1<cnt2) swap(a,b);
            for(int j=1;j<=n;++j) if(j&1) ans[tot][j][i]=a;else ans[tot][j][i]=b;
        }
    }while(next_permutation(s.begin(), s.end()));
    int mx=1e9,mi=1;
    for(int k=1;k<=tot;++k)
    {
        int cnt=0;
        forii forjj if(g[i][j]!=ans[k][i][j]) ++cnt;
        if(cnt<mx) mx=cnt,mi=k;
    }
    forii {
        forjj cout<<ans[mi][i][j];
        cout<<"\n";
    }
}