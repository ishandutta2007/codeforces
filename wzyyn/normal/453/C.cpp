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
int n,m,fa[N],top;
int a[N],q[N*4],vis[N];
vector<int> e[N];
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
void getans(int x){
	vis[x]=1;
	for (auto i:e[x])
		if (!vis[i]){
			q[++top]=i; a[i]^=1;
			getans(i);
			q[++top]=x; a[x]^=1;
			if (a[i]){
				q[++top]=i; a[i]^=1;
				q[++top]=x; a[x]^=1;
			}
		}
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) fa[i]=i;
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
		fa[get(x)]=get(y);
	}
	int p=-1;
	For(i,1,n){
		scanf("%d",&a[i]);
		if (a[i]==1){
			int x=get(i);
			if (p==-1) p=x;
			else if (p!=x) return puts("-1"),0;
		}
	}
	if (p==-1) return puts("0"),0;
	q[++top]=p; a[p]^=1;
	getans(p);
	int l=1,r=top;
	if (a[p]) l++;
	printf("%d\n",r-l+1);
	For(i,l,r) printf("%d ",q[i]);
}