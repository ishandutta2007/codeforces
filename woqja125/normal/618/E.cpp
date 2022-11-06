#include<stdio.h>
#include<math.h>
#define PI 3.14159265358979323846
double Sin(int d){ return sin(d*PI/180); }
double Cos(int d){ return cos(d*PI/180); }
//double getx(int l, int d){ return l*cos(d*M_PI/180); }
//double gety(int l, int d){ return l*sin(d*M_PI/180); }
struct node
{
	int d, a;
	double x, y;
	node *r, *l;
	void init(int s, int e);
	void op1(int s, int e, int X, int L);
	void op2(int s, int e, int i, int f, int A);
} ST[600010];
int C;
int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	ST->init(1, n);
	int t, s, v;
	for(i=1; i<=m; i++)
	{
		scanf("%d%d%d", &t, &s, &v);
		if(t==1) ST->op1(1, n, s, v);
		else ST->op2(1, n, s, n, 360-v);
		printf("%.10f %.10f\n", ST->x, ST->y);
	}
	return 0;
}
void node::init(int s, int e)
{
	if(s==e) { d=1; a=0; x=1; y = 0; }
	else
	{
		l = ST+(++C); r = ST+(++C);
		l->init(s, (s+e)/2);
		r->init((s+e)/2+1, e);
		x = l->x + r->x;
		y = l->y + r->y;
		d = a = 0;
	}
}
void node::op1(int s, int e, int X, int L)
{
	if(s==e)
	{
		d += L;
		x = d*Cos(a);
		y = d*Sin(a);
		return;
	}
	if(X<=(s+e)/2) l->op1(s, (s+e)/2, X, L);
	else r->op1((s+e)/2+1, e, X, L);
	double xx = l->x + r->x, yy = l->y + r->y;
	x = xx*Cos(a) - yy*Sin(a);
	y = xx*Sin(a) + yy*Cos(a);
}
void node::op2(int s, int e, int i, int f, int A)
{
	if(s > f || e < i) return;
	if(i<=s && e<=f)
	{
		(a += A)%=360;
		double xx=x, yy=y;
		x = xx*Cos(A) - yy*Sin(A);
		y = xx*Sin(A) + yy*Cos(A);
		return;
	}
	l->op2(s, (s+e)/2, i, f, A);
	r->op2((s+e)/2+1, e, i, f, A);
	double xx = l->x + r->x, yy = l->y + r->y;
	x = xx*Cos(a) - yy*Sin(a);
	y = xx*Sin(a) + yy*Cos(a);
}