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
const int N=100005;
struct edge{
	int to,next;
	ll v;
};
edge e[N*4];
int head[N],tot;
int vis[N],q[N],ans,n,m;
ll tag[N],a[65],sum,s;
void insert(ll x){
	if (!x) return;
	sum|=x;
	Rep(i,59,0)
		if (x&(1ll<<i))
			if (!a[i]) a[i]=x,x=0,s++;
			else x^=a[i]; 
}
void add(int x,int y,ll v){
	e[++tot]=(edge){y,head[x],v};
	head[x]=tot;
}
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
void dfs(int x,int fa){
	q[++*q]=x; vis[x]=1;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa){
			//cout<<x<<' '<<e[i].to<<endl;
			if (!vis[e[i].to]){
				tag[e[i].to]=tag[x]^e[i].v;
				dfs(e[i].to,x);
			}
			else
				insert(tag[x]^tag[e[i].to]^e[i].v);
		}
}
void solve(int x){
	memset(a,0,sizeof(a));
	*q=sum=s=0; dfs(x,0);
	static int cnt[65][2];
	memset(cnt,0,sizeof(cnt));
	For(i,1,*q) For(j,0,59)
		cnt[j][(tag[q[i]]>>j)&1]++;
	//s/=2;
	//cout<<s<<' '<<sum<<endl;
	For(i,0,59){
		int ss=0;
		if (sum&(1ll<<i)) ss=1ll*(*q)*((*q)-1)%mo*(mo+1)/4%mo;
		else ss=1ll*cnt[i][0]*cnt[i][1]%mo;
		//cout<<i<<' '<<ss<<' '<<sum<<' '<<s<<endl;
		ans=(ans+1ll*power(2,s)*ss%mo*((1ll<<i)%mo))%mo;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m){
		int x,y; ll v;
		scanf("%d%d%lld",&x,&y,&v);
		add(x,y,v); add(y,x,v);
	}
	For(i,1,n) if (!vis[i]) solve(i);
	printf("%d\n",ans);
}