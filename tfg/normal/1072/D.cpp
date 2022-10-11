/*huzaifa242 copyright*/
#include <bits/stdc++.h>
using namespace std;
#define MAX 2003
#define x first
#define y second
string s[MAX],ans="";
int dp[MAX][MAX],n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int k,i,j,dist=-1;
    cin>>n>>k;
    memset(dp,0,sizeof(dp));
    vector<pair<int, int> >v;
    for(i=0;i<n;i++)
    cin>>s[i];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==0 && j==0)
            {
                dp[i][j]=0;
            }
            else if(i==0)
            {
                dp[i][j]=dp[i][j-1];
            }
            else if(j==0)
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                dp[i][j]=min(dp[i-1][j],dp[i][j-1]);
            }
            dp[i][j]+=(s[i][j]=='a'?0:1);
            if(dp[i][j]<=k)
            {
                dist=max(dist,i+j+1);
            }
            //cout<<dp[i][j]<<" ";
        }
        //cout<<"\n";
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i+j+1==dist && dp[i][j]<=k)
            v.push_back({i,j});
        }
    }
    /*cout<<dist<<endl;
    for(i=0;i<v.size();i++)
    cout<<v[i].x<<" "<<v[i].y<<endl;*/        
    for(i=0;i<dist;i++)
    {
        ans+='a';
    }
    if(dist==-1)
    {
        ans+=s[0][0];
        v.push_back({0,0});
    }
    while(ans.length()<2*n-1)
    {
        char cc='z';
        for(auto vv:v)
        {
            int p=vv.x,q=vv.y;
            if(p+1<n)
            {
                cc=min(s[p+1][q],cc);
            }
            if(q+1<n)
            {
                cc=min(s[p][q+1],cc);
            }
        }
        /*for(i=0;i<v.size();i++)
        cout<<v[i].x<<" * "<<v[i].y<<endl;*/
        ans+=cc;
        vector<pair<int,int> > t;
        for(auto vv:v)
        {
            int p=vv.x,q=vv.y;
            if(p+1<n && s[p+1][q]==cc)
            {
                t.push_back({p+1,q});
            }
            if(q+1<n && s[p][q+1]==cc)
            {
                t.push_back({p,q+1});
            }
        }
        sort(t.begin(), t.end());
        t.resize(unique(t.begin(), t.end()) - t.begin());
        swap(v,t);
    }
    cout<<ans<<"\n";
    return 0;
}