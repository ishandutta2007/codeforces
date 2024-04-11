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
const int mo=998244353;
const int N=105;
int n,x[N],y[N];
int T,q[N*N];
int Area(int T){
	static int qx[N],qy[N];
	*qx=*qy=0;
	For(i,1,n){
		qx[++*qx]=x[i]-T;
		qx[++*qx]=x[i]+T+1;
		qy[++*qy]=y[i]-T;
		qy[++*qy]=y[i]+T+1;
	}
	sort(qx+1,qx+*qx+1);
	sort(qy+1,qy+*qy+1);
	*qx=unique(qx+1,qx+*qx+1)-qx-1;
	*qy=unique(qy+1,qy+*qy+1)-qy-1;
	static int sum[N][N];
	memset(sum,0,sizeof(sum));
	For(i,1,n){
		int x1=lower_bound(qx+1,qx+*qx+1,x[i]-T)-qx;
		int x2=lower_bound(qx+1,qx+*qx+1,x[i]+T+1)-qx;
		int y1=lower_bound(qy+1,qy+*qy+1,y[i]-T)-qy;
		int y2=lower_bound(qy+1,qy+*qy+1,y[i]+T+1)-qy;
		sum[x1][y1]++; sum[x2][y2]++;
		sum[x1][y2]--; sum[x2][y1]--;
	}
	For(i,1,*qx) For(j,1,*qy) sum[i][j]+=sum[i][j-1];
	For(i,1,*qx) For(j,1,*qy) sum[i][j]+=sum[i-1][j];
	ll ans=0;
	For(i,1,(*qx)-1) For(j,1,(*qy)-1)
		if (sum[i][j]) ans+=1ll*(qx[i+1]-qx[i])*(qy[j+1]-qy[j]);
	return ans%mo;
}
int S0(int l,int r){
	return r-l+1;
} 
int S1(int l,int r){
	return 1ll*(l+r)*(r-l+1)/2%mo;
}
int S2(int l,int r){
	int vr=1ll*r*(r+1)%mo*(r*2+1)%mo;
	int vl=1ll*l*(l-1)%mo*(l*2-1)%mo;
	return (vr+mo-vl)*1ll*(mo+1)/6%mo; 
}
int Func(int l,int r){
	int f0=Area(l);
	int f1=Area(l+1);
	int f2=Area(l+2);
	int a=(f2+f0+2ll*mo-f1-f1)*(mo+1)/2%mo;
	int b=(f1+2ll*mo-f0-1ll*(2*l+1)*a%mo)%mo;
	int c=(f0+2ll*mo-1ll*l*l%mo*a%mo-1ll*l*b%mo)%mo;
	assert((1ll*l*l%mo*a+1ll*l*b+c)%mo==f0);
	assert((1ll*(l+1)*(l+1)%mo*a+1ll*(l+1)*b+c)%mo==f1);
	assert((1ll*(l+2)*(l+2)%mo*a+1ll*(l+2)*b+c)%mo==f2);
	return (1ll*a*S2(l,r)+1ll*b*S1(l,r)+1ll*c*S0(l,r))%mo;
}
/*
3-al
al^2
a(l+1)^2
a(l+2)^2
*/
int main(){
	scanf("%d%d",&n,&T); 
	For(i,1,n) scanf("%d%d",&x[i],&y[i]);
	For(i,1,n) For(j,i+1,n)
		q[++*q]=(max(abs(x[i]-x[j]),abs(y[i]-y[j]))+1)/2;
	q[++*q]=T+1;
	sort(q+1,q+*q+1);
	*q=unique(q+1,q+*q+1)-q-1;
	for (;q[*q]!=T+1;--*q);
	int top=*q; q[0]=0;
	int ans=1ll*Area(T)*(T+1)%mo;
	For(i,1,top) ans=(ans+mo-Func(q[i-1],q[i]-1))%mo;
	printf("%d\n",ans);
}
/*
41
17
2 
*/