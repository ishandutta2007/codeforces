#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
const double eps=1e-3;
int n,a[maxn];
map<int,int> mp;
map<int,int> vis;
int ans=0;
int Ans[maxn];
inline bool is2p(int x)
{
	int y=log2(x);
	if(fabs(pow(2,y)-(double)x)<=eps)return 1;
	return 0;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	n=unique(a+1,a+n+1)-a-1;
	for(int i=1;i<=n;++i)mp[a[i]]=i;
	ans=1;Ans[1]=a[1];
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<=30;++j)
		{
			long long x=(long long)a[i]+(long long)pow(2,j);
			if(x>1000000000)break;
			if(mp[x])
			{
				int y=x+(int)pow(2,j);
				if(mp[y])
				{
					ans=3;Ans[1]=a[i];Ans[2]=x;Ans[3]=y;
				}
				else if(ans<=2)
				{
					ans=2;Ans[1]=a[i];Ans[2]=x;
				}
			}
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=ans;++i)printf("%d ",Ans[i]);
	return 0;
}