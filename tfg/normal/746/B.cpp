#include <iostream>
#include <string>

std::string str;
int n;

char ans[200200];

int main()
{
	std::cin >> n >> str;
	int left, right;
	int on;
	if(n%2==1)
	{
		ans[n/2]=str[0];
		left=n/2-1;
		right=n/2+1;
		on=1;
	}
	else
	{
		left=n/2-1;
		right=n/2;
		on=0;
	}
	while(on<n)
	{
		ans[left]=str[on];
		ans[right]=str[on+1];
		//std::cout << "(" << left << ',' << right << "), (" << on << ',' << on+1 << ")\n";


		left--;
		right++;
		on+=2;
	}
	for(int i=0;i<n;i++)
		std::cout << ans[i];
	std::cout << '\n';
}