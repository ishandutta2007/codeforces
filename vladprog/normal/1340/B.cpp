#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2010;
const int d[10]={238,72,186,218,92,214,246,74,254,222};

#define cnt __builtin_popcount

int a[N];
int dp[N][N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        s="_"+s;
        for(int j=1;j<=7;j++)
            if(s[j]=='1')
                a[i]|=1<<j;
    }
    dp[n+1][0]=true;
    for(int i=n;i>=1;i--)
        for(int j=0;j<=k;j++)
            for(int t=0;t<10;t++)
                if((a[i]&d[t])==a[i]&&
                   cnt(d[t])-cnt(a[i])<=j)
                    dp[i][j]|=dp[i+1][j-(cnt(d[t])-cnt(a[i]))];
    if(!dp[1][k])
        cout<<-1,exit(0);
//    cout<<(a[1]&d[9])<<" "<<a[1]<<"\n";
//    cout<<cnt(d[9])-cnt(a[1])<<" "<<k<<"\n";
    for(int i=1;i<=n;i++)
        for(int t=9;t>=0;t--)
            if((a[i]&d[t])==a[i]&&
               cnt(d[t])-cnt(a[i])<=k&&
               dp[i+1][k-(cnt(d[t])-cnt(a[i]))])
            {
                cout<<t;
                k-=cnt(d[t])-cnt(a[i]);
                break;
            }
}