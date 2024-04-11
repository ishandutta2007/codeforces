#include<cstdio>
#include<cstring>

using namespace std;

char str[100100],target[100100];
int cnt[100100][26];
int N,M;
int tcnt[26];

int main()
{
	scanf("%s%s",str,target);
	N=strlen(str),M=strlen(target);
	if(N<M)
	{
		printf("0\n");
		return 0;
	}
	memset(cnt,0,sizeof(cnt));
	if(str[0]!='?')
	{
		cnt[0][str[0]-'a']=1;
	}
	for(int i=1;i<N;i++)
	{
		for(int j=0;j<26;j++)
		{
			cnt[i][j]=cnt[i-1][j];
		}
		if(str[i]!='?')
		{
			cnt[i][str[i]-'a']++;
		}
	}
	memset(tcnt,0,sizeof(tcnt));
	for(int i=0;i<M;i++)
	{
		tcnt[target[i]-'a']++;
	}
	int ans=0;
	bool flg=true;
	for(int i=0;i<26;i++)
	{
		if(tcnt[i]<cnt[M-1][i]) flg=false;
	}
	if(flg) ans++;
	for(int i=1;i+M<=N;i++)
	{
		//[i,i+1,...,i+M-1]
		bool flg=true;
		for(int j=0;j<26;j++)
		{
			int now=cnt[i+M-1][j]-cnt[i-1][j];
			if(now>tcnt[j]) flg=false;
		}
		if(flg) ans++;
	}
	printf("%d\n",ans);
	return 0;
}