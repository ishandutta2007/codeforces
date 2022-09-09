#include <stdio.h>
const int N=155;
int max(int a, int b){ return a>b?a:b;}
struct Poly
{
	int a[N],sz;
	Poly(){ for(int i=0;i<N;i++) a[i]=0;sz=0;}
	void Push()
	{
		sz++;
		for(int i=sz;i;i--) a[i]=a[i-1];
	}
	Poly operator + (Poly b) const
	{
		Poly c;
		c.sz=max(b.sz,sz);
		for(int i=1;i<=c.sz;i++) c.a[i]=(a[i]+b.a[i])&1;
		return c;
	}
	void Print()
	{
		printf("%i\n",sz-1);
		for(int i=1;i<=sz;i++) printf("%i ",a[i]);
		printf("\n");
	}
} fib[N],tmp;
int main()
{
	int n,i,j;
	scanf("%i",&n);
	fib[0].sz=1;
	fib[0].a[1]=1;
	fib[1].sz=2;
	fib[1].a[1]=0;
	fib[1].a[2]=1;
	for(i=2;i<=n;i++)
	{
		for(j=0;j<N;j++) tmp.a[j]=fib[i-1].a[j];
		tmp.sz=fib[i-1].sz;
		tmp.Push();
		fib[i]=tmp+fib[i-2];
	}
	fib[n].Print();
	fib[n-1].Print();
	return 0;
}