#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	int ans=0;
	while(isdigit(ch))
	{
		ans=ans*10+ch-48;
		ch=getchar();
	}
	return ans;
}
#define N 1005
int a[N],b[N],x[N],y[N];
struct Node
{
	int a,b,c,d;
};
Node res[N*100];
int ss;
void add(int a,int b,int c,int d)
{
	ss++; res[ss].a=a; res[ss].b=b; res[ss].c=c; res[ss].d=d;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		b[i]=read();
		y[b[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		x[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==i&&b[i]==i) continue;
		add(i,x[i],y[i],i);
		int r=x[i];
		swap(x[i],x[a[i]]);
		swap(a[i],a[r]);
		r=y[i];
		swap(y[i],y[b[i]]);
		swap(b[i],b[r]);
	}
	cout<<ss<<endl;
	for(int i=1;i<=ss;i++)
	{
		printf("%d %d %d %d\n",res[i].a,res[i].b,res[i].c,res[i].d);
	}
	return 0;
}