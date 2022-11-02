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

#define N 500500

using namespace std;

int n,a[N];
long long res,sum;

long long gcd(long long a,long long b){
	while ((a>0)&&(b>0))
		if (a>b)a%=b;else b%=a;
	return a+b;
}

int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++)scanf("%d",&a[i]);
	sort(a,a+n);
	res=0;sum=0;
	for (int i=0;i<n;i++){
		res+=(long long)(a[i])*(i+1)-sum;
		sum+=a[i];
	}
	res=res*2-sum;
	long long d=gcd(res,(long long)n);
	printf("%I64d %I64d\n",res/d,n/d);
}