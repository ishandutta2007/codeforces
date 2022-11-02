#include <math.h>
#include <limits.h>
#include <complex>
#include <string>
#include <functional>
#include <iterator>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <complex.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

#define mp make_pair
#define pb push_back
#define INF 1000000000

using namespace std;

int n,m,g,a[500500];

int gcd(int a,int b){
	while ((a>0)&&(b>0))
		if (a>b)a%=b;else b%=a;
	return a+b;
}

int main(){
	scanf("%d",&n);
	m=0;g=0;
	for (int i=0;i<n;i++){
		scanf("%d",&a[i]);
		m=max(m,a[i]);
		g=gcd(g,a[i]);
	}
	if ((m/g-n)%2==0)
		puts("Bob");
	else puts("Alice");
}