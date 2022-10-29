#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(int argc, char** argv) {
	long long n,k;
	cin >> n >> k;
	if(n/k&1) puts("YES");
	else puts("NO");
	return 0;
}