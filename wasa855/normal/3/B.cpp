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
#define N 100005
struct Node
{
	int wei;
	int dat;
	double pri;
};
Node a[N];
Node one[N];
Node two[N];
int sum[N];
bool cmp(Node x,Node y)
{
	return x.dat>y.dat;
}
signed main()
{
	int n,v;
	cin>>n>>v;
	int c1=0,c2=0;
	for(int i=1;i<=n;i++)
	{
		a[i].wei=read();
		a[i].dat=read();
		if(a[i].wei==1) one[++c1].dat=a[i].dat,one[c1].wei=i;
		if(a[i].wei==2) two[++c2].dat=a[i].dat,two[c2].wei=i;
	}
	sort(one+1,one+c1+1,cmp);
	sort(two+1,two+c2+1,cmp);
	for(int i=1;i<=c1;i++)
	{
		sum[i]=sum[i-1]+one[i].dat;
	}
	int ans=0;
	int tmp=0;
	int aa=0;
	for(int i=0;i<=c2;i++)
	{
		if(i*2>v) break;
		tmp+=two[i].dat;
		int cnt=v-2*i;
		if(cnt>c1)
		{
			if(tmp+sum[c1]>ans)
			{
				ans=tmp+sum[c1];
				aa=i;
			}
		}
		else
		{
			if(tmp+sum[cnt]>ans)
			{
				ans=tmp+sum[cnt];
				aa=i;
			}
		}
//		if(cnt>c1) ans=max(ans,tmp+sum[c1]);
//		else ans=max(ans,tmp+sum[cnt]);
	}
	cout<<ans<<endl;
	int cnt=v-2*aa;
	cnt=min(cnt,c1);
	for(int i=1;i<=aa;i++) printf("%d ",two[i].wei);
	for(int i=1;i<=cnt;i++) printf("%d ",one[i].wei);
	return 0;
}