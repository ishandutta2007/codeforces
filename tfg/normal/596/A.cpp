#include <iostream>

int x[4], y[4];

int main()
{
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++)
		std::cin >> x[i] >> y[i];
	int xx[2], yy[2];
	for(int i = 0; i < n; i++)
	{
		if(i == 0 || x[i] < xx[0])
			xx[0] = x[i];
		if(i == 0 || x[i] > xx[1])
			xx[1] = x[i];
		if(i == 0 || y[i] < yy[0])
			yy[0] = y[i];
		if(i == 0 || y[i] > yy[1])
			yy[1] = y[i];
	}
	if(yy[0] != yy[1] && xx[0] != xx[1])
		std::cout << (xx[1] - xx[0]) * (yy[1] - yy[0]) << '\n';
	else
		std::cout << "-1\n";
}