#include <stdio.h>
#define ll long long
const int mod=1e9+9;
int pow(int x, int k)
{
	int ret=1;
	for(;k;k>>=1,x=(ll)x*x%mod) if(k&1) ret=(ll)ret*x%mod;
	return ret;
}
int inv(int x){ return pow(x,mod-2);}
const int N=100050;
char s[N];
int main()
{
	int n,k,a,b,i;
	scanf("%i %i %i %i",&n,&a,&b,&k);
	scanf("%s",s);
	int sum=0;
	for(i=0;i<k;i++)
	{
		int add=(ll)pow(a,n-i)*pow(b,i)%mod;
		if(s[i]=='+')
		{
			sum+=add;
			if(sum>=mod) sum-=mod;
		}
		else
		{
			sum-=add;
			if(sum<0) sum+=mod;
		}
	}
	int x=(ll)inv(a)*b%mod;
	x=pow(x,k);
	int po=(n+1)/k;
	if(x==1) return printf("%i\n",(ll)sum*po%mod),0;
	int sol=(ll)pow(x,po);
	sol--;if(sol<0) sol+=mod;
	sol=(ll)sol*inv(x-1)%mod;
	printf("%i\n",(ll)sol*sum%mod);
	return 0;
}