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
const int N=605;
int n,in[N],out[N];
int idS[N],idT[N];
int a[N][N],f[N],m,mo;
vector<int> e[N];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int Det(int n){
	For(i,1,n) For(j,1,n) a[i][j]%=mo;
	//For(i,1,n) For(j,1,n)
	//	printf("%d%c",a[i][j],j==n?'\n':' ');
	int ans=1;
	For(i,1,n){
		int p=-1;
		For(j,i,n) if (a[j][i]) p=j;
		if (p==-1) return 0;
		if (p!=i){
			ans=mo-ans;
			For(j,1,n) swap(a[i][j],a[p][j]);
		}
		ans=1ll*ans*a[i][i]%mo;
		int v=power(a[i][i],mo-2);
		For(j,i+1,n){
			int val=1ll*(mo-v)*a[j][i]%mo;
			For(k,i,n) a[j][k]=(a[j][k]+1ll*val*a[i][k])%mo;
		}
	}
	return ans;
}
int dfs(int x){
	if (f[x]!=-1) return f[x];
	f[x]=0;
	for (auto i:e[x]) f[x]=(f[x]+dfs(i))%mo;
	return f[x];
}
void check(int id){
	//cout<<id<<endl;
	For(i,1,n) f[i]=(i==id?1:-1);
	For(i,1,n) if (!out[i]) a[idS[id]][idT[i]]=dfs(i);
}
int main(){
	scanf("%d%d%d",&n,&m,&mo);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		out[x]++; in[y]++;
		e[y].PB(x);
	}
	For(i,1,n) if (!in[i]) idS[i]=++*idS;
	For(i,1,n) if (!out[i]) idT[i]=++*idT;
	For(i,1,n)
		if (!in[i]&&!out[i])
			a[idS[i]][idT[i]]=1;
		else if (!in[i]) check(i);
	printf("%d\n",Det(*idS));
}