#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=510;

int a[N],dp[N][N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int len=1;len<=n;len++)
        for(int l=1;l+len-1<=n;l++)
        {
            int r=l+len-1;
            dp[l][r]=1e9;
            vector<int> v;
            for(int i=l;i<=r;i++)
            {
                v.push_back(a[i]);
                while(v.size()>=2&&v[v.size()-1]==v[v.size()-2])
                    v.pop_back(),
                    v.back()++;
                if(v.size()==1)
                    dp[l][r]=min(dp[l][r],dp[i+1][r]+1);
            }
        }
    cout<<dp[1][n];
}