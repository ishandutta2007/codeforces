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
const int mo=1000000007;
const int N=65,M=(1<<14)+5;
int C[N][N],n,a[N],vis[N];
int deg[N],e[N][N],bit[N];
int cnt[M],f[N][M];
vector<int> S,T;
void init(){
	For(i,0,N-1) C[i][0]=1;
	For(i,1,N-1) For(j,1,i)
		C[i][j]=(C[i-1][j]+C[i-1][j-1])%mo;
}
void dfs(int x){
	vis[x]=1;
	deg[x]?T.PB(x):S.PB(x);
	For(i,1,n) if (e[x][i]&&!vis[i]) dfs(i);
}
int F(vector<int> S,vector<int> T){
	assert(S.size()<=15);
	int n=S.size(),m=T.size();
	For(i,0,m-1) bit[i]=0;
	For(i,0,m-1) For(j,0,n-1)
		if (a[T[i]]%a[S[j]]==0) bit[i]|=1<<j;
	For(i,0,(1<<n)-1) cnt[i]=0;
	For(i,0,(1<<n)-1) For(j,0,m-1)
		if ((bit[j]&i)==bit[j]) ++cnt[i];
	For(i,0,m) For(j,0,(1<<n)-1) f[i][j]=0;
	For(i,0,m-1) f[1][bit[i]]++;
	For(i,1,m-1) For(j,0,(1<<n)-1){
		For(k,0,m-1)
			if ((j&bit[k])&&(j&bit[k])!=bit[k])
				f[i+1][j|bit[k]]=(f[i+1][j|bit[k]]+f[i][j])%mo;
		f[i+1][j]=(f[i+1][j]+1ll*f[i][j]*(cnt[j]-i))%mo;
	}
	return f[m][(1<<n)-1];
}
int main(){
	init();
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	For(i,1,n) For(j,i+1,n)
		if (a[j]%a[i]==0){
			++deg[j];
			e[i][j]=e[j][i]=1;
		}
	int ans=1,cnt=0;
	For(i,1,n) if (!vis[i]){
		S.resize(0);
		T.resize(0);
		dfs(i);
		//cout<<S.size()<<' '<<T.size()<<endl;
		if (!T.empty()){
			int sz=T.size()-1;
			ans=1ll*ans*F(S,T)%mo;
			ans=1ll*ans*C[cnt+sz][sz]%mo;
			cnt+=sz;
		}
	}
	printf("%d\n",ans);
}