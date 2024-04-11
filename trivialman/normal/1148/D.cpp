#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 1e9+7;
const int N = 300010;

struct dat{
	int a,b,id;
}c[N];
int n, m, a[N], b[N];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	scanf("%d",&n);
	rep(i,1,n)scanf("%d%d",a+i,b+i),m+=(a[i]>b[i]);
	if(m>n/2){
		m=0;
		rep(i,1,n)if(a[i]>b[i])c[++m]={a[i],b[i],i};
		sort(c+1,c+m+1,[](dat x,dat y){return x.b<y.b;});
		printf("%d\n",m);
		rep(i,1,m)printf("%d ",c[i].id);
	}else{
		m=0;
		rep(i,1,n)if(a[i]<b[i])c[++m]={a[i],b[i],i};
		sort(c+1,c+m+1,[](dat x,dat y){return x.a>y.a;});
		printf("%d\n",m);
		rep(i,1,m)printf("%d ",c[i].id);
	}
	return 0;
}