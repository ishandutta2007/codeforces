#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

const int N=2.5e5+100;

int a[N],dp[N];

int solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    vector<pair<int,int>> mx{{1,a[1]}},mn{{1,a[1]}};
    vector<pair<int,int>> up{{1,0}},down{{1,0}};
    dp[1]=0;
    for(int i=2;i<=n;i++)
    {
        int x=a[i];
        if(x<a[i-1])
        {
            while(!mn.empty()&&mn.back().second>x)
            {
                if(down.back().first==mn.back().first)
                    down.pop_back();
                mn.pop_back();
            }
            dp[i]=(mn.empty()?
                   up.front().second:
                   lower_bound(up.begin(),up.end(),pair{mn.back().first,0ll})->second)+1;
        }
        else
        {
            while(!mx.empty()&&mx.back().second<x)
            {
                if(up.back().first==mx.back().first)
                    up.pop_back();
                mx.pop_back();
            }
            dp[i]=(mx.empty()?
                   down.front().second:
                   lower_bound(down.begin(),down.end(),pair{mx.back().first,0ll})->second)+1;
        }
        int y=dp[i];
        mn.push_back({i,x});
        mx.push_back({i,x});
        while(!up.empty()&&up.back().second>y)
            up.pop_back();
        up.push_back({i,y});
        while(!down.empty()&&down.back().second>y)
            down.pop_back();
        down.push_back({i,y});
    }
    return dp[n];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
        cout<<(solve())<<"\n";
}