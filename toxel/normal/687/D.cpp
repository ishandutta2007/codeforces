#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#define N 500000
#define M 1000
using namespace std;
typedef struct edge
{
	int u,v,length,number;
};
/*typedef vector<edge>vec;
typedef struct segment
{
	int left,right;
	segment *leftchild,*rightchild;
	vec edges;
};
segment head;*/
edge edg[N];
int point[2*N];
bool compare(edge a,edge b)
{
	return a.length>b.length;
}
int find(int i)
{
	return i==point[i]?i:point[i]=find(point[i]);
}
void unite(int u,int v)
{
	u=find(u);
	v=find(v);
	if (u!=v)
		point[u]=v;
}
/*vec *build(segment *head,int left,int right)
{
	segment *p1,*p2;
	head->left=left;
	head->right=right;
	if (right==left)
	{
		head->leftchild=NULL;
		head->rightchild=NULL;
		return ;
	}
	int mid=(left+right)/2;
	head->leftchild=(segment *)malloc(sizeof(segment));
	build(head->leftchild,left,mid);
	head->rightchild=(segment *)malloc(sizeof(segment));
	build(head->rightchild,mid+1,right);
	
}*/
int main()
{
	int n,m,q,i,j,l,r,ans[M],flag;
	/*FILE *fp;
	fp=fopen("f.in","r");
	fscanf(fp,"%d%d%d",&n,&m,&q);
	for (i=1;i<=m;i++)
	{
		fscanf(fp,"%d%d%d",&edg[i].u,&edg[i].v,&edg[i].length);
		edg[i].number=i;
	}
	sort(edg+1,edg+m+1,compare);
	for (i=0;i<q;i++)
	{
		flag=true;
		fscanf(fp,"%d%d",&l,&r);
		for (j=1;j<=2*n;j++)
			point[j]=j;
		for (j=1;j<=m;j++)
			if (edg[j].number>=l&&edg[j].number<=r)
			{
				if (find(edg[j].v)==find(edg[j].u))
				{
					ans[i]=edg[j].length;
					flag=false;
					break;
				}
				else
				{
					unite(edg[j].v,edg[j].u+n);
					unite(edg[j].v+n,edg[j].u);
				}
			}
		if (flag)
			ans[i]=-1;
	}*/
	scanf("%d%d%d",&n,&m,&q);
	for (i=1;i<=m;i++)
	{
		scanf("%d%d%d",&edg[i].u,&edg[i].v,&edg[i].length);
		edg[i].number=i;
	}
	sort(edg+1,edg+m+1,compare);
	for (i=0;i<q;i++)
	{
		flag=true;
		scanf("%d%d",&l,&r);
		for (j=1;j<=2*n;j++)
			point[j]=j;
		for (j=1;j<=m;j++)
			if (edg[j].number>=l&&edg[j].number<=r)
			{
				if (find(edg[j].v)==find(edg[j].u))
				{
					ans[i]=edg[j].length;
					flag=false;
					break;
				}
				else
				{
					unite(edg[j].v,edg[j].u+n);
					unite(edg[j].v+n,edg[j].u);
				}
			}
		if (flag)
			ans[i]=-1;
	}
	for (i=0;i<q;i++)
		printf("%d\n",ans[i]);
	return 0;
}