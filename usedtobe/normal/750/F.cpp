#include<bits/stdc++.h>
using namespace std;
int a[1000],cnt,k,use[1000],b[1000][3],h,j,t,tot,A[1000],B[1000];
/*void ask(int x)
{
	printf("? %d\n",x);
	if(tot>=16){use[x]=2;return;}
	tot++;
	if((A[x]<<1)<(1<<h))b[x][use[x]++]=B[A[x]<<1],b[x][use[x]++]=B[A[x]<<1|1];
	if(A[x]!=1)b[x][use[x]++]=B[A[x]>>1];
	printf("%d\n",use[x]);
	for(int i=0;i<use[x];i++)printf("%d ",b[x][i]);puts("");
}*/
void ask(int x)
{
	if(tot>=16){use[x]=2;return;}
	printf("? %d\n",x);tot++;
	fflush(stdout);
	scanf("%d",&k);use[x]=k;
	for(int i=0;i<k;i++)scanf("%d",&b[x][i]);
}
int dfs(int x,int y)
{
	//printf("dfs %d %d\n",x,y);
	if(!use[x])ask(x);
	if(use[x]==2)return x;
	if(use[x]==1)return (-y/2)+1;
	if(y>=h)return 0;
	int i,ans;
	for(i=0;i<use[x];i++)
	if(!use[b[x][i]])
	{
		ans=dfs(b[x][i],y+1);
		//printf("dfs %d %d=%d\n",b[x][i],y+1,ans);
		if(ans>0)return ans;
		if(ans<0)return ans+1;
	}
	return 0;
}
int getans()
{
	int i,ans;
	for(a[cnt=1]=1;;cnt++)
	{
		ask(a[cnt]);
		if(use[a[cnt]]==2)return a[cnt];
		if(use[a[cnt]]==1)break;
		for(i=0;i<k;i++)if(!use[b[a[cnt]][i]])break;
		a[cnt+1]=b[a[cnt]][i];
	}
	if(cnt==1)cnt=2,a[1]=b[a[1]][0];
	for(j=cnt>>1;j>=1;j--)
		if((ans=dfs(a[j],cnt-j+1))>0)return ans;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&h);
		/*for(int i=1;i<1<<h;i++)A[i]=i;
		random_shuffle(A+1,A+(1<<h));
		for(int i=1;i<1<<h;i++)B[A[i]]=i;*/
		cnt=0;tot=0;
		memset(a,0,sizeof(a));
		memset(use,0,sizeof(use));
		memset(b,0,sizeof(b));
		//printf("rt=%d\n",B[1]);
		//if(A[getans()]!=1)puts("galigeigei");else puts("haha");
		printf("! %d\n",getans());
		fflush(stdout);
	}
}