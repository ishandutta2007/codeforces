#include <bits/stdc++.h>
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int N=1000005;
int n,a[N];
int s1[N],s2[N];
int ans;
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++)
        s1[i]=s1[i-1]+a[i];
    for (int i=n;i>0;i--)
        s2[i]=s2[i+1]+a[i];
    for (int i=0;i<=n;i++)
        ans=max(ans,i-s1[i]+s2[i+1]);
    cout<<ans<<endl;
    return 0;
}