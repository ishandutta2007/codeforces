#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
using namespace std;

const int N=200005;
vector<int> e[N];
int n,ans;
int dfs(int x,int fa){
	if (e[x].size()==1&&x!=1)
		return 1;
	vector<int> v;
	for (auto i:e[x])
		if (i!=fa) v.PB(dfs(i,x));
	sort(v.begin(),v.end());
	if (v.size()>=2){
		if (x==1){
			ans=max(ans,v.back());
			ans=max(ans,v[v.size()-2]+1);
		}
		else
			ans=max(ans,v.back()+1);
	}
	ans=max(ans,v[0]);
	return v[0]+1;
}
void solve(){
	ans=0;
	scanf("%d",&n);
	For(i,1,n) e[i].resize(0);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y);
		e[y].PB(x); 
	}
	dfs(1,0); 
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}