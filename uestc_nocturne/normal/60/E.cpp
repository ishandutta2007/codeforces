#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
typedef __int64 LL;
LL P,a[20],p[20],q[20];
LL F(long long n)
{
	LL pr=2*P;
	if(n==0)return 0;
	a[1]=1;a[2]=1;a[3]=1;a[4]=0;
		p[1]=1;p[2]=0;p[3]=0;p[4]=1;
		while(n>0)
		{
			q[1]=p[1];q[2]=p[2];
			q[3]=p[3];q[4]=p[4];
			if(n%2==1)
			{p[1]=(q[1]*a[1]+q[2]*a[3])%pr;
			p[2]=(q[1]*a[2]+q[2]*a[4])%pr;
			p[3]=(q[3]*a[1]+q[4]*a[3])%pr;
			p[4]=(q[3]*a[2]+q[4]*a[4])%pr;}
			q[1]=a[1];q[2]=a[2];
			q[3]=a[3];q[4]=a[4];
			a[1]=(q[1]*q[1]+q[2]*q[3])%pr;
			a[2]=(q[1]*q[2]+q[2]*q[4])%pr;
			a[3]=(q[3]*q[1]+q[4]*q[3])%pr;
			a[4]=(q[3]*q[2]+q[4]*q[4])%pr;
			n=n/2;
		}
		return p[2];
}
LL A[1100000],x,y,D,sum;
int i,n;
int main()
{
	cin>>n>>x>>y>>P;
//	scanf("%d%I64d%I64d%I64d",&n,&x,&y,&P);
	sum=0;
	for(i=0;i<n;i++)
	{cin>>A[i];sum+=A[i];}
	sum*=2;sum=sum%(2*P);
	if(n==1){cout<<A[0]%P<<endl;return 0;}
	LL D=(A[0]+A[n-1])%(2*P);
	LL te=3,BS=1;
	LL EE=F(x+1),DD=F(x);
//	cout<<EE<<" "<<DD<<" ";
	while(x>0)
	{
		if(x%2==1)BS=(BS*te)%(2*P);
		te=(te*te)%(2*P);
		x/=2;
	}
	LL S=((((sum-D)*BS)%(2*P)+D+2*P)%(2*P));
//	cout<<S/2<<endl;
	D=(A[0]+((EE%(2*P))*A[n-1])%(2*P)+(DD*A[n-2])%(2*P))%(2*P);
	te=3,BS=1;
	while(y>0)
	{
		if(y%2==1)BS=(BS*te)%(2*P);
		te=(te*te)%(2*P);
		y/=2;
	}
	S=((((S-D)*BS)%(2*P)+D+2*P)%(2*P))/2;
	cout<<S<<endl;
}