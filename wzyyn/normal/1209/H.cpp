#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define y1 wzpakking
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int N=400005;
int len[N],id[N],n,m,T;
double El[N],Er[N],v[N];
double E[N],ans,V[N];
void add(int x,double v){
	len[++m]=x;
	V[m]=v;
}
double S[N*4],mn[N*4];
void pushup(int k){
	S[k]=S[k*2]+S[k*2+1];
	mn[k]=min(mn[k*2],S[k*2]+mn[k*2+1]);
}
void build(int k,int l,int r){
	if (l==r){
		mn[k]=S[k]=E[l];
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	pushup(k);
}
void change(int k,int l,int r,int p,double v){
	if (l==r){
		mn[k]=S[k]=S[k]+v;
		return;
	}
	int mid=(l+r)/2;
	if (p<=mid) change(k*2,l,mid,p,v);
	else change(k*2+1,mid+1,r,p,v);
	pushup(k);
}
double ask(int k,int l,int r,int x,int y){
	if (l==x&&r==y) return mn[k];
	int mid=(l+r)/2;
	if (y<=mid) return ask(k*2,l,mid,x,y);
	if (x>mid) return ask(k*2+1,mid+1,r,x,y)+S[k*2];
	return min(ask(k*2,l,mid,x,mid),ask(k*2+1,mid+1,r,mid+1,y)+S[k*2]);
}
bool cmp(int x,int y){
	return V[x]<V[y];
}
int main(){
	scanf("%d%d",&n,&T);
	int pre=0;
	For(i,1,n){
		int l,r;
		double x;
		scanf("%d%d%lf",&l,&r,&x);
		if (l!=pre) add(l-pre,1);
		add(r-l,x+1);
		pre=r;
	}
	if (pre!=T)
		add(T-pre,1);
	For(i,1,m){
		if (V[i]<1+1e-9) El[i]=1e18;
		else El[i]=len[i]/(V[i]-1)*V[i]-len[i];
		Er[i]=len[i]/(V[i]+1)*V[i]-len[i];
		if (V[i]<1+1e-9) v[i]=0,E[i]=0;
		else v[i]=-1,E[i]=El[i];
		ans+=(E[i]+len[i])/V[i];
		//printf("%.10lf %d %.10lf %.10lf %.10lf %.10lf\n",ans,len[i],V[i],v[i],E[i],Er[i]);
	}
	For(i,1,m) id[i]=i;
	sort(id+1,id+m+1,cmp);
	build(1,1,m);
	For(i,1,m){
		int x=id[i];
		double dif=ask(1,1,m,x,m);
		//printf("%d %.10lf %.10lf\n",x,dif,E[x]-Er[x]);
		dif=min(dif,E[x]-Er[x]);
		ans-=dif/V[x];
		change(1,1,m,x,-dif);
	}
	printf("%.15lf\n",ans);
}