#include<iostream>
using namespace std;
int g[4020][4020];
long long n,m,a,b,c,d,s,z,p=1000000007;
int main()
{
	cin>>n>>m,n++,m++;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(i&&j)
				g[i][j]=i>j?g[i-j][j]:g[i][j-i];
			else
				g[i][j]=i+j;
	s=n*m%p;
	z=s*(s-1)%p*(s-2)%p;
	a=(n>>1)*(m>>1);
	b=(n+1>>1)*(m>>1);
	c=(n>>1)*(m+1>>1);
	d=(n+1>>1)*(m+1>>1);
	z-=6*a*b%p*c%p;
	z-=6*b*c%p*d%p;
	z-=6*c*d%p*a%p;
	z-=6*d*a%p*b%p;
	z-=((n-1)*(n-2)+(m-1)*(m-2))%p*s%p;
	z%=p;
	for(int i=1;i<n;i++)
		for(int j=1;j<m;j++)
			if(i||j)
				z=(z-(g[i][j]-1)*(n-i)*(m-j)*12)%p;
	cout<<(z+p)%p;
	return 0;
}