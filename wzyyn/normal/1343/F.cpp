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

const int N=205;
int n,vis[N][N],deg[N];
int Deg[N],q[N],del[N],found;

void dfs(int dep,int fir){
	//cout<<"D "<<dep<<' '<<fir<<endl; 
	if (found) return;
	if (dep==1){
		q[1]=fir;
		found=1;
		return;
	}
	q[dep]=fir;
	int pos=-1;
	For(i,1,n-1)
		if (!del[i]&&vis[i][fir]) pos=i;
	if (pos==-1) return;
	int qq[5],top=0;
	del[pos]=1;
	For(i,1,n) if (vis[pos][i])
		if ((--Deg[i])==(dep==2?0:1)&&i!=fir) qq[++top]=i;
	if (top==2){
		int d1=deg[qq[1]]-Deg[qq[1]];
		int d2=deg[qq[2]]-Deg[qq[2]];
		if (d1<d2) swap(d1,d2),swap(qq[1],qq[2]);
		if (d1!=d2) --top;
	} 
	For(i,1,top){
		dfs(dep-1,qq[i]);
		if (found) break;
	}
	del[pos]=0;
	For(i,1,n) if (vis[pos][i]) ++Deg[i];
}
bool check(int fir){
	found=0;
	memcpy(Deg,deg,sizeof(deg));
	memset(del,0,sizeof(del));
	dfs(n,fir);
	if (found){
		//printf("ANS=");
		For(i,1,n) printf("%d ",q[i]);
		puts("");
	}
	return found;
}
void solve(){
	scanf("%d",&n);
	memset(vis,0,sizeof(vis));
	memset(deg,0,sizeof(deg));
	For(i,1,n-1){
		int cnt,x;
		scanf("%d",&cnt);
		For(j,1,cnt){
			scanf("%d",&x);
			vis[i][x]=1;
			++deg[x];
		}
	}
	For(i,1,n)
		if (deg[i]==1)
			if (check(i)) return;
	assert(0);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
/*
1 
5
2 4 5
3 1 4 5
3 1 3 5
5 1 2 3 4 5 
*/