#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;

int main()
{
	ll n;
	cin >> n;
	cin >> n;
	int k = 0;
	while(((n >> k) & 1) == 0) k++;
	printf("%d\n", k + 1);
	//cin >> n;

	return 0;
}