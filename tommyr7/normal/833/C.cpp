#include <bits/stdc++.h>
#define Maxn 19
using namespace std;
long long L,R;
int cnt=0,ans=0;
int leftnum[Maxn],rightnum[Maxn];
int s[10],now[Maxn],cur[Maxn];
int check()
{
	int pos=Maxn-1;
	while (leftnum[pos]==rightnum[pos])
	{
		int k=leftnum[pos];
		--s[k];
		if (s[k]<0) return 0;
		--pos;
	}
	for (int i=0;i<10;i++)
		now[i]=s[i];
	for (int p=pos;p>=0;p--)
	{
		for (int i=rightnum[p]-1;i>=(p==pos?leftnum[p]+1:0);i--)
			if (now[i]>0) return 1;
		int k=rightnum[p];
		--now[k];
		if (now[k]<0) break;
	}
	for (int i=0;i<10;i++)
		now[i]=s[i];
	for (int p=pos;p>=0;p--)
	{
		for (int i=leftnum[p]+1;i<=(p==pos?rightnum[p]-1:9);i++)
			if (now[i]>0) return 1;
		int k=leftnum[p];
		--now[k];
		if (now[k]<0) break;
	}
	return 0;
}
void dfs(int pos)
{
	if (pos==Maxn)
	{
		++cnt;
		int i;
		for (i=0;i<10;i++)
			s[i]=0;
		for (i=0;i<Maxn;i++)
			++s[cur[i]];
		ans+=check();
		return;
	}
	int k;
	for (k=cur[pos-1];k<=9;k++)
	{
		cur[pos]=k;
		dfs(pos+1);
	}
}
int main()
{
	scanf("%lld%lld",&L,&R);
	if (L==R)
	{
		printf("%d\n",1);
		return 0;
	}
	--L,++R;
	long long nowL=L,nowR=R;
	for (int i=0;i<Maxn;i++)
	{
		leftnum[i]=nowL%10;
		nowL/=10;
	}
	for (int i=0;i<Maxn;i++)
	{
		rightnum[i]=nowR%10;
		nowR/=10;
	}
	for (int k=0;k<=9;k++)
	{
		cur[0]=k;
		dfs(1);
	}
	printf("%d\n",ans);
	return 0;
}