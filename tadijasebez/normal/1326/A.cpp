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
	int t;scanf("%i",&t);
	while(t--){
		int n;
		scanf("%i",&n);
		if(n==1)printf("-1\n");
		else{
			if(((n-1)*2)%3==0){
				for(int i=1;i<=n-2;i++)printf("2");
				printf("33\n");
			}else{
				for(int i=1;i<=n-1;i++)printf("2");
				printf("3\n");
			}
		}
	}
	return 0;
}