#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define double long double
using namespace std;

const int N=100005;
int n,m;
vector<int> v[N];
int vi[N],ans[N];
void solve(){
	scanf("%d%d",&n,&m);
	For(i,1,m){
		v[i].resize(0);
		int k,x;
		scanf("%d",&k);
		for (;k;--k){
			scanf("%d",&x);
			v[i].push_back(x);
		}
	}
	For(i,1,n) vi[i]=0;
	For(i,1,m)
		if (v[i].size()==1){
			ans[i]=v[i][0];
			++vi[v[i][0]];
		}
	
	For(i,1,m)
		if (v[i].size()!=1){
			int p=v[i][0];
			for (auto j:v[i])
				if (vi[j]<vi[p]) p=j;
			ans[i]=p; ++vi[p];
		}
	
	For(i,1,n)
		if (vi[i]*2>m+1)
			return puts("NO"),void(0);
	puts("YES");
	For(i,1,m) printf("%d ",ans[i]);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}