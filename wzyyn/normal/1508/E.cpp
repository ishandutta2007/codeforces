#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;


const int N=300005;
int n,a[N],b[N],fa[N];
int q[N],q2[N],vis[N];
int dfn[N],dep[N],inq[N];
vector<int> e[N];


bool cmp(int x,int y){
	return a[x]<a[y];
}
bool cmp2(int x,int y){
	return dep[x]<dep[y];
}
void dfs(int x){
	dfn[x]=++*dfn;
	for (auto i:e[x]){
		dep[i]=dep[x]+1;
		dfs(i);
	}
	inq[++*inq]=x;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); fa[y]=x;
	}
	for (int i=1;i<=n;i++)
		sort(e[i].begin(),e[i].end(),cmp);
	dfs(1);
	long long round=0;
	for (int i=1;i<=n;i++)
		if (a[i]<a[1]) round+=dep[i];
	
	int p=0;
	for (;p<=n&&round>=dep[inq[p+1]];p++)
		round-=dep[inq[p+1]];
	/*for (int i=1;i<=n;i++) printf("%d ",dfn[i]);
	puts("");
	for (int i=1;i<=n;i++) printf("%d ",inq[i]);
	puts("");
	cout<<p<<' '<<round<<endl;*/
	for (int i=1;i<=p;i++)
		for (int j=inq[i];j&&!vis[j];j=fa[j])
			vis[j]=1;
	
	memcpy(b,dfn,sizeof(b));
	for (int i=1;i<=n;i++)
		if (vis[i]&&b[i]>p) q[++*q]=b[i];
	for (int i=1;i<=n;i++)
		if (vis[i]) b[i]=0;
	for (int i=1;i<=p;i++)
		b[inq[i]]=i;
	for (int i=1;i<=n;i++)
		if (!b[i]) q2[++*q2]=i;
	sort(q+1,q+*q+1);
	sort(q2+1,q2+*q2+1,cmp2);
	assert(*q==*q2);
	for (int i=1;i<=*q;i++)
		b[q2[i]]=q[i];
	
	int x=1;
	for (;round;--round){
		int y=-1;
		for (auto i:e[x])
			if (b[i]>b[x]&&(y==-1||b[i]<b[y]))
				y=i;
		assert(y!=-1);
		swap(b[y],b[x]);
		x=y;
	}
	
	for (int i=1;i<=n;i++)
		if (a[i]!=b[i]){
			puts("NO");
			return 0;
		}
	
	puts("YES");
	round=0;
	for (int i=1;i<=n;i++)
		if (a[i]<a[1])
			round+=dep[i];
	printf("%lld\n",round);
	for (int i=1;i<=n;i++)
		printf("%d ",dfn[i]);
}