#include<cstdio>
#include<iostream>

using namespace std;

long long p,q;
long long a[100];

long long gcd(long long a,long long b)
{
	if(a==0&&b==0) return 1;
	if(b==0) return a;
	if(a<b) return gcd(b,a);
	return gcd(b,a%b);
}

bool change(int id)
{
	if(q>(1ll<<62)/a[id]) return false;
	long long tmp=q*a[id];
	if(p-tmp<=0) return false;
	long long nq=p-tmp,np=q;
	p=np,q=nq;
	long long d=gcd(p,q);
	p/=d,q/=d;
	return true;
}

int main()
{
	cin>>p>>q;
	int N;
	cin>>N;
	for(int i=0;i<N;i++) cin>>a[i];
	for(int i=0;i<N-1;i++)
	{
		bool ok=change(i);
		if(ok==false)
		{
			printf("NO\n");
			return 0;
		}
	}
	if(q<=(1ll<<62/a[N-1])&&p==q*a[N-1]) printf("YES\n");
	else printf("NO\n");
	return 0;
}