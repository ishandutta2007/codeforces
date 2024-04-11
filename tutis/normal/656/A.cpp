#include <bits/stdc++.h>
using namespace std;
int main()
{
	int64_t N;
	cin >> N;
	int64_t D[36];
	D[0] = 1;
	D[1] = 2;
	for (int i = 2; i <= 11; i++)
		D[i] = 2 * D[i - 1];
	D[12] = 4096;
	D[13] = 8092;
	for (int i = 14; i < 36; i++)
		D[i] = 2 * D[i - 1];
	for (int i = 0; i < 36; ++i)
	{
		//cout<<D[i]<<" ";
	}
	cout << D[N];
}