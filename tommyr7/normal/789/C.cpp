#include <bits/stdc++.h>
using namespace std;
int n;
long long b[100007],a[100007];
long long f[100007];
int main()
{
    cin>>n;
    long long ans=0;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<n;i++) b[i]=abs(a[i]-a[i+1]);
    for (int i=1;i<n;i++) if (i%2==0) b[i]=-b[i];
    memset(f,0,sizeof(f));
    for (int i=1;i<n;i++) f[i]=max(f[i-1]+b[i],(long long)0);
    for (int i=1;i<n;i++) ans=max(ans,f[i]);
    memset(f,0,sizeof(f));
    for (int i=1;i<n;i++) f[i]=min(f[i-1]+b[i],(long long)0);
    for (int i=1;i<n;i++) ans=max(ans,abs(f[i]));
    cout << ans << endl;
    return 0;
}