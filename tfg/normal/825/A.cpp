#include <iostream>
#include <string>

int main()
{
	int n;
	std::string str;
	std::cin >> n >> str;
	long long ans = 0;
	for(int on = 0; on < str.size(); on++)
	{
		int l = on;
		while(on < n && str[on] == '1')
			on++;
		ans = 10 * ans + (on - l);
	}
	if(str[n - 1] == '0')
		ans *= 10;
	std::cout << ans << "\n";
}