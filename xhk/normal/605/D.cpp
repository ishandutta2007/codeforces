#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

struct unit
{int x1,y1,x2,y2,num;
};
struct unit a[100010];

int n,tot;
int sa[200010],used[100010],p[200010],q[100010],dis[100010],pre[100010];
vector<int> c[200010];

void change(int i,int x)
{while(i<=tot)
 {	c[i].push_back(x);
 	i+=i&(-i);
 }
}

bool cmp(int A,int B)
{return a[A].y1<a[B].y1;
}

void print(int i)
{if(pre[i]==-1) 
	printf("%d",i);
 else
 {	print(pre[i]);
 	printf(" %d",i);
 }
}

int main()
{int i,j,t=1,w=0,flag=0;
 
 scanf("%d",&n);
 memset(pre,-1,sizeof(pre));
 for(i=1;i<=n;i++)
 {	scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
 	tot++;
 	sa[tot]=a[i].x1;
 	tot++;
  	sa[tot]=a[i].x2;
  	if(a[i].x1==0 && a[i].y1==0) 
	{	flag=1;
		w++;
		q[w]=i;
		used[i]=1;
		dis[i]=1;
	}
 }
 if(!flag)
 {	printf("%d\n",-1);
 	return 0;
 }
 sort(sa+1,sa+tot+1);
 //cout<<tot<<endl;
 for(i=1;i<=n;i++)
 {	a[i].x1=lower_bound(sa+1,sa+tot+1,a[i].x1)-sa;
 	a[i].x2=lower_bound(sa+1,sa+tot+1,a[i].x2)-sa;
 	change(a[i].x1,i);
 }
 for(i=1;i<=tot;i++)
 	sort(c[i].begin(),c[i].end(),cmp);
 while(t<=w)
 {	//cout<<t<<" "<<w<<" "<<q[t]<<endl;
 	if(q[t]==n)
 	{	printf("%d\n",dis[q[t]]);	
 		print(n);
 		return 0;
 	}
 	i=a[q[t]].x2;
 	//cout<<i<<endl;
 	while(i>=1)
 	{	//cout<<i<<" "<<p[i]<<" "<<a[q[t]].y2<<endl;
	 	while(p[i]<c[i].size() && a[c[i][p[i]]].y1<=a[q[t]].y2)
 		{	if(used[c[i][p[i]]]==0)
 			{	used[c[i][p[i]]]=1;
 				w++;
 				q[w]=c[i][p[i]];
 				pre[c[i][p[i]]]=q[t];
 				dis[c[i][p[i]]]=dis[q[t]]+1;
 			}
 			p[i]++;
 		}
 		i-=i&(-i);
 	}
 	t++;
 }
 printf("%d\n",-1);
 return 0;
}