#include<stdio.h>
#include<iostream>
using namespace std;
int l,n,f[4000020],a[4000020],b[4000020],p=51123987;
long long z,w;
char s[4000020];
int main()
{
	scanf("%d",&l),n=l+l+1;
	for(int i=1;i<=l;i++)
		scanf(" %c",s+i+i);
	for(int i=1,j=0,k;i<=n;i+=k,j=max(1,j-k))
	{
		while(j<i&&i+j<=n&&s[i-j]==s[i+j])
			j++;
		f[i]=j;
		for(k=1;k<f[i]&&f[i]-k!=f[i-k];k++)
			f[i+k]=min(f[i-k],f[i]-k);
    }
    for(int i=1;i<=n;i++)
    {
		a[(i-f[i])/2+1]++,a[i/2+1]--;
		b[(i+1)/2]++,b[(i+f[i])/2]--;
		z+=f[i]/2;
	}
	for(int i=1;i<=l;i++)
		a[i]+=a[i-1],b[i]+=b[i-1];
	z%=p;
	z=z*(z-1)/2%p;
	for(int i=1;i<=l;i++)
	{
		z=(z-w*a[i])%p;
		w=(w+b[i])%p;
	}
	printf("%d\n",(z+p)%p);
}