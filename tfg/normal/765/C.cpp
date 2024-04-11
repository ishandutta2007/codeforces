#include <iostream>
#include <algorithm>

typedef long long ll;

ll k, a, b;

int main()
{
	std::cin >> k >> a >> b;
	if(a<b)
		std::swap(a, b);
	bool valid=true;
	ll ans=0;
	if(a<k && b<k)
		valid=false;
	else if(a%k!=0 && b<k)
		valid=false;
	else
		ans=a/k+b/k;
	if(!valid)
		ans=-1;
	std::cout << ans << '\n';
}