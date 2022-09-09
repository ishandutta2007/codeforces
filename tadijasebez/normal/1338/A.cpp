#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <complex>
#include <iostream>
#include <cctype>
#include <cstring>
#include <bitset>
#include <stack>
#include <functional>
#include <cassert>
#include <tuple>
#include <iomanip>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt make_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}

int main(){
	int t;
	scanf("%i",&t);
	while(t--){
		int n;
		scanf("%i",&n);
		vector<int> a(n+1),b(n+1);
		for(int i=1;i<=n;i++)scanf("%i",&a[i]);
		b[1]=a[1];for(int i=2;i<=n;i++)b[i]=max(a[i],b[i-1]);
		int mx=0;
		for(int i=1;i<=n;i++)ckmx(mx,b[i]-a[i]);
		int cnt=0;
		while(mx>0)cnt++,mx>>=1;
		printf("%i\n",cnt);
	}
	return 0;
}