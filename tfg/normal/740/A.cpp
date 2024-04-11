#include <iostream>

long long int n, a, b, c;

const long long int INF = 0x3f3f3f3f3f3f3fLL;

long long int bruteforce(long long int cost, int books, int ind)
{
	if((books+n)%4==0)
		return cost;
	if(ind>=10)
		return INF;
	long long int ans=std::min(bruteforce(cost+a,books+1,ind+1),bruteforce(cost+b,books+2,ind+1));
	ans=std::min(bruteforce(cost+c,books+3,ind+1),ans);
	return ans;
}

int main()
{
	std::cin >> n >> a >> b >> c;
	std::cout << bruteforce(0,0,0) << '\n';
}