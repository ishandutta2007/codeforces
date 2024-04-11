#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

const int N=100005;
const int mo=998244353;
vector<int> e[N];
int ans[N],n;
int dfs(int x,int fa,int v){
	int f1=1,f2=0;
	for (auto i:e[x])
		if (i!=fa){
			int S=dfs(i,x,v);
			if (!(S&2)) f1=0;
			if (S&1) ++f2;
		}
	if (f2%v==0) return 2*f1+1;
	if (f2%v==v-1) return 2*f1;
	return 0;
}
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		e[i].resize(0);
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	ans[1]=1;
	for (int i=1;i<n;i++)
		ans[1]=2*ans[1]%mo;
	for (int i=2;i<=n;i++)	
		if ((n-1)%i==0){
			int S=dfs(1,0,i);
			ans[i]=(S==3);
		}
		else ans[i]=0;
	for (int i=n;i>=1;i--)
		for (int j=i+i;j<=n;j+=i)
			ans[i]=(ans[i]+mo-ans[j])%mo;
	for (int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}