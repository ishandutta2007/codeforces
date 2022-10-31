#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stack>

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

const lli mod=1e9+7;
const lli inf=1000000000000000000ll+2;

int vis[1001];

lli mul(lli a,lli b) {
	if(a==inf || b==inf) return inf;
	else if(inf/b<a) return inf;
	else return a*b;
}
int main() {
	for(int i=2;i<=1000;i++) {
		if(!vis[i]) {
			for(int j=i*i;j<=1000;j+=i) vis[j]=1;
		}
	}
	lli n,k,r=1;
	scanf("%lld%lld",&n,&k);
	if(k>=n) {
		if(n==1 && k<=2) puts("Yes");
		else puts("No");
		return 0;
	}
	for(int i=2;i<=k && i<=1000;i++) {
		if(!vis[i]) {
			for(int j=i;j<=1000 && j<=k;j*=i) r=mul(r,i);
		}
	}
	
	if(r==inf || n%r!=r-1) puts("No");
	else puts("Yes");
	
	return 0;
}