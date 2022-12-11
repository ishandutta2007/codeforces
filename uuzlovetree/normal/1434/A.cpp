#include<bits/stdc++.h>
using namespace std;
int a[10];
int n,b[1000005];
struct data
{
	int val,id;
}d[1000005];
bool operator < (data A,data B)
{
	return A.val<B.val;
}
int c[1000005],num;
int main()
{
	for(int i=1;i<=6;++i)scanf("%d",&a[i]);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&b[i]);
	for(int i=1;i<=n;++i)
		for(int j=0;j<6;++j)d[i*6-j].val=b[i]-a[j+1],d[i*6-j].id=i;
	sort(d+1,d+n*6+1);
	//for(int i=1;i<=n*6;++i)cerr<<i<<" "<<d[i].val<<" "<<d[i].id<<endl;
	int r=0,ans=(int)(1e9+7);
	for(int l=1;l<=n*6;++l)
	{
		while(r<=n*6&&num<n)
		{
			++r;
			if(!c[d[r].id])num++;
			c[d[r].id]++;
		}
		if(r>n*6)break;
		//cerr<<l<<" "<<r<<" "<<d[l].val<<" "<<d[r].val<<endl;
		if(num==n)ans=min(ans,d[r].val-d[l].val);
		c[d[l].id]--;
		if(!c[d[l].id])num--;
	}
	printf("%d\n",ans);
}