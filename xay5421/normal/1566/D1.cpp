// author: xay5421
// created: Sun Sep 12 22:53:50 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long LL;
const int N=305;
int T,n,m,a[N],id[N],pos[N],t[N];
void upd(int k1,int k2){
	for(int i=k1;i<=m;i+=i&-i)t[i]+=k2;
}
int qry(int k1){
	int k2=0;
	for(int i=k1;i;i&=i-1)k2+=t[i];
	return k2;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		rep(i,1,m)scanf("%d",&a[i]),id[i]=i;
		sort(id+1,id+1+m,[&](int x,int y){return a[x]^a[y]?a[x]<a[y]:x>y;});
		rep(i,1,m){
			pos[id[i]]=i;
		}
		rep(i,1,m)t[i]=0;
		LL ans=0;
		rep(i,1,m){
			ans+=qry(pos[i]);
			upd(pos[i],1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}