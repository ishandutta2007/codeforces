#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
/*struct Node
{
	int s,e,id;
}q[1000100];
bool cmpx(Node x,Node y)
{
	if(x.s==y.s)return x.e<y.e;
	return x.s<y.s;
}
bool cmpy(Node x,Node y)
{	
	if(x.e==y.e)return x.s<y.s;
	return x.e<y.e;
}
bool cmpid(Node x,Node y)
{return x.id<y.id;}*/
int l[1000100],lg[12];
char ch[100100],p[12][12];
int i,j,k,po,st,ma,le,n;
int main()
{
	while(~scanf("%s",&ch))
	{
		le=strlen(ch);
		for(i=0;i<le;i++)
		l[i]=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%s",p[i]);
			lg[i]=strlen(p[i]);
			for(j=0;j+lg[i]<=le;j++)
			{
				bool can=true;
				for(k=0;k<lg[i];k++)
				{
					if(ch[j+k]!=p[i][k])
					{can=false;break;}
				}
				if(can)
				{
					l[j+lg[i]-1]=max(j+1,l[j+lg[i]-1]);
				}
			}
		}
	//	for(i=0;i<le;i++)printf("%d ",l[i]);puts("");
		ma=0;st=0;po=0;
		for(i=0;i<le;i++)
		{
			po=max(po,l[i]);
	//		printf("%d ",po);
			if(ma<i-po+1)
			{
				ma=i-po+1;st=po;
			}
		}
		printf("%d %d\n",ma,st);
	}
}