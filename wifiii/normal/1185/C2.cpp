
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forij for(int i=1;i<=m;++i)
#define forjj for(int j=1;j<=m;++j)

int cnt[105],ans[200005];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    int sum=0;
    forii
    {
        int t;
        cin>>t;
        sum+=t;
        if(sum<=m) {ans[i]=0;cnt[t]++;continue;}
        int tmp = sum;
        for(int j=100;j>=0;--j)
        {
            if(tmp - cnt[j] * j <= m)
            {
                ans[i] += (tmp - m + j - 1) / j;
                break;
            }
            tmp -= cnt[j] * j;
            ans[i] += cnt[j];
        }
        cnt[t]++;
    }
    forii cout<<ans[i]<<" ";
    cout<<endl;
}