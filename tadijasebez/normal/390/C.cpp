#include <stdio.h>
const int N=100050;
int cnt[2][10][N];
char s[N];
int main()
{
	int n,i,k,j,q;
	scanf("%i %i %i",&n,&k,&q);
	scanf("%s",s+1);
	for(i=1;i<=n;i++)
	{
		for(j=0;j<k;j++) cnt[0][j][i]=cnt[0][j][i-1],cnt[1][j][i]=cnt[1][j][i-1];
		cnt[s[i]-'0'][i%k][i]++;
	}
	int l,r;
	while(q--)
	{
		scanf("%i %i",&l,&r);
		int sol=0;
		for(i=0;i<k-1;i++) sol+=cnt[1][(l+i)%k][r]-cnt[1][(l+i)%k][l-1];
		sol+=cnt[0][(l+k-1)%k][r]-cnt[0][(l+k-1)%k][l-1];
		printf("%i\n",sol);
	}
	return 0;
}