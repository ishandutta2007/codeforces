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
const int N=1000050;
int a[N],b[N];
int main(){
	int n,m;
	scanf("%i %i",&n,&m);
	int sum=0;
	for(int i=1;i<=m;i++){
		scanf("%i",&a[i]);
		b[i]=n-a[i]+1;
	}
	for(int i=m-1;i>=1;i--)b[i]=min(b[i+1]-1,b[i]);
	if(b[1]<=0)return 0*printf("-1\n");
	a[0]=1;for(int i=1;i<=m;i++)b[i]=min(b[i-1]+a[i-1],b[i]);
	if(b[m]!=n-a[m]+1)return 0*printf("-1\n");
	for(int i=1;i<=m;i++)printf("%i ",b[i]);
	return 0;
}