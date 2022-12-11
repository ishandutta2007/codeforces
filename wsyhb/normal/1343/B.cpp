#include<bits/stdc++.h>
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
const int N=2e5+5;
int ans[N];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		n>>=1;
		if(n&1) printf("NO\n");
		else
		{
			printf("YES\n");
			for(int i=1;i<=n;i++) ans[i]=i<<1,ans[i+n]=(i<<1)-1;
			ans[n<<1]+=n;
			n<<=1;
			for(int i=1;i<=n;i++) printf("%d%c",ans[i],i<n?' ':'\n');
		}
	}
	return 0;
}