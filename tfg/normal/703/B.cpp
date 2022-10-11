#include <cstdio>

int n, k;
long long int c[100100];
bool cap[100100];
long long int sum=0;
long long int sumcap=0;
long long int ans=0;

int main()
{
	scanf("%i %i", &n, &k);
	for(int i=0; i<n; i++)
	{
		scanf("%lli", &c[i]);
		sum+=c[i];
	}
	for(int i=0; i<n; i++)
	{
		ans +=  c[i] * c[(i+1)%n];
		//printf("new ans=%lli\n", ans);
	}
	for(int i=0; i<k; i++)
	{
		int temp;
		scanf("%i", &temp);
		temp--;
		int othersum=sum-sumcap-c[(temp-1+n)%n]-c[temp]-c[(temp+1)%n];
		if(cap[(temp-1+n)%n]) othersum += c[(temp-1+n)%n];
		if(cap[(temp+1)%n]) othersum += c[(temp+1)%n];
		sumcap+=c[temp];
		cap[temp]=true;
		ans+=c[temp]*othersum;
		//printf("new ans=%lli\n", ans);
	}
	printf("%lli", ans);
}