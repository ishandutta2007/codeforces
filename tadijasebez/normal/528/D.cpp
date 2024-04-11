#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ldb double
const ldb PI=acos(-1);
/*struct base
{
	ldb real,imag;
	base(){}
	base(ldb a, ldb b):real(a),imag(b){}
    base operator - (base b){ return base(real-b.real,imag-b.imag);}
    base operator * (base b){ return base(real*b.real-imag*b.imag,real*b.imag+imag*b.real);}
    void operator += (base b){ real+=b.real;imag+=b.imag;}
    void operator /= (ldb b){ real/=b;imag/=b;}
};*/
#define base complex<ldb>
const int N=800050;
void fft(base a[], int n, bool inv)
{
    for(int i=1,j=0;i<n;i++)
	{
		int k=n;
		do j^=k>>=1; while(~j&k);
		if(j>i) swap(a[i],a[j]);
	}
	for(int j=2;j<=n;j<<=1)
	{
		ldb ang=PI*2/j*(inv?-1:1);
		base mul(cos(ang),sin(ang));
		int block=n/j;
		for(int i=0;i<block;i++)
		{
			base cur(1,0);
			for(int k=i*j;k<i*j+j/2;k++)
			{
				base tmp=cur*a[k+j/2];
				a[k+j/2]=a[k]-tmp;a[k]+=tmp;
				cur=cur*mul;
			}
		}
	}
	if(inv) for(int i=0;i<n;i++) a[i]/=n;
}
char s[N],t[N];
int n,m,k;
int a[N],b[N],ans[N],sum[N];
base A[N],B[N];
void Build(char ch)
{
	for(int i=0;i<n;i++) a[i]=s[i]==ch,sum[i]=a[i];
	for(int i=1;i<n;i++) sum[i]+=sum[i-1];
	for(int i=0;i<n;i++) a[i]=sum[min(n-1,i+k)]-(i-k-1<0?0:sum[i-k-1]),a[i]=min(a[i],1);
	for(int i=0;i<m;i++) b[m-i-1]=t[i]==ch;
	//printf("%c\n",ch);
	//for(int i=0;i<n;i++) printf("%i ",a[i]);printf("\n");
	//for(int i=0;i<m;i++) printf("%i ",b[i]);printf("\n");
}
void Solve()
{
	int sz=1;while(sz<n) sz<<=1;sz<<=1;
	for(int i=n;i<sz;i++) a[i]=0;
	for(int i=m;i<sz;i++) b[i]=0;
	for(int i=0;i<sz;i++) A[i]=base(a[i],0),B[i]=base(b[i],0);
	fft(A,sz,0);fft(B,sz,0);
	for(int i=0;i<sz;i++) A[i]=A[i]*B[i];
	fft(A,sz,1);
	for(int i=m-1;i<m-1+n;i++) ans[i-m+1]+=round(A[i].real());
}
int main()
{
	scanf("%i %i %i %s %s",&n,&m,&k,s,t);
	Build('A');Solve();
	Build('G');Solve();
	Build('T');Solve();
	Build('C');Solve();
	int sol=0;
	for(int i=0;i<n;i++) sol+=ans[i]==m;
	printf("%i\n",sol);
	return 0;
}