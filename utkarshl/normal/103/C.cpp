#include"cstdio"
using namespace std;
int main()
{
	long long n,k,p;
	scanf("%I64d%I64d%I64d",&n,&k,&p);
	while(p--)
	{
		long long x;
		scanf("%I64d",&x);
		char ans;
		if(k==0)ans='.';
		else if (k==n)ans='X';
		else if (2*k>n)
		{
			if(x<=2*(n-k))
			{
				ans=(x%2==0)?'X':'.';
			}
			else ans='X';
		}
		else
		{
			long long excess_dots =n-k-k;
			if(excess_dots%2!=0)
			{	
				if(x<=excess_dots+1)ans='.';
				else 	if(x!=n) ans=(x%2==0)?'X':'.';
					else ans='X';
			}
			else
			{
				if(x<=excess_dots)ans='.';
				else ans=(x%2==0)?'X':'.';
			}
		}
		printf("%c",ans);
	}
}