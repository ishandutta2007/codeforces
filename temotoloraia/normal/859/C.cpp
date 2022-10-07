#include <bits/stdc++.h>
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define LL long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n;
int a[1000],s[1000];
int dp[1000];
int main() {
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    for (int i=n;i>0;i--){
        for (int j=i;j<=n;j++)
            dp[i]=max(dp[i],a[j]+s[n]-dp[j+1]-s[j]);
    }
    cout<<s[n]-dp[1]<<" "<<dp[1]<<endl;
	return 0;
}