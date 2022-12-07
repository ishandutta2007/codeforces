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
int n,ans,sz[N];
ll S,SS,q1[N*20],q2[N*20];
struct node{
	int x,v1,v2;
};
vector<node> e[N];
void dfs(int x,int fa){
	sz[x]=(e[x].size()==1&&x!=1);
	for (auto i:e[x])
		if (i.x!=fa){
			dfs(i.x,x);
			SS+=1ll*i.v1*sz[i.x];
			sz[x]+=sz[i.x];
			for (int rem=i.v1;rem;rem/=2){
				if (i.v2==2) q2[++*q2]=sz[i.x]*1ll*(rem-rem/2);
				if (i.v2==1) q1[++*q1]=sz[i.x]*1ll*(rem-rem/2);
			}
		}
}
void solve(){
	*q1=*q2=ans=SS=0;
	scanf("%d%lld",&n,&S);
	For(i,1,n) e[i].resize(0);
	For(i,1,n-1){
		int x,y,v,v2;
		scanf("%d%d%d%d",&x,&y,&v,&v2);
		e[x].PB((node){y,v,v2});
		e[y].PB((node){x,v,v2});
	}
	dfs(1,0);
	sort(q1+1,q1+*q1+1);
	sort(q2+1,q2+*q2+1);
	ans=1<<30;
	int p1=0,p2=*q2,res=*q1;
	For(i,1,*q1) SS-=q1[i];
	for (;p1<=*q1;p1++){
		if (p1) SS+=q1[p1],--res;
		for (;p2&&SS>S;SS-=q2[p2--],res+=2);
		if (SS<=S) ans=min(ans,res);
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}