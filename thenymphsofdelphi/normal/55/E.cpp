#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Point
{
	ll x,y;
	Point(){};
	Point(ll x,ll y):x(x),y(y){}
};
Point operator-(const Point& lhs,const Point& rhs){
	return Point(lhs.x-rhs.x,lhs.y-rhs.y);
}
ll operator*(const Point& lhs,const Point& rhs){
	return lhs.x*rhs.y - lhs.y*rhs.x; 
}
ll s[1<<20];
Point p[1<<20];
Point q;
int main()
{
	int n,m;
	ll l,r,ans;
	for(int i=2;i<(1<<20);i++){
		s[i]+=s[i-1]+i-1;
	}
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>p[i].x>>p[i].y;
		p[n+i]=p[i];
	}
	cin>>m;
	for(int i=0;i<m;i++)
	{
		cin>>q.x>>q.y;
		for(int j=0;j<n;j++)
		{
			if((p[j]-q)*(p[j+1]-q) >= 0)
			{
			    printf("0\n");
				goto  NEXT	;
			}
		}
		ans = 0;
		for(int j=0,k=0;j<n;j++)
		{
			while((p[j]-q)*(p[k]-q)<=0)
			{
				k++;
			}
			l = k-1-j;
			r = n-1-l;
			ans += s[l]+s[r];
		}
		printf("%I64d\n",1LL*n*(n-1)*(n-2)/6-ans/2);
		NEXT : continue;
		
	}
	return 0;
}