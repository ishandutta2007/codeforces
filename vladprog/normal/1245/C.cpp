#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;
typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100,MOD=1e9+7;

int dp[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<N;i++)
        dp[i]=(dp[i-1]+dp[i-2])%MOD;

    string s;
    cin>>s;
    for(char c:s)
        if(c=='w'||c=='m')
            cout<<0,exit(0);
    vector<pair<char,int>> v;
    for(char c:s)
        if(v.empty()||v.back().first!=c)
            v.push_back({c,1});
        else
            v.back().second++;
    int ans=1;
    for(auto p:v)
        if(p.first=='n'||p.first=='u')
            ans=ans*dp[p.second]%MOD;
    cout<<ans;
}