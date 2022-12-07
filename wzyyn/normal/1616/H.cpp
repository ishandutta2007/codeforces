#include<bits/stdc++.h>

using namespace std;

const int mo=998244353;
const int N=150005;
int n,x,d,ans;
int a[N],vp[N];
void init(){
	vp[0]=1;
	for (int i=1;i<N;i++)
		vp[i]=1ll*vp[i-1]*2%mo;
}
int sz[N*32];
int ch[N*32][2];
int nd;
void insert(int &k,int v,int d){
	if (!k) k=++nd;
	++sz[k];
	if (!d) return;
	insert(ch[k][(v&d?1:0)],v,d>>1);
}
int solve(int k1,int k2,int d){
	//cout<<k1<<' '<<k2<<' '<<d<<endl;
	if (!k1||!k2) return 0;
	if (!d) return 1ll*(vp[sz[k1]]-1)*(vp[sz[k2]]-1)%mo;
	if (!(x&d)) return (solve(ch[k1][0],ch[k2][0],d>>1)+solve(ch[k1][1],ch[k2][1],d>>1))%mo;
	int v1=solve(ch[k1][0],ch[k2][1],d>>1);
	int v2=solve(ch[k2][0],ch[k1][1],d>>1);
	int re=1ll*v1*v2%mo;
	re=(re+1ll*v1*(vp[sz[ch[k2][0]]]+vp[sz[ch[k1][1]]]-1))%mo;
	re=(re+1ll*v2*(vp[sz[ch[k1][0]]]+vp[sz[ch[k2][1]]]-1))%mo;
	re=(re+1ll*(vp[sz[ch[k1][0]]]-1)*(vp[sz[ch[k2][0]]]-1))%mo;
	re=(re+1ll*(vp[sz[ch[k1][1]]]-1)*(vp[sz[ch[k2][1]]]-1))%mo;
	return re;
}
void solve(int l,int r){
	int rt=0;
	if (d==1){
		ans=(ans+vp[r-l+1]-1)%mo;
		return;
	}
	for (;nd;--nd) sz[nd]=ch[nd][0]=ch[nd][1]=0;
	for (int i=l;i<=r;i++) insert(rt,a[i]&(d-1),d>>1);
	ans=(ans+vp[sz[ch[rt][0]]]-1)%mo;
	ans=(ans+vp[sz[ch[rt][1]]]-1)%mo;
	ans=(ans+solve(ch[rt][0],ch[rt][1],d>>2))%mo;
	//cout<<l<<' '<<r<<' '<<ans<<endl;
}
int main(){
	init();
	scanf("%d%d",&n,&x);
	for (d=1;d<=x;d<<=1);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int l=1;
	for (int i=2;i<=n+1;i++)
		if (i==n+1||(a[i]/d)!=(a[i-1]/d))
			solve(l,i-1),l=i;
	cout<<ans<<endl;
}