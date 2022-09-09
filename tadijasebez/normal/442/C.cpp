#include <stdio.h>
#include <algorithm>
using namespace std;
#define ll long long
const int N=500050;
int min(int a, int b){ return a>b?b:a;}
int S[N],c;
ll ans;
int main()
{
	int n,i,x;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&x);
		while(c>1 && S[c]<=min(S[c-1],x))
		{
			ans+=min(S[c-1],x);
			c--;
		}
		S[++c]=x;
	}
	sort(S+1,S+1+c);
	for(i=1;i<=c-2;i++) ans+=S[i];
	printf("%lld\n",ans);
	return 0;
}