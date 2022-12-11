#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
int a[max_n],cnt_queries;
inline int query(int x)
{
	if(!a[x])
	{
		++cnt_queries;
		printf("? %d\n",x);
		fflush(stdout);
		scanf("%d",a+x);
	}
	return a[x];
}
int main()
{
	int n;
	scanf("%d",&n);
	int l=1,r=n,mid;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(query(mid)<query(mid+1))
			r=mid;
		else
			l=mid+1;
	}
	printf("! %d\n",l);
	fprintf(stderr,"cnt=%d\n",cnt_queries); 
	return 0;
}