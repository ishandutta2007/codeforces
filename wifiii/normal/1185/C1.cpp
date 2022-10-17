
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forij for(int i=1;i<=m;++i)
#define forjj for(int j=1;j<=m;++j)

int a[105],ans[105];
int main()
{
    int n,m;
    cin>>n>>m;
    int sum=0;
    forii cin>>a[i];
    forii
    {
        sum += a[i];
        sort(a+1,a+i);
        if(sum <= m) {ans[i]=0;continue;}
        int cur = sum, cnt = 0;
        for(int j=i-1;j>=0;--j)
        {
            cur -= a[j];
            cnt++;
            if(cur <= m) break;
        }
        ans[i]=cnt;
    }
    forii cout<<ans[i]<<" ";
    cout<<endl;
}