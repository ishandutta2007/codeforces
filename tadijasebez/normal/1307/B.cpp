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
		int n,x;
		scanf("%i %i",&n,&x);
		int mx=0;
		bool one=0;
		for(int i=1;i<=n;i++){
			int y;
			scanf("%i",&y);
			if(y==x)one=1;
			mx=max(mx,y);
		}
		if(one)printf("1\n");
		else{
			int ans=(x+mx-1)/mx;
			if(x<mx)ans=2;
			printf("%i\n",ans);
		}
	}
	return 0;
}