
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
typedef long long ll;
int a[105];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        memset(a,0,sizeof(a));
        int n;
        cin>>n;
        rep(i,n)
        {
            int tmp;
            cin>>tmp;
            a[tmp%3]++;
        }
        //cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
        int ans = a[0];
        int m = min(a[1],a[2]);
        ans += m, a[1] -= m, a[2] -= m;
        ans += a[1] / 3;
        ans += a[2] / 3;
        cout<<ans<<endl;
    }
}