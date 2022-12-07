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
int n,k,d,pre[N];
int a[N],b[N],q1[N],q2[N];
int tg[N*4],t[N*4];
map<int,int> mp;
pii ans;
void SP(){
	int l=0,S=0,s=1;
	For(i,2,n+1)
		if (i==n+1||a[i]!=a[i-1]){
			if (s>S) S=s,l=i-S;
			s=1;
		}
		else ++s;
	printf("%d %d\n",l,l+S-1);
	exit(0);
}

void build(int k,int l,int r){
	tg[k]=0; t[k]=1;
	if (l==r) return;
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
}
void pushdown(int k){
	if (!tg[k]) return;
	tg[k*2]+=tg[k]; tg[k*2+1]+=tg[k];
	t[k*2]+=tg[k]; t[k*2+1]+=tg[k];
	tg[k]=0;
}
void change(int k,int l,int r,int x,int y,int v){
	if (x<=l&&r<=y){
		tg[k]+=v,t[k]+=v;
		return;
	}
	pushdown(k);
	int mid=(l+r)/2;
	if (x<=mid) change(k*2,l,mid,x,y,v);
	if (y>mid) change(k*2+1,mid+1,r,x,y,v);
	t[k]=min(t[k*2],t[k*2+1]);
}
int ask(int k,int l,int r,int x,int y){
	if (x<=l&&r<=y) return t[k];
	pushdown(k);
	int mid=(l+r)/2;
	if (y<=mid) return ask(k*2,l,mid,x,y);
	if (x>mid) return ask(k*2+1,mid+1,r,x,y);
	return min(ask(k*2,l,mid,x,mid),ask(k*2+1,mid+1,r,mid+1,y));
}
void solve(int l,int r){
	//cout<<l<<' '<<r<<endl;
	mp.clear();
	pre[l-1]=0;
	For(i,l,r){
		if (!mp[a[i]]) pre[i]=l-1;
		else pre[i]=mp[a[i]];
		pre[i]=max(pre[i],pre[i-1]);
		mp[a[i]]=i;
	}
	build(1,l,r);
	int t1=0,t2=0;
	q1[t1]=q2[t2]=l-1;
	For(i,l,r){
		//cout<<i<<endl;
		for (;t1&&a[q1[t1]]>=a[i];--t1)
			change(1,l,r,q1[t1-1]+1,q1[t1],a[q1[t1]]-a[i]);
		for (;t2&&a[q2[t2]]<=a[i];--t2)
			change(1,l,r,q2[t2-1]+1,q2[t2],a[i]-a[q2[t2]]);
		q1[++t1]=q2[++t2]=i;
		//cout<<i<<endl;
		change(1,l,r,l,i,-1);
		for (;;){
			if (i-pre[i]<=ans.fi) break;
			//cout<<i<<' '<<pre[i]<<' '<<ans.fi<<endl;
			if (ask(1,l,r,pre[i]+1,i-ans.fi)>k) break;
			ans.fi++; ans.se=i-ans.fi+1;
		}
	}
}
/*
:<=0 
*/
int main(){
	scanf("%d%d%d",&n,&k,&d);
	For(i,1,n) scanf("%d",&a[i]);
	if (d==0) SP();
	For(i,1,n) b[i]=(a[i]%d+d)%d,a[i]=(a[i]-b[i])/d;
	int la=1;
	For(i,2,n+1)
		if (b[i]!=b[i-1]||i==n+1)
			solve(la,i-1),la=i; 
	printf("%d %d\n",ans.se,ans.se+ans.fi-1);
}