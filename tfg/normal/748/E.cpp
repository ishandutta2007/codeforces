#include <cstdio>

typedef long long int ll;

const int ms=10001000;
//const int ms=100;

ll a[ms];
ll b[ms];

int main()
{
	int n, k;
	scanf("%i %i",&n,&k);
	ll total=0;
	for(int i=0;i<n;i++)
	{
		ll temp;
		scanf("%lli",&temp);
		a[temp]++;
		total+=temp;
	}
	if(total<k)
	{
		printf("-1\n");
		return 0;
	}
	total=0;
	for(int i=ms-1;total<k;i--)
	{
		total+=a[i];
		total-=b[i];

		a[i/2]+=a[i];
		a[(i+1)/2]+=a[i];
		b[(i+1)/2]+=a[i];

		if(total>=k)
			printf("%i\n",i);
	}

}