#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 1e9+7;
const int N = 300010;

int p[N], id[N], a[N*5], b[N*5], cnt=0, x, n;

void myswap(int i, int j){
	a[++cnt]=i;
	b[cnt]=j;
	swap(p[i],p[j]);
	swap(id[p[i]],id[p[j]]);
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&p[i]),id[p[i]]=i;
	rep(i,1,n/2-1){
		x = n/2+1-i;
		if(id[x]<=n/2){
			myswap(id[x],n);
			myswap(n,x);
		}else{
			myswap(id[x],1);
			myswap(1,n);
			myswap(n,x); 
		}
		x = n/2+i;
		if(id[x]<=n/2){
			myswap(id[x],n);
			myswap(n,1);
			myswap(1,x);
		}else{
			myswap(id[x],1);
			myswap(1,x);
		}
	}
	if(p[1]!=1)myswap(1,n);
	printf("%d\n",cnt);
	rep(i,1,cnt){
		printf("%d %d\n",a[i],b[i]);
	}
	return 0;
}