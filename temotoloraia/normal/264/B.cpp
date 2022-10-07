#include <iostream>
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
int n,a[100005],mas[100005],dp[100005],ans;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		dp[i]=1;
		for (int j=1;j*j<=a[i];j++)
			if (a[i]%j==0){
   			   if (mas[j] && j>1)dp[i]=max(dp[i],dp[mas[j]]+1);
   			   if (mas[a[i]/j])dp[i]=max(dp[i],dp[mas[a[i]/j]]+1);
  			}
		for (int j=1;j*j<=a[i];j++)
		if (a[i]%j==0)
		mas[j]=i,mas[a[i]/j]=i;
		ans=max(ans,dp[i]);
	}
	cout<<ans<<endl;
    return 0;
}