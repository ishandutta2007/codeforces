#include <bits/stdc++.h>

using namespace std;
#define int long long
int cif[10][8];
int a[2000][8];
bool dp[2001][2001];
pair <int,pair<int,int> > pr[2001][2001];
int go(int x,int ci)
{
    int ans=0;
    for(int i=0;i<8;++i)
    {
        int u=a[x][i];
        int v=cif[ci][i];
        if(u==1 && v==0)
        {
            return 1e18;
        }
        if(u==0 && v==1)
        {
            ++ans;
        }
    }
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cif[0][0]=1;cif[0][1]=1;cif[0][2]=1;cif[0][4]=1;cif[0][5]=1;cif[0][6]=1;cif[1][2]=1;cif[1][5]=1;cif[2][0]=1;
    cif[2][2]=1;cif[2][3]=1;cif[2][4]=1;cif[2][6]=1;cif[3][0]=1;cif[3][2]=1;cif[3][3]=1;cif[3][5]=1;cif[3][6]=1;
    cif[4][1]=1;cif[4][3]=1;cif[4][2]=1;cif[4][5]=1;cif[5][0]=1;cif[5][1]=1;cif[5][3]=1;cif[5][5]=1;cif[5][6]=1;cif[7][0]=1;cif[7][2]=1;cif[7][5]=1;
    for(int i=0;i<8;++i)
    {
        cif[6][i]=1;
        cif[8][i]=1;
        cif[9][i]=1;
    }
    cif[9][4]=0;cif[6][2]=0;
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;++i)
    {
        string s;
        cin>>s;
        for(int j=0;j<8;++j)
        {
            a[i][j]=s[j]-'0';
        }
    }
    reverse(a,a+n);
    for(int i=0;i<=k;++i)
    {
        if(i==0)
        {
        dp[0][i]=true;
        pr[0][i]={-1,{-1,-1}};
        }
        else
        {
        dp[0][i]=false;
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int t=0;t<=k;++t)
        {
        dp[i][t]=false;
        for(int j=9;j>=0;--j)
        {
            int x=go(i-1,j);
            if(x==1e18 || x>t)
            {
                continue;
            }
            if(dp[i-1][t-x])
            {
                pr[i][t]={j,{i-1,t-x}};
                dp[i][t]=true;
                break;
            }
        }
        }
    }
    if(!dp[n][k])
    {
        cout<<(-1);
        return 0;
    }
    else
    {
        vector <int> v;
        pair <int,int> z=make_pair(n,k);
        while(true)
        {
            //cout<<z.first<<" "<<z.second<<endl;
            pair <int,pair <int,int> > h=pr[z.first][z.second];
            if(h.first==(-1))
            {
                break;
            }
            v.push_back(h.first);
            z=h.second;
        }
        bool h=false;
        for(int i=0;i<n;++i)
        {
            cout<<v[i];
        }
    }
    return 0;
}