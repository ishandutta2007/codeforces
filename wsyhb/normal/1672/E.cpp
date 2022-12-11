#include<bits/stdc++.h>
using namespace std;
inline int query(int w)
{
	assert(w>=1&&w<=1e9);
	printf("? %d\n",w);
	fflush(stdout);
	int h;
	scanf("%d",&h);
	return h;
}
int main()
{
	int n;
	scanf("%d",&n);
	int L=n+(n-1),R=n*2000+(n-1),S=-1;
	while(L<=R)
	{
		int mid=(L+R)>>1;
		if(query(mid)==1)
			S=mid,R=mid-1;
		else
			L=mid+1;
	}
	assert(S!=-1);
	int ans=S;
	for(int h=2;h<=n;++h)
	{
		int w=S/h;
		if(query(w)==h)
			ans=min(ans,h*w);
	}
	printf("! %d\n",ans);
	fflush(stdout);
	return 0;
}