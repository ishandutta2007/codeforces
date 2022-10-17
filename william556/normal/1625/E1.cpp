#include<bits/stdc++.h>
using namespace std;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
const int N=3e5+5;
int n,q;
char s[N];
int fa[N],tot;
int lp[N],rp[N];
vector<int> e[N];
int lid[N],rid[N];
int rk[N];
long long f[N],sum[N],sum1[N];
void dfs(int x){
	long long res=0;
	for(int i=0;i<e[x].size();i++){
		int y=e[x][i];
		rk[y]=i+1;
		dfs(y);
		f[x]+=f[y];
		sum1[y]=res;
		res+=f[y];
		sum[y]=res;
	}
	int l=e[x].size();
	f[x]+=1ll*l*(l-1)/2+1;
	lid[lp[x]]=x,rid[rp[x]]=x;
}
int main(){
	n=in(),q=in();
	scanf("%s",s+1);
	tot=1;
	for(int i=1,p=1;i<=n;i++){
		if(s[i]=='('){
			fa[++tot]=p;
			e[p].push_back(tot);
			p=tot,lp[p]=i;
		}else{
			if(p!=1)rp[p]=i,p=fa[p];
		}
	}
	dfs(1);
	while(q--){
		int t=in(),l=in(),r=in();
		l=lid[l],r=rid[r];
		long long ans=sum[r]-sum1[l];
		int x=rk[r]-rk[l]+1;
		ans+=1ll*x*(x-1)/2;
		printf("%lld\n",ans);
	}
	return 0;
}