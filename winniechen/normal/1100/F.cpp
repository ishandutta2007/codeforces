#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 500005
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
struct Mat
{
	int a[21],siz;
	Mat(){memset(a,0,sizeof(a));siz=0;}
	bool insert(int x)
	{
		if(siz==20)return 0;
		for(int i=19;~i;i--)if((x>>i)&1)
			if(a[i])x^=a[i];
			else {a[i]=x;siz++;return 1;}
		return 0;
	}
	void calc(int &x){for(int i=19;~i;i--)if((!((x>>i)&1))&&a[i])x^=a[i];}
	int calc(){int x=0;for(int i=19;~i;i--)if(!((x>>i)&1)&&a[i])x^=a[i];return x;}
}t[N];
int a[N],n,lst[22],ans[N],Q;
struct node{int l,r,idx;}q[N];
inline bool cmp(const node &a,const node &b){return a.r==b.r?a.l<b.l:a.r<b.r;}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	scanf("%d",&Q);
	for(int i=1;i<=Q;i++)scanf("%d%d",&q[i].l,&q[i].r),q[i].idx=i;sort(q+1,q+Q+1,cmp);
	for(int i=1,k=1;i<=n;i++)
	{
		if(!lst[0])lst[0]=i;
		// printf("%d\n",i);
		for(int j=19;j;j--)if(lst[j])
		{
			if(t[lst[j]].insert(a[i]))
			{
				if(!lst[j+1])lst[j+1]=lst[j];
				// if(lst[j]==3)printf("%d\n",a[i]);
				lst[j]++;
				while(lst[j]<lst[j-1]&&t[lst[j]].insert(a[i]))
				{
					// if(lst[j]==3)printf("%d\n",a[i]);
					// if(lst[j]==4)printf("%d\n",a[i]);
					lst[j]++;
				}
				if(lst[j]==lst[j-1])lst[j]=0;
			}
		}
		if(t[lst[0]].insert(a[i]))
		{
			if(!lst[1])lst[1]=lst[0];lst[0]++;
			while(lst[0]<=i&&t[lst[0]].insert(a[i]))
			{
				// if(lst[0]==3)printf("%d\n",a[i]);
				// if(lst[0]==4)printf("%d\n",a[i]);
				lst[0]++;
			}
			if(lst[0]==i+1)lst[0]=0;
		}
		// for(int j=5;j;j--)printf("j=%d lst[j]=%d\n",j,lst[j]);
		while(k<=Q&&q[k].r==i)t[q[k].l].calc(ans[q[k].idx]),k++;
	}
	// printf("%d %d\n",t[4].siz,t[3].siz);
	for(int i=1;i<=Q;i++)printf("%d\n",ans[i]);
}
/*
10
32 52 25 0 1 9 8 16 64 16
10
2 7
2 6
6 8
1 1
5 10
5 8
4 10
6 8
2 6
6 10
 */