#include <stdio.h>
#include <map>
using namespace std;
const int N=1505;
#define mp make_pair
int dp[N][26],a[N];
int Get(int l, int r, int j){ return dp[r][j]-dp[l-1][j];}
map<pair<int,int> ,int> sol;
int main()
{
	int n,q,i,j,u,v,x,t;char c;
	scanf("%i\n",&n);
	for(i=1;i<=n;i++) scanf("%c",&a[i]),a[i]-='a';
	for(i=1;i<=n;i++)
	{
		for(j=0;j<26;j++) dp[i][j]=dp[i-1][j];
		dp[i][a[i]]++;
	}
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i %c",&x,&c);t=c-'a';
		if(sol[mp(x,t)]) printf("%i\n",sol[mp(x,t)]);
		else
		{
			int top=n,bot=1,mid;
			while(top>=bot)
			{
				mid=top+bot>>1;
				bool ok=0;
				for(i=1;i<=n-mid+1;i++) if(mid-Get(i,i+mid-1,t)<=x) ok=1;
				if(ok) sol[mp(x,t)]=mid,bot=mid+1;
				else top=mid-1;
			}
			printf("%i\n",sol[mp(x,t)]);
		}
	}
	return 0;
}