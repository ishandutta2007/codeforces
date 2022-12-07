#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm> 
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
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
using namespace std;
const int N=1000005;
int n,Q,v[N],t[N*4],ans[N];
vector<pii> vec[N];
pii a[N];
void change(int k,int l,int r,int p,int v){
	//printf("%d %d %d\n",l,r,p);
	t[k]+=v;
	if (l==r) return;
	int mid=(l+r)/2;
	if (p<=mid) change(k*2,l,mid,p,v);
	else change(k*2+1,mid+1,r,p,v);
}
int ask(int k,int l,int r,int v){
	if (l==r) return l;
	int mid=(l+r)/2;
	if (t[k*2]<v) return ask(k*2+1,mid+1,r,v-t[k*2]);
	return ask(k*2,l,mid,v);
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&v[i]);
	For(i,1,n) a[i]=pii(v[i],-i);
	sort(a+1,a+n+1,greater<pii>());
	scanf("%d",&Q);
	For(i,1,Q){
		int x,y;
		scanf("%d%d",&x,&y);
		vec[x].PB(pii(y,i));
	}
	For(i,1,n){
		change(1,1,n,-a[i].se,1);
		//printf("%d\n",i);
		For(j,0,vec[i].size()-1)
			ans[vec[i][j].se]=v[ask(1,1,n,vec[i][j].fi)];
	}
	For(i,1,Q)
		printf("%d\n",ans[i]);
}