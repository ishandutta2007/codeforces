#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#include <cmath>
#include <stack>
#include <iostream>
#include <cstring>

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

const int mod=1e9+7;

int n,k;
int cc[1001];
lli cache[1001][1001][2];
char str[100001];

lli DP(int idx,int k,int f) {
	if(k<0) return 0;
	else if(idx==n) {
		return k==0 ? 1 : 0;
	}

	lli &ret=cache[idx][k][f];
	if(ret!=-1) return ret;


	if(f==0) {
		if(str[idx]=='0') ret=DP(idx+1,k,0);
		else {
			ret = (DP(idx+1,k-1,0) + DP(idx+1,k,1))%mod;
		}
	}
	else {
		ret = (DP(idx+1,k-1,1) + DP(idx+1,k,1))%mod;
	}
	return ret;
}

int main() {
	scanf("%s%d",str,&k);
	n=strlen(str);

	int mx=0;
	for(int i=0;i<n;i++) {
		mx = mx*2+str[i]-'0';
		mx=min(mx,1000);
	}

	for(int i=2;i<=1000;i++) {
		int val=i,c=0;
		while(val) {
			if(val&1)c++;
			val>>=1;
		}
		cc[i]=cc[c]+1;
	}
	
	memset(cache,-1,sizeof(cache));

	lli res=0;
	if(k==0) {
		res = 1;
	}
	else {
		for(int i=1;i<=n;i++) {
			if(cc[i]+1 == k) {
				res = (res + DP(0,i,0))%mod;
				if(i==1) res=(res-1+mod)%mod;
			}
		}
	}
	printf("%lld\n",res);
	
	return 0;
}