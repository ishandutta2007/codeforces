#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define LL long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int N=100005;
LL n, A[N];
LL a[N], b[N];
LL x[N];
int main() {
    cin>>n;
    for (int i=1;i<=n;i++)
        scanf("%d",&A[i]);
    for (int i=1;i<=n;i++)
        a[i]=max(A[i],a[i-1]+1);
    for (int i=n;i>=1;i--)
        b[i]=max(A[i],b[i+1]+1);
    for (int i=1;i<=n;i++){
        x[i]=max(a[i],b[i])-A[i];
        a[i]-=A[i];
        b[i]-=A[i];
    }
    for (int i=1;i<=n;i++)
        a[i]+=a[i-1];
    for (int i=n;i>=1;i--)
        b[i]+=b[i+1];
    LL ans=min(a[n],b[1]);
    for (int i=2;i<n;i++)
        ans=min(ans,a[i-1]+x[i]+b[i+1]);
    cout<<ans<<endl;
	return 0;
}