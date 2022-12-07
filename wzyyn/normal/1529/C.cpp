#include<bits/stdc++.h>
using namespace std;

const int N=100005;
int n;
int l[N],r[N];
vector<int> e[N];
long long f[N][2];

void dfs(int x,int fa){
	f[x][0]=f[x][1]=0;
	for (auto i:e[x])
		if (i!=fa){
			dfs(i,x);
			f[x][0]+=max(f[i][0]+abs(l[i]-l[x]),f[i][1]+abs(r[i]-l[x]));
			f[x][1]+=max(f[i][0]+abs(l[i]-r[x]),f[i][1]+abs(r[i]-r[x]));
		}
}
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&l[i],&r[i]);
	for (int i=1;i<=n;i++)
		e[i].resize(0);
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(1,0);
	cout<<max(f[1][0],f[1][1])<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}