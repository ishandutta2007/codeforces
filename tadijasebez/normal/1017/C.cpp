#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long int
#define pb push_back
#define mp make_pair
int min(int a, int b){ return a>b?b:a;}
int max(int a, int b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
ll max(ll a, ll b){ return a>b?a:b;}
const int N=100050;
int a[N];
int main()
{
	int n,i;
	scanf("%i",&n);
	if(n==1) return printf("1 "),0;
	if(n==2) return printf("1 2 "),0;
	int k=1,sol=n+1;
	for(i=2;i<=n;i++)
	{
		int ans=i+(n+i-1)/i;
		if(ans<sol) sol=ans,k=i;
	}
	for(i=1;i<=n;i++) a[i]=n-i+1;
	for(i=1;i<=n;i+=k)
	{
		int l=i,r=i+k;
		if(r>n+1) r=n+1;
		reverse(a+l,a+r);
	}
	for(i=1;i<=n;i++) printf("%i ",a[i]);
	/*for(i=n;i>=1;i--)
	{
		if(n&1)
		{
			if(i==1) printf("1 ");
			else if(i&1) printf("%i ",i-1);
			else printf("%i ",i+1);
		}
		else
		{
			if(i&1) printf("%i ",i+1);
			else printf("%i ",i-1);
		}
	}*/
	//int st=(n+1)/2;
	//vector<int> sol;
	//sol.pb(st);
	//for(i=1;i<=n;i++)
	//{
	//	sol.pb(st+i);
	//	sol.pb(st-i);
	//}
	//for(i=0;i<n;i++) printf("%i ",sol[i]);
	return 0;
}