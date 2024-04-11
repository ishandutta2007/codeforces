#include<cstdio>
#include<algorithm>
#include<cstring>
#include<bitset>
using namespace std;
int n,k,sg[200005],prime[100005],num;
bitset<200005>f[105],t;
bool flag[200005];
void pre()
{
	flag[1]=0;
	for(int i=2;i<=200000;i++)
	{
		if(!flag[i])
		{
			prime[++num]=i;
			t[i]=1;
		}
		for(int j=1;j<=num&&prime[j]*i<=200000;j++)
		{
			flag[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
	for(int i=1;i<=num;i++)
	  for(int j=1;prime[j]*prime[i]<=200000;j++)
	    t[prime[i]*prime[j]]=1;
}
int main()
{
	pre();
	scanf("%d%d",&n,&k);
	t[k]=0;
	for(int i=0;i<=200000;i++)
	{
		while(f[sg[i]][i])sg[i]++;
		f[sg[i]]|=t<<i;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		ans^=sg[b-a-1]^sg[c-b-1];
	}
	if(ans)printf("Alice\nBob\n");
	else printf("Bob\nAlice\n");
	return 0;
}