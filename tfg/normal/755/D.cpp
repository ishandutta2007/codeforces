#include <iostream>
#include <cstdio>

const int ms=1001000;

int n, k;

int BIT[ms];

int qry(int x)
{
	int ans=0;
	for(;x>0;x-=x&-x)
		ans+=BIT[x];
	return ans;
}

int upd(int x)
{
	for(;x<ms;x+=x&-x)
		BIT[x]++;
}

int qry(int l, int r)
{
	//std::cout << "making qry(" << l << ", " << r << ")\n";
	if(l>n)
		return qry(l-n, r-n);
	if(r>n)
		return qry(l,n) + qry(0, r%n);
	else
		return qry(r) - qry(l-1);
}

int main()
{
	std::cin >> n >> k;
	int on=1;
	long long int cur=1;
	if(k+k>n)
		k=n-k;
	for(int i=0;i<n;i++)
	{
		int prev=1+(on-1-k+n)%n;
		int got=1+(qry(on+1,on+k-1)+qry(prev+1,prev+k-1));

		//std::cout << "on: " << on << '\n';
		//std::cout << "got = " << got << '\n';

		if(got==0)
			got=1;


		cur+=got;
		upd(on);
		on=1+(on-1+k)%n;
		if(i)
			printf(" ");
		printf("%lli",cur);

		//std::cout << '\n';
	}
	std::cout << '\n';
}