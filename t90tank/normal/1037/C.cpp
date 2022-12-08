// ConsoleApplication2.cpp :  "main" 
//

//#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std; 

char a[3000000], b[3000000]; 
int  f[3000000]; 

int main()
{
	int n;
	scanf("%d", &n); 
	scanf("%s%s", a + 1, b + 1);
	f[0] = 0; f[1] = (a[1] != b[1]);
	for (int i = 2; i <= n; ++i) {
		f[i] = f[i - 1] + (a[i] != b[i]);
		if (a[i] != a[i - 1] && a[i] == b[i - 1] && a[i - 1] == b[i])
			f[i] = min(f[i], f[i - 2] + 1); 
	}
	cout << f[n] << endl; 
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