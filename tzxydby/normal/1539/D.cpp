#include<bits/stdc++.h>
using namespace std;
const int N=100005;
struct nd
{
	long long x,y;
	bool operator<(const nd k)const
	{
		return y<k.y;
	}
}a[N];
int n;
long long s,t[N],h;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",&a[i].x,&a[i].y);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		t[i]=a[i].x;
	int l=1,r=n;
	while(1)
	{
		if(l>r)
			break;
		if(h>=a[l].y)
		{
			s+=t[l];
			h+=t[l];
			t[l]=0;
			l++;
			continue;
		}		
		long long k=min(a[l].y-h,t[r]);
		s+=k*2;
		h+=k;
		t[r]-=k;
		if(!t[r])
			r--;
	}
	printf("%lld\n",s);
	return 0;
}