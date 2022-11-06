#include<stdio.h>
#include<set>
int gcd(int a, int b){return b?gcd(b, a%b):a; }
int in[1000001], n, a, b;
long long tmp[1000001];
std::set<int> primes;
void addP(int x)
{
	for(int i=2; x>1 && i <= x/i; i++)
	{
		if(x%i == 0)
		{
			primes.insert(i);
			while(x%i==0) x/=i;
		}
	}
	if(x!=1) primes.insert(x);
}
long long solve(int P)
{
	long long ans = 0, t=0;
	int i, j, i1, j1;
	for(i=1; i<=n && in[i]%P == 0; i++);
	for(j=n; j>=1 && in[j]%P == 0; j--);
	if(i>j) return 0;
	ans = 1ll*a*(j-i+1);

	int cb = 0;
	long long sa = 0, sb = 0;
	for(i=1; i<=n; i++)
	{
		if(in[i]%P == 1 || in[i]%P == P-1) cb++;
		else if(in[i]%P != 0) break;
		if(-1ll*b*cb+1ll*a*i > sa) sa = -1ll*b*cb+1ll*a*i;
	}
	if(i==n+1)
	{
		cb = 0; sa = 0;
		for(i=1; i<=n; i++)
		{
			if(in[i]%P == 1 || in[i]%P == P-1) cb++;
			if(-1ll*b*cb+1ll*a*i > sa) sa = -1ll*b*cb+1ll*a*i;
			tmp[i] = sa;
		}
		cb = 0;
		t = 0;
		for(j=n; j>=1; j--)
		{
			if(in[j]%P == 1 || in[j]%P == P-1) cb++;
			else if(in[j]%P != 0) break;
			if(-1ll*b*cb+1ll*a*(n-j+1) > sb) sb = -1ll*b*cb+1ll*a*(n-j+1);
			if(tmp[j-1] + sb > t) t = tmp[j-1] + sb;
		}
		t = 1ll*n*a - t;
		if(ans > t) return t;
		else return ans;
	}

	cb = 0;
	for(j=n; j>=1; j--)
	{
		if(in[j]%P == 1 || in[j]%P == P-1) cb++;
		else if(in[j]%P != 0) break;
		if(-1ll*b*cb+1ll*a*(n-j+1) > sb) sb = -1ll*b*cb+1ll*a*(n-j+1);
	}

	t = 1ll*n*a - sa - sb;

	if(ans > t) return t;
	return ans;
}
int main()
{
	int i;
	scanf("%d%d%d", &n, &a, &b);
	for(i=1; i<=n; i++) scanf("%d", in+i);
	addP(in[1]);addP(in[1]-1);addP(in[1]+1);
	addP(in[n]);addP(in[n]-1);addP(in[n]+1);
	long long min = 1000000000000000000ll;
	for(int p: primes)
	{
		long long t = solve(p);
		if(min > t) min = t;
	}
	printf("%lld", min);
	return 0;
}