#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=405;
int mod;
int add(int x, int y){ x+=y;return x>=mod?x-mod:x;}
int sub(int x, int y){ x-=y;return x<0?x+mod:x;}
int mul(int x, int y){ return (ll)x*y%mod;}
int l[N],b[N][N],ans[N],F[N];
int main()
{
	int t;
	scanf("%i %i",&t,&mod);
	F[0]=1;
	for(int i=1;i<N;i++) F[i]=mul(F[i-1],i);
	b[0][0]=1;
	for(int i=1;i<N;i++)
		for(int j=1;j<N;j++)
			for(int k=1;k<=i;k++)
				b[i][j]=add(b[i][j],mul(b[i-k][j-1],F[k]));
	for(int i=1;i<N;i++)
	{
		l[i]=F[i];
		for(int j=1;j<i;j++)
			l[i]=sub(l[i],mul(l[i-j],F[j]));
	}
	for(int i=1;i<N;i++)
	{
		ans[i]=F[i];
		if(i>2)
			for(int j=1;j<i;j++)
				ans[i]=sub(ans[i],mul(2,mul(l[i-j],F[j])));
		for(int j=3;j<i;j++)
			ans[i]=sub(ans[i],mul(b[i][j],ans[j]));
	}
	while(t--)
	{
		int n;
		scanf("%i",&n);
		printf("%i\n",ans[n]);
	}
	return 0;
}