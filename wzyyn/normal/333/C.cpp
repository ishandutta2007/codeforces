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
int k,m,T,a[10],vis[20005];
set<int> solve(int l,int r){
	set<int> ans;
	if (l==r){
		ans.insert(-a[l]);
		ans.insert(a[l]);
		return ans;
	}
	For(m,l,r-1){
		set<int> a=solve(l,m);
		set<int> b=solve(m+1,r);
		for (auto i:a) for (auto j:b){
			ans.insert(i+j);
			ans.insert(i-j);
			ans.insert(i*j);
		}
	}
	return ans;
}
void dfs(int x){
	if (x==5){
		set<int> tmp=solve(1,4);
		++T;
		for (auto i:tmp) if (abs(k-i)<10000){
			if (vis[abs(k-i)]==T) continue;
			vis[abs(k-i)]=T;
			printf("%04d%d%d%d%d\n",abs(k-i),a[1],a[2],a[3],a[4]);
			if (!(--m)) exit(0);
		}
		return;
	}
	for (a[x]=0;a[x]<=9;++a[x]) dfs(x+1);
}
int main(){
	scanf("%d%d",&k,&m);
	dfs(1);
}