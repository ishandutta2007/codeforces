#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100,K=20,A=26;

int p[N][A];
int dp[N][2][A];

int cost(int l,int r,int c)
{
    return (r-l+1)-(p[r][c]-p[l-1][c]);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        string s;
        cin>>n>>s;
        s="_"+s;
        for(int i=1;i<=n;i++)
        {
            for(int c=0;c<A;c++)
                p[i][c]=p[i-1][c];
            p[i][s[i]-'a']++;
        }
        int k=0;
        while((1<<k)<n)
            k++;
        for(int j=0;j<=k;j++)
            for(int i=1;i+(1<<j)-1<=n;i++)
                for(int c=0;c<A;c++)
                    if(j==0)
                        dp[i][j%2][c]=s[i]!='a'+c;
                    else
                        dp[i][j%2][c]=min(cost(i,i+(1<<(j-1))-1,c)+dp[i+(1<<(j-1))][1-j%2][c+1],
                                          cost(i+(1<<(j-1)),i+(1<<j)-1,c)+dp[i][1-j%2][c+1]);
        cout<<dp[1][k%2][0]<<"\n";
    }
}