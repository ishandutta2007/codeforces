#include <bits/stdc++.h>
using namespace std;
struct point
{
	long long x,y;
	point operator + (point A)
	{
		return (point){x+A.x,y+A.y};
	}
	point operator * (long long t)
	{
		return (point){t*x,t*y};
	}
}W[100005],a,b;
int n;
string str;
int main()
{
	scanf("%lld%lld%lld%lld",&a.x,&a.y,&b.x,&b.y);
	scanf("%d",&n);
	cin>>str;
	for(int i=0;i<n;i++)
	{
		point tmp=W[i];
		if(str[i]=='U') tmp.y++;
		else if(str[i]=='D') tmp.y--;
		else if(str[i]=='L') tmp.x--;
		else tmp.x++;
		W[i+1]=tmp;
	}
	long long l=0,r=1e18;
	while(l+1<=r)
	{
		long long mid=(l+r)/2;
		point now=a+W[n]*(mid/n)+W[mid%n];
		if(abs(now.x-b.x)+abs(now.y-b.y)<=mid) r=mid;
		else l=mid+1;
	}
	printf("%lld",l==1e18?-1:l);
	return 0;
}