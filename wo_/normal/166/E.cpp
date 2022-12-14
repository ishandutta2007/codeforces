#include<cstdio>
#include<algorithm>

using namespace std;

const long long mod=1e9+7;

long long bpow(int n)
{
	if(n==0)
	{
		return 1;
	}
	long long res=bpow(n/2)*bpow(n/2);
	res%=mod;
	if(n%2==1)
	{
		res*=3;
	}
	res%=mod;
	return res;
}

int main()
{
	int n;
	scanf("%d",&n);
	long long ans=bpow(n-1);
	if(n%2==0) ans++;
	else ans--;
	long long r=0;
	for(int i=0;;i++)
	{
		if((ans+mod*i)%4==0)
		{
			r=(ans+mod*i)/4;
			break;
		}
	}
	r*=3;
	r%=mod;
	printf("%d\n",(int)r);
	return 0;
}