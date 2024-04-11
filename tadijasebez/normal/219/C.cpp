#include <stdio.h>
const int N=500050;
int k,n;
char s[N];
char Get(char a, char b)
{
	int i;
	for(i=0;i<k;i++) if('A'+i!=a && 'A'+i!=b) return 'A'+i;
	for(i=0;i<k;i++) if('A'+i!=a) return 'A'+i;
	return 0;
}
int cnt[2][2];
int main()
{
	int i,sol=0;
	scanf("%i %i",&n,&k);
	scanf("%s",s+1);
	if(k==2)
	{
		for(i=1;i<=n;i++) cnt[s[i]-'A'][i&1]++; 
		if(cnt[0][1]+cnt[1][0]<cnt[0][0]+cnt[1][1])
		{
			printf("%i\n",cnt[0][1]+cnt[1][0]);
			for(i=1;i<=n;i++) printf("%c",'A'+(i&1));
			printf("\n");
		}
		else
		{
			printf("%i\n",cnt[0][0]+cnt[1][1]);
			for(i=1;i<=n;i++) printf("%c",'A'+((i&1)^1));
			printf("\n");
		}
		return 0;
	}
	for(i=2;i<=n;i++) if(s[i]==s[i-1]) s[i]=Get(s[i-1],s[i+1]),sol++;
	printf("%i\n%s\n",sol,s+1);
	return 0;
}