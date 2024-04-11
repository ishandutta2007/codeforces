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
const int mo=998244353;
double f[N][2][2];
int val[N][2][2],ok[N][2][2];
int n,ans,tp,x[N],v[N],p[N],I100;
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
struct node{
	int x,v1,v2;
	double v;
	bool operator <(const node &a)const{
		return v<a.v;
	}
}q[N*2];
struct nodee{
	int a[2][2];
}t[N*4];
nodee merge(nodee x,nodee y,int mid){
	nodee ans;
	memset(ans.a,0,sizeof(ans.a));
	For(i,0,1) For(j,0,1) For(ii,0,1) For(jj,0,1)
		if (ok[mid][j][ii])
			ans.a[i][jj]=(ans.a[i][jj]+1ll*x.a[i][j]*y.a[ii][jj])%mo;
	return ans;
}
void build(int k,int l,int r){
	if (l==r){
		t[k].a[0][1]=t[k].a[1][0]=0;
		t[k].a[0][0]=1ll*I100*(100 +mo-p[l])%mo;
		t[k].a[1][1]=1ll*I100*p[l]%mo;
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	t[k]=merge(t[k*2],t[k*2+1],mid);
}
void change(int k,int l,int r,int p){
	if (l==r) return;
	int mid=(l+r)/2;
	if (p<=mid) change(k*2,l,mid,p);
	else change(k*2+1,mid+1,r,p);
	t[k]=merge(t[k*2],t[k*2+1],mid);
}
nodee ask(int k,int l,int r,int x,int y){
	if (l==x&&r==y) return t[k];
	int mid=(l+r)/2;
	if (y<=mid) return ask(k*2,l,mid,x,y);
	if (x>mid) return ask(k*2+1,mid+1,r,x,y);
	return merge(ask(k*2,l,mid,x,mid),ask(k*2+1,mid+1,r,mid+1,y),mid);
}
int main(){
	scanf("%d",&n);
	I100=power(100,mo-2)%mo;
	For(i,1,n) scanf("%d%d%d",&x[i],&v[i],&p[i]);
	For(i,1,n-1){
		For(j,0,1) For(k,0,1) f[i][j][k]=1e60;
		f[i][1][0]=1.0*(x[i+1]-x[i])/(v[i]+v[i+1]);
		val[i][1][0]=1ll*(x[i+1]-x[i])*power(v[i]+v[i+1],mo-2)%mo;
		//printf("%d\n",val[i][1][0]);
		q[++tp]=(node){i,1,0,f[i][1][0]};
		if (v[i]>v[i+1]){
			f[i][1][1]=1.0*(x[i+1]-x[i])/(v[i]-v[i+1]);
			val[i][1][1]=1ll*(x[i+1]-x[i])*power(v[i]-v[i+1],mo-2)%mo;
			q[++tp]=(node){i,1,1,f[i][1][1]};
		}
		if (v[i]<v[i+1]){
			f[i][0][0]=1.0*(x[i+1]-x[i])/(v[i+1]-v[i]);
			val[i][0][0]=1ll*(x[i+1]-x[i])*power(v[i+1]-v[i],mo-2)%mo;
			q[++tp]=(node){i,0,0,f[i][0][0]};
		}
	}
	For(i,1,n-1) For(j,0,1) For(k,0,1)
		ok[i][j][k]=1;
	build(1,1,n);
	sort(q+1,q+tp+1);
	For(i,1,tp){
		nodee pr=ask(1,1,n,1,q[i].x);
		nodee su=ask(1,1,n,q[i].x+1,n);
		int v1=(pr.a[0][q[i].v1]+pr.a[1][q[i].v1])%mo;
		int v2=(su.a[q[i].v2][0]+su.a[q[i].v2][1])%mo;
		ans=(ans+1ll*v1*v2%mo*val[q[i].x][q[i].v1][q[i].v2])%mo;
		ok[q[i].x][q[i].v1][q[i].v2]=0;
		change(1,1,n,q[i].x);
	}
	printf("%d\n",ans);
}