#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
typedef long long LL;
const LL P = 1e9+7;
const int INF = 0x3fffffff;
const int N = 4e5+5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int T,n,m,gg,ss,bb,bbb,a[N],b[N];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>T;
	while(T--){
		scanf("%d",&n);
		rep(i,1,n) scanf("%d",a+i);
		a[0] = -1, b[0] = 0, m = 0;
		rep(i,1,n) if(a[i]!=a[i-1]){
			b[++m] = 1;
		}else{
			++b[m];
		}
		gg = ss = bb = bbb = 0;
		gg = b[1];
		int i=2;
		for(;i<=m;i++){
			ss += b[i];
			if(ss>gg) break;
		}
		i++;
		for(;i<=m;i++){
			bb += b[i];
			if(bb>gg && gg+ss+bb<=n/2){
				bbb = bb;
			}
		}
		if(bbb){
			printf("%d %d %d\n",gg,ss,bbb);
		}else printf("0 0 0\n");
	}
	return 0;
}