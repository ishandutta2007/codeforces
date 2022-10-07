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
const int N=200005;
int n;
int a[N];
int ans;
int main() {
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    ans=a[n]*2-a[n-1];
    for (int i=1;i<=n-2;i++)
        if (a[i]+a[i+2]!=a[i+1]*2)
            ans=a[n];
    cout<<ans<<endl;
	return 0;
}