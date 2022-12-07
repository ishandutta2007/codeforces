#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=250005;
const int M=10000005;
vector<int> H[N],C[N];
int n,m,Q,top,t,sz[N];
int h[M],q[M],pr[M],su[M];
ll c[M],f[M]; 
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n){
		scanf("%d",&sz[i]);
		H[i].resize(sz[i]);
		C[i].resize(sz[i]);
		For(j,0,sz[i]-1) scanf("%d",&H[i][j]);
		For(j,0,sz[i]-1) scanf("%d",&C[i][j]);
	}
	scanf("%d",&Q);
	For(i,1,Q){
		int id,v;
		scanf("%d%d",&id,&v);
		For(j,0,sz[id]-1){
			h[++top]=H[id][j];
			c[top]=C[id][j]*1ll*v;
		}
	}
	//cout<<top<<endl;
	For(i,1,m){
		for (;t&&i>=q[t]+h[q[t]];--t)
			su[q[t]]=i-1;
		q[++t]=i;
	}
	for (;t;--t) su[q[t]]=m;
	Rep(i,m,1){
		for (;t&&i<=q[t]-h[q[t]];--t)
			pr[q[t]]=i+1;
		q[++t]=i;
	}
	for (;t;--t) pr[q[t]]=1;
	For(i,1,m){
		f[i]=f[pr[i]-1]+c[i];
		for (;t&&su[q[t]]<i;--t);
		if (t) f[i]=min(f[i],f[q[t]-1]+c[q[t]]);
		if (!t||f[i-1]+c[i]<f[q[t]-1]+c[q[t]]) q[++t]=i;
	}
	printf("%lld\n",f[m]);
}