#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll delta(ll a,ll b,ll c)
{
	return b*b-4*a*c;
}
int main()
{
	ll a,b,c;
	scanf("%I64d%I64d%I64d",&a,&b,&c);
	if(a==0&&b==0&&c==0)
	{
		puts("-1");
		return 0;
	}
	else if(a==0&&b==0&&c!=0)
	{
		puts("0");
		return 0;
	}
	else if(a==0&&b!=0)
	{
		puts("1");
		double x=(b*c>0)?-(sqrt(c*c)/sqrt(b*b)):(sqrt(c*c)/sqrt(b*b));
		printf("%8lf",x);
		return 0;
	}
	int s;
	if(delta(a,b,c)<0)
	{
		puts("0");
		return 0;
	}
	else if(delta(a,b,c)==0)
	{
		puts("1");
		double x=-b/(2*a);
		printf("%8lf",x);
		return 0;
	}
	else
	{
		puts("2");
		double x1=(-b-sqrt(delta(a,b,c)))/(2*a),x2=(-b+sqrt(delta(a,b,c)))/(2*a);
		printf("%8lf",min(x1,x2));
		printf("\n");
		printf("%8lf",max(x1,x2));
		return 0;
	}
}