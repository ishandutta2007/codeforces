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
const int M=1000005;
const int N=100005;
struct rect{
	int x,y,X,Y,v;
	bool operator <(const rect &a)const{
		return y<a.y;
	}
}a[N];
int n,m,k;
int t[M*3],tg[M*3];
vector<int> in[M],out[M];
set<pii> S;
void clear(int k){
	tg[k]=1; t[k]=0;
}
void pushdown(int k){
	if (!tg[k]) return;
	clear(k*2);
	clear(k*2+1);
	tg[k]=0;
}
void change(int k,int l,int r,int p,int v){
	t[k]=(t[k]+v)%mo;
	if (l==r) return;
	int mid=(l+r)/2;
	pushdown(k);
	if (p<=mid) change(k*2,l,mid,p,v);
	else change(k*2+1,mid+1,r,p,v);
}
void clear(int k,int l,int r,int x,int y){
	if (x<=l&&r<=y) return clear(k);
	int mid=(l+r)/2;
	pushdown(k);
	if (x<=mid) clear(k*2,l,mid,x,y);
	if (y>mid) clear(k*2+1,mid+1,r,x,y);
	t[k]=(t[k*2]+t[k*2+1])%mo;
}
int ask(int k,int l,int r,int x,int y){
	if (l==x&&r==y) return t[k];
	int mid=(l+r)/2;
	pushdown(k);
	if (y<=mid) return ask(k*2,l,mid,x,y);
	if (x>mid) return ask(k*2+1,mid+1,r,x,y);
	return (ask(k*2,l,mid,x,mid)+ask(k*2+1,mid+1,r,mid+1,y))%mo;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	For(i,1,k) scanf("%d%d%d%d",&a[i].x,&a[i].y,&a[i].X,&a[i].Y);
	sort(a+1,a+k+1);
	For(i,1,k){
		in[a[i].x].PB(i);
		out[a[i].X+1].PB(i);
	}
	S.insert(pii(0,0));
	For(i,1,n){
		for (auto j:in[i]){
			int id=S.lower_bound(pii(-a[j].Y-1,0))->se;
			if ((!id||a[id].Y+1<=a[j].Y)&&a[j].Y!=m)
				a[j].v=ask(1,1,m,a[id].Y+1,a[j].Y);
			//cout<<j<<' '<<a[j].y<<' '<<a[j].v<<endl;
		}
		for (auto j:in[i]){
			S.insert(pii(-a[j].y,j));
			S.insert(pii(-a[j].Y,j));
			clear(1,1,m,a[j].y,a[j].Y);
			if (a[j].v) change(1,1,m,a[j].Y+1,a[j].v);
		}
		for (auto j:out[i]){
			S.erase(pii(-a[j].y,j));
			S.erase(pii(-a[j].Y,j));
		}
		if (i==1)
			change(1,1,m,1,1);
	}
	int pr=-(S.lower_bound(pii(-m,0)))->fi;
	//cout<<pr<<endl;
	printf("%d\n",ask(1,1,m,pr+1,m));
}