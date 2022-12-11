#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cmath>
using namespace std;

typedef long long ll;
#define X first
#define Y second
#define mp make_pair

int main()
{	
	int n1, n2, k1, k2;
	cin >> n1 >> n2 >> k1 >> k2;
	if (n1 > n2)
		cout << "First";
	else
		cout << "Second";
	return 0;
}