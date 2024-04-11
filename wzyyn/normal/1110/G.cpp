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
const int N=2000005;
int n,nd,co[N],q[N];
vector<int> e[N];
char s[N]; 
void dfs(int x,int c){
	co[x]=c;
	for (auto i:e[x])
		if (co[i]==-1) dfs(i,c^1);
}
void solve(){
	scanf("%d",&n); nd=n;
	For(i,1,4*n) e[i].clear();
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	scanf("%s",s+1);
	For(i,1,n) if (s[i]=='W'){
		e[i].PB(++nd); e[nd].PB(i);
		e[nd+1].PB(nd); e[nd].PB(nd+1);
		e[nd+2].PB(nd); e[nd].PB(nd+2);
		nd+=2; 
	}
	For(i,1,nd)
		if (e[i].size()>=4)
			return puts("White"),void(0);
	*q=0;
	For(i,1,nd)
		if (e[i].size()==3){
			int cnt=0;
			For(j,0,2) cnt+=(e[e[i][j]].size()>1);
			if (cnt>=2) return puts("White"),void(0);
			q[++*q]=i;
		}
	//cout<<*q<<' '<<q[1]<<' '<<q[2]<<endl;
	if (*q<=1) return puts("Draw"),void(0);
	assert(*q==2);
	For(i,1,nd) co[i]=-1;
	dfs(q[1],0);
	puts(co[q[2]]?"Draw":"White");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}