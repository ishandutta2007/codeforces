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
const int N=200005;
int n,m;
int fa[N],fl[N];
struct edge{
	int x,y,v;
	bool operator <(const edge &a)const{
		return v>a.v;
	}
}e[N];
ll ans;
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
bool merge(int x,int y){
	x=get(x); y=get(y);
	if (x==y){
		if (fl[x]) return 0;
		return fl[x]=1;
	}
	else{
		if (fl[x]&fl[y]) return 0;
		fa[y]=x; fl[x]|=fl[y];
		return 1;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) fa[i]=i;
	For(i,1,m) scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].v);
	sort(e+1,e+m+1);
	For(i,1,m)
		if (merge(e[i].x,e[i].y))
			ans+=e[i].v;
	cout<<ans<<endl;
}