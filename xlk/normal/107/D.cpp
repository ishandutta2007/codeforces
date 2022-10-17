#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
int p=12345,k,l,d,z;
int q[30],r[30],v[130],a[130][130],b[130][130];
vector<int>f[30];
long long n;
char c;
void mul(int a[130][130],int b[130][130])
{
	int _[130][130]={};
	fr(i,l)fr(j,l)fr(k,l)
		_[i][j]+=a[i][k]*b[k][j]%p;
	fr(i,l)fr(j,l)
		a[i][j]=_[i][j]%p;
}
int main()
{
	scanf("%I64d%d",&n,&k);
	fr(i,26)
		r[i]=1;
	fr(i,k)
	{
		scanf(" %c%d",&c,&d),c-='A';
		r[c]*=d/__gcd(d,r[c]);
		f[c].push_back(d);
	}
	q[0]=1;
	fr(i,26)
		q[i+1]=q[i]*r[i];
	l=q[26];
	fr(i,l)
	{
		v[i]=1;
		fr(j,26)
			if(f[j].size())
			{
				b[i][i+q[j]-((i/q[j]+1)%r[j]==0?q[j+1]:0)]++;
				int w=0;
				for(int k:f[j])
					w|=i/q[j]%k==0;
				v[i]&=w;
			}
	}
	a[0][0]=1;
	for(;n;n>>=1,mul(b,b))
		if(n&1)
			mul(a,b);
	fr(i,l)
		if(v[i])
			z+=a[0][i];
	printf("%d\n",z%p);
}