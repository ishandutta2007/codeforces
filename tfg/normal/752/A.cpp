#include <iostream>

int main()
{
	int n, m, k;
	std::cin >> n >> m >> k;
	int r, c;
	char where;
	if(k&1)
		where='L';
	else
		where='R';
	k=(k-1)/2;
	r=k/m;
	c=k%m;
	r++;c++;
	std::cout << r << ' ' << c << ' ' << where << '\n';	
}