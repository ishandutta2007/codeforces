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
const int N=100005;
int n,m,fl[N];
int vis[N],op[N];
int S[N],dep[N];
vector<int> e[N];
void dfs_JUD(int x){
	++op[x];
	if (op[x]>1) return;
	vis[x]=1;
	for (auto i:e[x])
		if (!vis[i]) dfs_JUD(i);
	vis[x]=0;
}
bool JUD(int x){
	For(i,1,n) vis[i]=op[i]=0;
	dfs_JUD(x);
	For(i,1,n) if (op[i]!=1) return 0;
	return 1;
}
void jud_1(int x){
	vis[x]=1; op[x]=0;
	for (auto i:e[x])
		if (!vis[i]){
			dep[i]=dep[x]+1; jud_1(i);
			if (dep[op[i]]<dep[op[x]]) op[x]=op[i];
			S[x]+=S[i];
		}
		else{
			S[x]++,S[i]--;
			if (dep[i]<dep[op[x]]) op[x]=i;
		}
	vis[x]=0;
}
void jud_2(int x){
	vis[x]=1;
	if (S[x]==1) fl[x]|=fl[op[x]];
	for (auto i:e[x]) if (!vis[i]) jud_2(i);
	vis[x]=0;
}
int rnd(){
	int x=0;
	For(i,1,9) x=x*10+rand()%10;
	return x;
}
void solve(){
	scanf("%d%d",&n,&m);
	For(i,1,n) e[i].resize(0);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y);
	}
	For(i,1,n) fl[i]=0;
	int p=-1;
	For(i,1,200){
		int x=rnd()%n+1;
		if (JUD(x)){
			p=x;
			break;
		}
	}
	if (p==-1){
		cout<<-1<<endl;
		return;
	}
	fl[p]=1; dep[0]=1<<30;
	For(i,1,n) vis[i]=op[i]=S[i]=0;
	jud_1(p); jud_2(p);
	int sum=0;
	For(i,1,n) sum+=fl[i];
	if (sum*5<n) cout<<-1<<endl;
	else{
		For(i,1,n) if (fl[i]) cout<<i<<' ';
		cout<<endl;
	}
}
int main(){
	srand(time(NULL));
	int T;
	scanf("%d",&T);
	while (T--) solve();
}