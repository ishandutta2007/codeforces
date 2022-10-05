#include <bits/stdc++.h>
using namespace std;
const int Maxn=10005;
int n,m,ans,now,all;
vector <int> Ve[Maxn];
bool check(int x)
{
	all=m;
	int cnt=0;
	int tot=x/n,las=x%n+1;
	for(int i=now;cnt<n;i++)
	{
		if(i>n) i=1;
		cnt++;
		las--;
		if(las==-1)
		{
			las=n-1,tot--;
			if(tot<0&&all) return false;
		}
		if(!(Ve[i].size()<=tot||(Ve[i].size()==tot+1&&*Ve[i].begin()<=las))) return false;
		else all-=Ve[i].size();
	}
	return true;
}
int main()
{
	//freopen("A.in","r",stdin);
	scanf("%d%d",&n,&m);
	all=m;
	for(int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		Ve[a].push_back((b-a+n)%n);
	}
	for(int i=1;i<=n;i++)
		sort(Ve[i].begin(),Ve[i].end());
	for(int i=1;i<=n;i++)
	{
		now=i;
		int l=1,r=n*m+n;
		while(l+1<=r)
		{
			int mid=(l+r)/2;
			if(check(mid)) r=mid;
			else l=mid+1;
		}
		printf("%d ",l);
	}
	return 0;
}