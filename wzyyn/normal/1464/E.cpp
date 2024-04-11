#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
using namespace std;

const int N=100005;
const int M=515;
int n,m;
vector<int> e[N];
int ind[N],vis[N],q[N],sg[N];
void topo(){
	int h=0,t=0;
	For(i,1,n) if (!ind[i]) q[++t]=i;
	while (h!=t){
		int x=q[++h];
		for (auto i:e[x]) if (!--ind[i]) q[++t]=i;
	}
	Rep(i,t,1){
		int x=q[i];
		for (auto j:e[x]) vis[sg[j]]=1;
		for (;vis[sg[x]];++sg[x]);
		for (auto j:e[x]) vis[sg[j]]=0;
	}
}
const int mo=998244353;
int t[555][555];
int tab[555];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); ++ind[y];
	}
	topo();
	For(i,1,n) ++tab[sg[i]];
	m=511;
	For(i,0,m){
		For(j,0,m) t[i][i^j]=1ll*tab[j]*power(n+1,mo-2)%mo;
		t[i][m+1]=(i==0?0:power(n+1,mo-2));
	}
	For(i,0,m){
		t[i][m+1]=mo-t[i][m+1];
		t[i][i]=(mo-1+t[i][i])%mo;
	}
	For(i,0,m){
		int p=-1;
		For(j,i,m) if (t[j][i]) p=j;
		if (p!=i) For(j,i,m+1) swap(t[i][j],t[p][j]);
		int inv=power(t[i][i],mo-2);
		For(j,i,m+1) t[i][j]=1ll*t[i][j]*inv%mo;
		For(j,0,m) if (j!=i)
			Rep(k,m+1,i) t[j][k]=(t[j][k]+mo-1ll*t[j][i]*t[i][k]%mo)%mo;
	}
	cout<<t[0][m+1]<<endl;
}
/*
3,2:0
4:1
5:2
1:0
*/