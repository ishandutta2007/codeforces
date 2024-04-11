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
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ldb double
template<typename T>void ckmn(T &a,T b){a=min(a,b);}
template<typename T>void ckmx(T &a,T b){a=max(a,b);}
const int N=3550;
int a[N];
void Run(){
	int n,m,k;
	scanf("%i %i %i",&n,&m,&k);
	for(int i=1;i<=n;i++)scanf("%i",&a[i]);
	m--;k=min(k,m);
	int len=n-m,ans=0;
	for(int fir=0;fir<=k;fir++){
		int las=k-fir,mn=1e9;
		for(int st=fir+1;st+len-1<n-las+1;st++){
			ckmn(mn,max(a[st],a[st+len-1]));
		}
		ckmx(ans,mn);
	}
	printf("%i\n",ans);
}
int main(){
	int t;
	scanf("%i",&t);
	while(t--)Run();
	return 0;
}