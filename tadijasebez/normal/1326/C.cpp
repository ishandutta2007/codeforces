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
const int mod=998244353;
int add(int a, int b){ a+=b;return a>=mod?a-mod:a;}
void ckadd(int &a, int b){ a=add(a,b);}
int sub(int a, int b){ a-=b;return a<0?a+mod:a;}
void cksub(int &a, int b){ a=sub(a,b);}
int mul(int a, int b){ return (ll)a*b%mod;}
void ckmul(int &a, int b){ a=mul(a,b);}
int powmod(int x, int k){ int ans=1;for(;k;k>>=1,ckmul(x,x)) if(k&1) ckmul(ans,x);return ans;}
int inv(int x){ return powmod(x,mod-2);}
int main(){
	int n,k;
	scanf("%i %i",&n,&k);
	int las=-1,ans=1;
	ll sum=0;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%i",&x);
		if(x>=n-k+1){
			if(las!=-1)ckmul(ans,i-las);
			las=i;
			sum+=x;
		}
	}
	printf("%lld %i\n",sum,ans);
	return 0;
}