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
	int n;
	scanf("%i",&n);
	map<int,ll> cnt;
	for(int i=1;i<=n;i++){
		int x;scanf("%i",&x);
		cnt[x-i]+=x;
	}
	ll ans=0;
	for(auto it:cnt)ans=max(ans,it.second);
	printf("%lld\n",ans);
	return 0;
}