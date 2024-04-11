#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
int a[max_n],val[max_n];
map<int,int> nxt[max_n];
inline int Find(int x,int d)
{
	if(!nxt[x].count(d))
		return 1;
	int p=nxt[x][d];
	nxt[x].erase(d);
	return Find(p,d)+1;
}
int main()
{
//	freopen("input.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	int B=sqrt(1e5)+5,ans=0;
	for(int d=-B/4;d<=B/4;++d)
	{
		for(int i=1;i<=n;++i)
			val[i]=a[i]-(i-1)*d;
		sort(val+1,val+n+1);
		for(int i=1;i<=n;++i)
		{
			int j=i;
			while(j+1<=n&&val[j+1]==val[i])
				++j;
			ans=max(ans,j-i+1);
			i=j;
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=i+B*4&&j<=n;++j)
		{
			int d=a[j]-a[i];
			if(d%(j-i)==0)
			{
				d/=j-i;
				if(nxt[i].count(d)==0)
					nxt[i][d]=j;
			}
		}
	for(int i=1;i<=n;++i)
		for(map<int,int>::iterator it=nxt[i].begin();it!=nxt[i].end();++it)
		{
			int d=it->first,p=it->second;
			ans=max(ans,Find(p,d)+1);
		}
	printf("%d\n",n-ans);
	return 0;
}