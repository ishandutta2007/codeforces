#include<bits/stdc++.h>
using namespace std;
const int p=998244353;
int qow(int a,int n){
	int ans=1;
	for(;n;n>>=1){
		if(n&1)ans=((long long)ans*a)%p;
		a=((long long)a*a)%p;
	}
	return ans;
}
int inverse(int a){
	return qow(a,p-2);
}
int _;
int cnt[210000];
vector<int> e[210000];
vector<int> x[210000];
vector<int> y[210000];
int ans[210000];
int dfs(int i,int fa){
	int anss=1;
	for(int j=0;j<e[i].size();j++){
		if(e[i][j]==fa) continue;
		int pp[40];
        int vv[40];
		int tot=0;
		int xx=x[i][j];
		for(int o=2;o<=450;o++){
			if(xx%o==0){
				pp[++tot]=o;
				vv[tot]=0;
				for(;;){
					if(xx%o)break;
					xx/=o;
					vv[tot]++;
				}
				cnt[pp[tot]]+=vv[tot];
			}
		}
		if(xx>1){
			pp[++tot]=xx;
			vv[tot]=1;
			cnt[pp[tot]]+=vv[tot];
		}
		xx=y[i][j];
		for(int o=2;o<=450;o++){
			if(xx%o==0){
				pp[++tot]=o;
				vv[tot]=0;
				for(;;){
					if(xx%o)break;
					xx/=o;
					vv[tot]--;
				}
				cnt[pp[tot]]+=vv[tot];
			}
		}
		if(xx>1){
			pp[++tot]=xx;
			vv[tot]=-1;
			cnt[pp[tot]]+=vv[tot];
		}
		for(int o=1;o<=tot;o++)ans[pp[o]]=max(ans[pp[o]],cnt[pp[o]]);
		anss=(anss+dfs(e[i][j],i)*(((long long)inverse(x[i][j])*y[i][j])%p))%p;
		for(int o=1;o<=tot;o++)cnt[pp[o]]-=vv[o];
	}
	return anss;
}
int main(){
	scanf("%d",&_);
	while(_--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) cnt[i]=0;
		for(int i=1;i<=n;i++) ans[i]=0;
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<=n;i++) x[i].clear();
		for(int i=1;i<=n;i++) y[i].clear();
		for(int i=1;i<n;i++){
			int u,v,xx,yy;
			scanf("%d%d%d%d",&u,&v,&xx,&yy);
			e[u].push_back(v);
			x[u].push_back(xx);
			y[u].push_back(yy);
			e[v].push_back(u);
			x[v].push_back(yy);
			y[v].push_back(xx);
		}
		int anss=dfs(1,1);
		for(int i=1;i<=n;i++) anss=((long long)anss*qow(i,ans[i]))%p;
		printf("%d\n",anss);
	}
	return 0;
}