#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	long double X,Y,R,x,y,r,a,b,c,n,m,ans=0;
	cin>>X>>Y>>R>>x>>y>>r;
	n=(X-x)*(X-x)+(Y-y)*(Y-y);
	n=sqrt(n);
	long double p=acos(-1);
	if(n>=R+r) ans=0;
	else if(n+r<=R||n+R<=r) ans=p*min(r,R)*min(r,R);
	else {
		a=acos((R*R+n*n-r*r)/(2*R*n));
		b=acos((r*r+n*n-R*R)/(2*r*n));
		ans=(long double)(R*R*a+r*r*b-R*R*sin(a)*cos(a)-r*r*sin(b)*cos(b));
	}
	cout<<fixed<<setprecision(20)<<ans;
}