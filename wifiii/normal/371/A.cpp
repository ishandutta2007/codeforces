#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forij for(int i=1;i<=m;++i)
#define forjj for(int j=1;j<=m;++j)

int a[105];
int main()
{
    int n,k;
    cin>>n>>k;
    forii cin>>a[i];
    int ans=0;
    for(int i=1;i<=k;++i)
    {
        int c0=0,c1=0;
        for(int j=i;j<=n;j+=k)
        {
            if(a[j]==1) c0++;
            else c1++;
        }
        ans+=min(c0,c1);
    }
    cout<<ans<<endl;
}