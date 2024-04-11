#include <iostream>
#include <map>
#include <string>

std::string a[101];
std::map<std::string, int> freq;

int main()
{
	int n;
	std::cin >> n;
	for(int i=0;i<n;i++)
		std::cin >> a[i];
	int ans=0;
	for(int j=0;j<n;j++)
	{
		std::string now;
		for(int i=0;i<n;i++)
			now+=a[j][i];
		freq[now]++;
		ans=std::max(ans, freq[now]);
	}
	std::cout << ans << '\n';
}