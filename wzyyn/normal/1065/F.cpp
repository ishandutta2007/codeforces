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
const int N=1000005;
int n,k,D,q[N],S[N],sz[N],ans;
vector<int> e[N];
void dfs1(int x){
	q[++*q]=x;
	if (!e[x].size()){
		++S[x]; ++sz[x];
		if (*q>k) --S[q[*q-k]];
	}
	for (auto i:e[x]){
		dfs1(i);
		S[x]+=S[i];
		if (S[i]){
			sz[x]+=sz[i];
			sz[i]=0;
		}
	}
	--*q;
}
void dfs2(int x,int s){
	ans=max(ans,s+=sz[x]);
	for (auto i:e[x]) dfs2(i,s);
}
int main(){
	scanf("%d%d",&n,&k);
	For(i,2,n){
		int x;
		scanf("%d",&x);
		e[x].PB(i);
	}
	dfs1(1);
	dfs2(1,0);
	cout<<ans<<endl;
}