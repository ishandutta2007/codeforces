#include <iostream>
#include <string>

int n, a, b;

std::string str;

int main()
{
	std::cin >> n >> a >> b >> str;
	a--;b--;
	int ans=n;
	if(str[a]==str[b])
		ans=0;
	else
		ans=1;
	std::cout << ans << '\n';
}