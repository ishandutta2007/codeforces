#include<bits/stdc++.h>
const long long N=1<<17;
const long long moder=1000000007;
typedef struct matrix
{
	long long num[2][2];
};
typedef struct segment
{
	long long l,r;
	matrix m,lazy;
};
matrix ans[N],mat[60],I,O;
segment seg[N<<1];
long long n,a[N];
matrix add(matrix a,matrix b)
{
	matrix sum;
	sum.num[0][0]=(a.num[0][0]+b.num[0][0])%moder;
	sum.num[0][1]=(a.num[0][1]+b.num[0][1])%moder;
	sum.num[1][0]=(a.num[1][0]+b.num[1][0])%moder;
	sum.num[1][1]=(a.num[1][1]+b.num[1][1])%moder;
	return sum;
}
matrix multiply(matrix a,matrix b)
{
	matrix product;
	product.num[0][0]=(a.num[0][0]*b.num[0][0]+a.num[0][1]*b.num[1][0])%moder;
	product.num[0][1]=(a.num[0][0]*b.num[0][1]+a.num[0][1]*b.num[1][1])%moder;
	product.num[1][0]=(a.num[1][0]*b.num[0][0]+a.num[1][1]*b.num[1][0])%moder;
	product.num[1][1]=(a.num[1][0]*b.num[0][1]+a.num[1][1]*b.num[1][1])%moder;
	return product;
}
matrix fib(long long x)
{
	bool flag[60];
	long long i=0;
	matrix a=I;
	while (x)
	{
		flag[i++]=x%2;
		x/=2;
	}
	while (--i>=0)
		if (flag[i])
			a=multiply(a,mat[i]);
	return a;
}
void build()
{
	long long i;
	matrix x;
	x.num[0][0]=0;
	x.num[0][1]=0;
	x.num[1][0]=0;
	x.num[1][1]=1;
	for (i=(N<<1)-1;i>=N+n;i--)
	{
		seg[i].m=O;
		seg[i].lazy=I;
		seg[i].l=seg[i].r=i-N+1;
	}
	for (i=N+n-1;i>=N;i--)
	{
		seg[i].m=multiply(fib(a[i-N+1]),x);
		seg[i].l=seg[i].r=i-N+1;
		seg[i].lazy=I;
	}
	for (i=N-1;i>=1;i--)
	{
		seg[i].m=add(seg[2*i].m,seg[2*i+1].m);
		seg[i].l=seg[2*i].l;
		seg[i].r=seg[2*i+1].r;
		seg[i].lazy=I;
	}
}
void change(long long i,long long left,long long right,long long x)
{
	if (i>1)
	{
		seg[i].m=multiply(seg[i/2].lazy,seg[i].m);
		seg[i].lazy=multiply(seg[i/2].lazy,seg[i].lazy);
		seg[i^1].m=multiply(seg[i/2].lazy,seg[i^1].m);
		seg[i^1].lazy=multiply(seg[i/2].lazy,seg[i^1].lazy);
		seg[i/2].lazy=I;
	}
	if (seg[i].l>=left&&seg[i].r<=right)
	{
		seg[i].m=multiply(fib(x),seg[i].m);
		seg[i].lazy=multiply(fib(x),seg[i].lazy);
		return;
	}
	if (right<=seg[2*i].r)
	{
		change(2*i,left,right,x);
		seg[i].m=add(seg[2*i].m,seg[2*i+1].m);
		return;
	}
	if (left>=seg[2*i+1].l)
	{
		change(2*i+1,left,right,x);
		seg[i].m=add(seg[2*i].m,seg[2*i+1].m);
		return;
	}
	change(2*i,left,seg[2*i].r,x);
	change(2*i+1,seg[2*i+1].l,right,x);
	seg[i].m=add(seg[2*i].m,seg[2*i+1].m);
}
matrix search(long long i,long long left,long long right)
{
	matrix answer=O;
	if (i>1)
	{
		seg[i].m=multiply(seg[i/2].lazy,seg[i].m);
		seg[i].lazy=multiply(seg[i/2].lazy,seg[i].lazy);
		seg[i^1].m=multiply(seg[i/2].lazy,seg[i^1].m);
		seg[i^1].lazy=multiply(seg[i/2].lazy,seg[i^1].lazy);
		seg[i/2].lazy=I;
	}
	if (seg[i].l>=left&&seg[i].r<=right)
	{
		answer=add(answer,seg[i].m);
		return answer;
	}
	if (right<=seg[2*i].r)
	{
		answer=add(answer,search(2*i,left,right));
		return answer;
	}
	if (left>=seg[2*i+1].l)
	{
		answer=add(answer,search(2*i+1,left,right));
		return answer;
	}
	answer=add(answer,search(2*i,left,seg[2*i].r));
	answer=add(answer,search(2*i+1,seg[2*i+1].l,right));
	return answer;
}
int main()
{
	long long m,i,j=0,t,l,r,x;
	segment *head;
	I.num[0][0]=1;
	I.num[0][1]=0;
	I.num[1][0]=0;
	I.num[1][1]=1;
	O.num[0][0]=0;
	O.num[0][1]=0;
	O.num[1][0]=0;
	O.num[1][1]=0;
	scanf("%I64d%I64d",&n,&m);
	for (i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	mat[0].num[0][0]=0;
	mat[0].num[0][1]=1;
	mat[0].num[1][0]=1;
	mat[0].num[1][1]=1;
	for (i=1;i<60;i++)
		mat[i]=multiply(mat[i-1],mat[i-1]);
	head=(segment *)malloc(sizeof(segment));
	build();
	for (i=1;i<=m;i++)
	{
		scanf("%I64d",&t);
		if (t==1)
		{
			scanf("%I64d%I64d%I64d",&l,&r,&x);
			change(1,l,r,x);
		}
		else
		{
			scanf("%I64d%I64d",&l,&r);
			ans[j++]=search(1,l,r);
		}
	}
	for (i=0;i<j;i++)
		printf("%I64d\n",ans[i].num[0][1]);
	return 0;
}