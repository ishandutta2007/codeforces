#include <bits/stdc++.h>
class a
{
public:
	int a;
};
using namespace std;
int main()
{
	bool a, b, c, d;
	cin >> a >> b >> c >> d;
	int k = a + b * 2 + c * 4 + d * 8;
	int M[16];
	M[0] = 0;
	M[1] = 1;
	M[2] = 0;
	M[3] = 1;
	M[4] = 0;

	M[5] = 0;

	M[6] = 0;
	M[7] = 1;
	M[8] = 1;

	M[9] = 1;
	M[10] = 0;
	M[11] = 0;
	M[12] = 1;
	M[13] = 1;
	M[14] = 0;
	M[15] = 1;

	if (M[k] == -1)
		return -1;
	cout << M[k];
	return 0;
}