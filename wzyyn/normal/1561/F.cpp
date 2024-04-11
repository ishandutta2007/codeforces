#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

const int N=400005;
const int mo=998244353;
int t[N],fac[N],inv[N];
void change(int k,int v){
	for (;k<N;k+=k&(-k)) t[k]+=v;
}
int ask(int k){
	int s=0;
	for (;k;k-=k&(-k)) s+=t[k];
	return s;
}
int find(int v){
	int x=0;
	for (int p=1<<18;p;p>>=1)
		if (p+x<N&&t[x+p]<v)
			x+=p,v-=t[x];
	return x+1;
}
void init(){
	for (int i=1;i<N;i++)
		change(i,1);
	fac[0]=inv[0]=inv[1]=1;
	for (int i=2;i<N;i++)
		inv[i]=1ll*inv[mo%i]*(mo-mo/i)%mo;
	for (int i=1;i<N;i++)
		inv[i]=1ll*inv[i-1]*inv[i]%mo;
	for (int i=1;i<N;i++)
		fac[i]=1ll*fac[i-1]*i%mo;
}
int C(int x,int y){
	if (x<0||y<0||y>x) return 0;
	return 1ll*fac[x]*inv[y]%mo*inv[x-y]%mo;
}
int n,m;
int x[N],y[N];
int p1[N],p2[N],vis[N];
void solve(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) scanf("%d%d",&x[i],&y[i]);
	int s=n-1;
	for (int i=m;i>=1;i--){
		p1[i]=find(y[i]);
		p2[i]=find(y[i]+1);
		if (!vis[p2[i]]) --s;
		change(p1[i],-1);
		vis[p2[i]]=1;
	}
	for (int i=1;i<=m;i++){
		vis[p2[i]]=0;
		change(p1[i],1);
	}
	/*n+1*/
	//cout<<s<<endl;
	printf("%d\n",C(n+s,s));
}
int main(){
	init();
	int T;
	scanf("%d",&T);
	while (T--) solve(); 
}