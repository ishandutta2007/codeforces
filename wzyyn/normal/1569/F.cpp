#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
using namespace std;
int n,m,k,e[20][20];
long long A[20],ans;
int vi[20],ex[20],ey[20],msk[20];
unordered_map<long long,int> mp;
void Update(int d,int x){
	//cout<<"Update "<<d<<' '<<x<<endl;
	if (d==n/2){
		long long hsh=0;
		for (int i=1;i<=n;i++) hsh=hsh*10+msk[i];
		if (!mp.count(hsh)){
			long long re=1;
			for (int i=1;i<=x;i++)
				re=1ll*re*(k-i+1);
			ans+=re;
			mp[hsh]=1;
		}
		return;
	}
	for (int i=1;i<=x+1;i++){
		msk[ex[d]]=msk[ey[d]]=i;
		Update(d+1,max(i,x));
	}
}
bool Check(){
	static bool f[64][6];
	memset(f,0,sizeof(f));
	int p=n/2;
	for (int i=0;i<p;i++)
		if (e[ex[i]][ey[i]])
			f[1<<i][i]=1;
	for (int i=1;i<1<<p;i++)
		for (int j=0;j<p;j++)
			if ((i&(1<<j))&&f[i][j])
				for (int k=0;k<p;k++)
					if (!(i&(1<<k))){
						if (e[ex[j]][ey[k]]&&e[ey[j]][ex[k]]) f[i|(1<<k)][k]=1;
						if (e[ex[j]][ex[k]]&&e[ey[j]][ey[k]]) f[i|(1<<k)][k]=1;
					}
	for (int i=0;i<p;i++)
		if (f[(1<<p)-1][i]) return 1;
	return 0;
}
void dfs(int x,int t){
	for (;vi[x];++x);
	//cout<<x<<' '<<t<<' '<<ex[0]<<' '<<ey[0]<<' '<<ex[1]<<' '<<ey[1]<<endl;
	if (x==n+1){
		if (Check())
			Update(0,0);
		return;
	}
	for (int i=x+1;i<=n;i++)
		if (!vi[i]){
			vi[x]=vi[i]=1;
			ex[t]=x; ey[t]=i;
			dfs(x+1,t+1);
			vi[x]=vi[i]=0;
		}
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x][y]=e[y][x]=1;
	}
	dfs(1,0);
	cout<<ans<<endl;
}