#include<cstdio>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define int long long
const int N=100005;
int n,a[N],d[N];
signed main(){
	scanf("%I64d",&n);
	rep(i,2,n){
		int u,v;scanf("%I64d%I64d",&u,&v); 
		++d[u],++d[v];
	}
	rep(i,1,n)if(d[i]==2){puts("NO");return 0;}
	puts("YES");
	return 0;
}