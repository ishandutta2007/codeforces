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
const int N=8005;
int e[N][N],ind[N];
int vis[N],n;
ll ans;
void input(){
	static char s[N];
	For(i,1,n){
		scanf("%s",s+1);
		For(j,1,n/4){
			int p=j*4,v=(s[j]<='9'?s[j]-'0':s[j]-'A'+10);
			For(k,0,3) e[i][p]=(v&1),v>>=1,p--;
		}
	}
}
void init(){
	For(i,1,n) For(j,1,n)
		if (e[i][j]) ++ind[j];
	static int q[N];
	int h=0,t=0;
	For(i,1,n) if (!ind[i]) q[++t]=i;
	while (h!=t){
		int x=q[++h]; vis[x]=1;
		ans+=1ll*(n-h)*(1+614*n);
		For(i,1,n) if (e[x][i])
			if (!--ind[i]) q[++t]=i;
	}
	//cout<<ans<<endl;
}
void solve(int p){
	static int S[N];
	static int T[N];
	static int sum[N];
	S[++*S]=p;
	For(i,1,n)
		if (!vis[i]&&i!=p)
			if (e[i][p]) S[++*S]=i;
			else T[++*T]=i;
	For(i,1,*S) For(j,i+1,*S)
		if (e[S[j]][S[i]]) swap(S[j],S[i]);
	For(i,1,*T) For(j,i+1,*T)
		if (e[T[j]][T[i]]) swap(T[j],T[i]);
	memset(ind,0,sizeof(ind));
	For(i,1,*S) For(j,1,*T)
		if (e[T[j]][S[i]]) ++ind[S[i]];
	For(i,1,*S) For(j,1,*T)
		if (e[S[i]][T[j]]) ++ind[T[j]];
	ans+=3ll*(S[0]+T[0])*(S[0]+T[0]-1)/2;
	//cout<<ans<<' '<<S[0]<<' '<<T[0]<<' '<<S[1]<<' '<<S[2]<<' '<<T[1]<<endl;
	memset(sum,0,sizeof(sum));
	For(i,1,*S) ans+=sum[ind[S[i]]]++;
	memset(sum,0,sizeof(sum));
	For(i,1,*T) ans+=sum[ind[T[i]]]++;
}
int main(){
	scanf("%d",&n);
	input();
	init();
	int p=-1;
	For(i,1,n) if (!vis[i])
		if (p==-1||ind[i]>ind[p]) p=i;
	if (p!=-1) solve(p);
	printf("%lld\n",ans);
}