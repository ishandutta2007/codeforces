#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ldb long double
const ldb eps=1e-6;
template<typename T> struct pt{ T x,y;pt(T a=0, T b=0):x(a),y(b){}};
ll sgn(ll x){ return x?x/abs(x):x;}
bool QuadraticEquation(ldb a, ldb b, ldb c, ldb &l, ldb &r)
{
	if(a==0) return 0;
	ldb D=b*b-4*a*c;
	if(D<0) return 0;
	if(D==0){ l=r=-b/(2*a);return 1;}
	ldb sum;
	if(b>0) sum=-b-sqrt(D);
	else sum=-b+sqrt(D);
	l=sum/(2*a);r=sum!=0?(2*c)/sum:0;
	if(l>r) swap(l,r);
	return 1;
}
int main()
{
	int n,i;
	scanf("%i",&n);
	vector<pt<ll>> ps(n);
	for(i=0;i<n;i++) scanf("%lld %lld",&ps[i].x,&ps[i].y);
	for(i=1;i<n;i++) if(sgn(ps[i].y)*sgn(ps[i-1].y)==-1) return 0*printf("-1\n");
	for(i=0;i<n;i++) ps[i].y=abs(ps[i].y);
	ldb top=1e16,bot=0,mid,ans;
	for(int j=0;j<150;j++)
	{
		mid=(top+bot)/2;
		ldb l,r;
		bool ok=1,fir=1;
		for(i=0;i<n;i++)
		{
			ldb L,R;
			if(QuadraticEquation(1,(ldb)ps[i].x*(-2),(ldb)ps[i].y*ps[i].y-(ldb)mid*2*ps[i].y+(ldb)ps[i].x*ps[i].x,L,R))
			{
				if(fir) l=L,r=R,fir=0;
				l=max(l,L);r=min(r,R);
			}
			else ok=0;
		}
		if(l>r) ok=0;
		if(ok) top=mid;
		else bot=mid;
	}
	cout<<fixed<<setprecision(12)<<(top+bot)/2<<"\n";
	return 0;
}