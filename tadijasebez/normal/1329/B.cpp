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
const int L=30;
int main(){
	int t;
	scanf("%i",&t);
	while(t--){
		int n,m;
		scanf("%i %i",&n,&m);
		int mxb=0;
		for(int bt=0;bt<L;bt++)if(n>>bt&1)mxb=bt;
		int sum=1,dp=0;
		for(int bt=0;bt<=mxb;bt++){
			int num=(1<<bt);
			if(bt==mxb)num=(n%(1<<bt))+1;
			dp=(ll)sum*num%m;
			sum=(sum+dp)%m;
		}
		printf("%i\n",(sum-1+m)%m);
	}
	return 0;
}