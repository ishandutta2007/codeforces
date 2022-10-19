#include<bits/stdc++.h>
using namespace std;
const int N=1000005,M=6005,sz=200;
int n,m,c,p[N],q[N],a[N],b[N],z[M][M],s[M][M],x;
int f(int z){return (z-1+x)%n+1;}
int sol(int h,int v)
{
	int ans=s[h/sz][v/sz];
	for(int i=h/sz*sz;i<h;i++)
		if(b[i]<v)
			ans++;
	for(int i=v/sz*sz;i<v;i++)
		if(a[i]<h/sz*sz)
			ans++;
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&p[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&q[i]);
	for(int i=0;i<n;i++)
		a[p[i]]=i;
	for(int i=0;i<n;i++)
		b[a[q[i]]]=i;
	for(int i=0;i<n;i++)
		a[b[i]]=i;
	for(int i=0;i<n;i++)
		z[i/sz][b[i]/sz]++;
	for(int i=0;i<M-1;i++)
		for(int j=0;j<M-1;j++)
			s[i+1][j+1]=s[i+1][j]+s[i][j+1]-s[i][j]+z[i][j];
	scanf("%d",&m);
	while(m--)
	{
		int l1,r1,l2,r2;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		l1=f(l1),r1=f(r1),l2=f(l2),r2=f(r2);
		l1--,r1--,l2--,r2--;
		if(l1>r1)
			swap(l1,r1);
		if(l2>r2)
			swap(l2,r2);
		x=sol(r1+1,r2+1)-sol(l1,r2+1)-sol(r1+1,l2)+sol(l1,l2);
		printf("%d\n",x);
		x++;
	}
	return 0;
}