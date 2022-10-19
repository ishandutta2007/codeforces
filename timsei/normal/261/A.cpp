#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm> 
using namespace std;

const int N = 1e5 + 5;

int a[N] , Cost[N] , n , m;
long long ans;

bool cmp(int x , int y) {
	return x > y;
}

int main(void) {
	scanf("%d" , &n);
	for(int i = 1;i <= n;++ i) scanf("%d" , &a[i]);
	sort(a + 1 , a + n + 1);
	int now = a[1] , ans = 0;
	scanf("%d" , &m);
	for(int i = 1;i <= m;++ i) scanf("%d" ,&Cost[i]);
	n = m;
	sort(Cost + 1 , Cost + n + 1 , cmp);
	int i = 1;
	while(i <= n) {
		int j = i;
		for(;j - i + 1 <= now && j <= n;++ j) ans += Cost[j];
		i = j + 2;
	}
	cout << ans;
}