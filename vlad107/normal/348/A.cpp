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

int n,a[500500];
long long l,r,s;

int main(){
	scanf("%d",&n);
	l=0;r=0;
	for (int i=0;i<n;i++){
		scanf("%d",&a[i]);
		r+=a[i];
	}
	r++;
	while (l<r-1){
		long long s=(l+r)/2;
		long long sb=0;
		for (int i=0;i<n;i++){
			if (s-a[i]<0){
				sb=-1;
				break;
			}
			sb+=s-a[i];
		}
		if (sb>=s)
			r=s;
		else l=s;
	}
	cout<<r;
}