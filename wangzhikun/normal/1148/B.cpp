#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define debug(x) cerr<<#x<<'='<<x<<endl
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

ll n,m,a,b,k,A[200010],B[200010];
ll ans = -1;
int main() {
	read(n);read(m);read(a);read(b);read(k);
	for(int i=1;i<=n;i++) read(A[i]);
	for(int i=1;i<=m;i++) read(B[i]);
	int p = 0;
	if(k>=n)ans = 1e18;
	for(int i=1;i<=n;i++){
		while(p<=m && A[i]+a>B[p]){
			p++;
		}
		if(i-1>k)continue;
		//cout<<i<<' '<<p+k-(i-1)<<endl;
		ans = max(ans,B[p+k-(i-1)]);
		if(p+k-i+1>m)ans = 1e18;
	}
	if(ans == 1e18){
		cout<<-1<<endl;
	}else{
		cout<<ans+b<<endl;
	}
	return 0;
}