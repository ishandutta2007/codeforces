#include<stdio.h>
#include<complex>
#include<math.h>
using namespace std;
typedef complex<double>P;
P a,b,c;
int t,x,y;
double E=1e-8;
double xm(P a,P b)
{
	return imag(a*conj(b));
}
P K(const P&a,const P&b,const P&c)
{
	double x1=real(a),y1=imag(a),x2=real(b),y2=imag(b),x3=real(c),y3=imag(c);
	double s1=x1*x1+y1*y1,s2=x2*x2+y2*y2,s3=x3*x3+y3*y3;
	double rx=(y1*(s2-s3)+y2*(s3-s1)+y3*(s1-s2))/(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
	double ry=(x1*(s2-s3)+x2*(s3-s1)+x3*(s1-s2))/(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
	return P(-rx/2,ry/2);
}
void scan(P&a)
{
	scanf("%d%d",&x,&y),a=P(x,y);
}
void pt(P&a)
{
	printf("%.9f %.9f ",real(a),imag(a));
}
int F(P a,P b,P c)
{
	P d=b+b-c;
	P A=K(a,b,d),B=b+b-A,C=c+c-B,D=a+a-A;
	if(xm(A-D,B-A)<E||xm(B-A,C-B)<E||xm(C-B,D-C)<E||xm(D-C,A-D)<E)
		return 1;
	else
		return puts("YES"),pt(A),pt(B),pt(C),pt(D),0;
}
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scan(a),scan(b),scan(c);
		if(fabs(xm(b-a,c-a))<E||F(a,b,c)&&F(a,c,b)&&F(b,a,c)&&F(b,c,a)&&F(c,a,b)&&F(c,b,a))
			puts("NO");
		puts("");
	}
	return 0;
}