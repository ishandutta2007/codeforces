// ConsoleApplication2.cpp :  "main" 
//


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std; 

int a[300000]; 

int main()
{
	int n, s; 
	scanf("%d%d", &n, &s); 
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	sort(a, a + n);
	long long ans = 0;
	for (int i = 0; i < n / 2; ++i) ans += max(0, a[i] - s);
	for (int i = 0; i < n / 2; ++i) ans += max(0, s - a[n-1-i]);
	ans += max(a[n / 2] - s, s - a[n / 2]); 
	cout << ans << endl; 
}

// : Ctrl + F5  >()
// : F5  >

// : 
//   1. /
//   2. 
//   3. 
//   4. 
//   5. >>
//   6. >> .sln 