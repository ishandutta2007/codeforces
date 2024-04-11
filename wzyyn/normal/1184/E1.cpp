#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int N=1000005;
struct edge{
	int x,y,v;
	bool operator <(const edge &a)const{
		return v<a.v;
	}
}e[N];
int fa[N],n,m,px,py,pv,ans; 
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
int main(){
	scanf("%d%d%d%d%d",&n,&m,&px,&py,&pv);
	For(i,2,m) scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].v);
	For(i,1,n) fa[i]=i;
	sort(e+2,e+m+1);
	ans=1000000000;
	For(i,2,m){
		fa[get(e[i].x)]=get(e[i].y);
		if (get(px)==get(py)){
			ans=e[i].v;
			break;
		}
	}
	printf("%d\n",ans);
}