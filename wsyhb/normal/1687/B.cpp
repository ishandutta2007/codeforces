#include<bits/stdc++.h>
using namespace std;
const int max_m=500+5;
int l[max_m],id[max_m];
inline bool cmp(int x,int y)
{
	return l[x]<l[y];
}
char s[max_m];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		printf("? ");
		for(int j=1;j<=m;++j)
			printf("%d",i==j);
		cout<<endl;
		scanf("%d",l+i);
		id[i]=i,s[i]='0';
	}
	sort(id+1,id+m+1,cmp);
	int sum=0;
	for(int i=1;i<=m;++i)
	{
		int x=id[i];
		sum+=l[x];
		s[x]='1';
		printf("? %s",s+1);
		cout<<endl;
		int res;
		scanf("%d",&res);
		if(res!=sum)
			s[x]='0',sum-=l[x];
	}
	printf("! %d\n",sum);
	fflush(stdout);
	return 0;
}