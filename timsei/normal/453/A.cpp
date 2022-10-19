#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 2e5 + 5;

int main(void) {
	int n , m;
	cin >> n >> m;
	swap(n , m);
	double ans = 0 , nn = n , mm = m;
	for(int i = 0;i < m;++ i) {
		ans += pow((mm - i) / (mm) , n) * (m - i) * (1 - pow((mm - i - 1) / (mm - i) , n));
	}
	printf("%.12lf" , ans);
}