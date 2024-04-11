#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
//#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=3010,K=2*N;

int l[N],r[N];
vector<int> lef[K],rig[K];
int dp[K][K];

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
        cin>>n;
        map<int,int> m;
        for(int i=1;i<=n;i++)
            cin>>l[i]>>r[i],
            m[l[i]],m[r[i]];
        int k=0;
        for(auto&p:m)
            p.y=++k;
        for(int i=1;i<=n;i++)
            l[i]=m[l[i]],
            r[i]=m[r[i]];
        for(int i=1;i<=k;i++)
            lef[i].clear(),
            rig[i].clear();
        for(int i=1;i<=n;i++)
            rig[l[i]].push_back(r[i]),
            lef[r[i]].push_back(l[i]);
        for(int i=1;i<=k;i++)
            sort(lef[i].begin(),lef[i].end(),greater<>()),
            sort(rig[i].begin(),rig[i].end());
        for(int i=1;i<=k;i++)
            dp[i][i]=!rig[i].empty()&&*rig[i].begin()==i;
//            cout<<"dp["<<i<<"]["<<i<<"]="<<dp[i][i]<<"\n";
        for(int len=1;len<=k;len++)
            for(int from=1;from+len<=k;from++)
            {
                int to=from+len;
                dp[from][to]=max(dp[from][to-1],dp[from+1][to]);
                bool add=false;
                if(rig[from].size()<lef[to].size())
                {
                    for(int mid:rig[from])
                        if(mid<to)
                            dp[from][to]=max(dp[from][to],dp[from][mid]+dp[mid+1][to]);
                        else if(mid==to)
                            add=1;
                        else
                            break;
                }
                else
                {
                    for(int mid:lef[to])
                        if(mid>from)
                            dp[from][to]=max(dp[from][to],dp[from][mid-1]+dp[mid][to]);
                        else if(mid==from)
                            add=1;
                        else
                            break;
                }
                dp[from][to]+=add;
//                cout<<"dp["<<from<<"]["<<to<<"]="<<dp[from][to]<<"\n";
            }
        cout<<dp[1][k]<<"\n";
    }
}