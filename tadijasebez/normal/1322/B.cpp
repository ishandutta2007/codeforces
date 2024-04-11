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
const int N=400050;
const int M=10000050;
const int L=27;
int a[N];
struct BIT{
	static const int NSZ=10000050;
	int sum[NSZ],cnt;
	void init(int mx){for(int i=0;i<min(M,mx+10);i++)sum[i]=0;cnt=0;}
	void Set(int i,int f){cnt^=f;for(i++;i<NSZ;i+=i&-i)sum[i]^=f;}
	int Get(int i){i=min(i,M-5);int ans=0;for(i++;i;i-=i&-i)ans^=sum[i];return ans;}
}BT[2];
int ans;
void Solve(int mod,int bit,int n){
	BT[0].init(mod);
	BT[1].init(mod);
	int all=0;
	for(int i=1;i<=n;i++){
		if(a[i]>>bit&1){
			all^=BT[0].Get(mod-a[i]%mod-1);
			all^=BT[1].cnt^BT[1].Get(mod-a[i]%mod-1);
		}else{
			all^=BT[1].Get(mod-a[i]%mod-1);
			all^=BT[0].cnt^BT[0].Get(mod-a[i]%mod-1);
		}
		if(a[i]>>bit&1)BT[1].Set(a[i]%mod,1);
		else BT[0].Set(a[i]%mod,1);

	}
	if(all&1)ans+=mod;
}
int main(){
	int n;
	scanf("%i",&n);
	for(int i=1;i<=n;i++){
		scanf("%i",&a[i]);
	}
	for(int i=0;i<L;i++){
		Solve(1<<i,i,n);
	}
	printf("%i\n",ans);
	return 0;
}