#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;
	if (n <= 4)
		cout << "No solution" << endl;
	else
	{
		double alpha = 2 * M_PI / n;

		cout << fixed << setprecision(6);
		double x = 0, y = 0;
		for (int i = 1; i <= n - 2; i++)
		{
			cout << x << " " << y << endl;

			double l = 500;
			l += 0.01 * i;
			x += l * cos(alpha * i), y += l * sin(alpha * i);
		}
		cout << x << " " << y << endl;
		x -= y / sin(alpha * (n - 1)) * cos(alpha * (n - 1)), y = 0;
		cout << x << " " << y << endl;
	}

	return 0;
}