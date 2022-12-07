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
int n,a,b,c,top,x[4],y[4];
ll T,v[4],A[4];
char ans[500005];
ll sum(int id,int sx,int sy,int tx,int ty){
	int vl=abs(sx-x[id])+abs(sy-y[id]);
	int vr=abs(tx-x[id])+abs(ty-y[id]);
	return vl<=vr?1ll*(vl+vr+1)*(vr-vl)/2:1ll*(vl+vr-1)*(vl-vr)/2;
}
bool check(int px,int py){
	For(i,0,3) A[i]=v[i];
	if (px!=1||py!=1)
		For(i,0,3) A[i]-=abs(x[i]-px)+abs(y[i]-py);
	//For(i,0,3) cout<<A[i]<<' '; cout<<endl;
	if (px<x[0]){
		For(i,0,3) A[i]-=sum(i,px,py,x[0],py);
		px=x[0];
	}
	if (py<y[0]){
		For(i,0,3) A[i]-=sum(i,px,py,px,y[0]);
		py=y[0];
	}
	if (px<=x[1]&&py<=y[2]){
		//cout<<A[0]<<' '<<A[1]<<' '<<px<<' '<<py<<endl;
		A[0]-=sum(0,px,py,x[1],y[2]);
		A[3]-=sum(3,px,py,x[1],y[2]);
		A[1]-=sum(1,px,py,x[1],py)+sum(1,x[1],py,x[1],y[2]);
		A[2]-=sum(2,px,py,px,y[2])+sum(2,px,y[2],x[1],y[2]);
		ll dif=sum(1,px,py,px,y[2])+sum(1,px,y[2],x[1],y[2])-
			   sum(1,px,py,x[1],py)-sum(1,x[1],py,x[1],y[2]);
		//cout<<dif<<endl;
		if (A[2]-A[1]>=dif) A[2]-=dif;
		else if (A[1]-A[2]>=dif) A[1]-=dif;
		else{
			ll tmp=A[2]-(A[2]+A[1]-dif)/2;
			if (tmp&1) ++tmp;
			A[2]-=tmp; A[1]-=dif-tmp;
		}
		//cout<<A[0]<<' '<<A[1]<<' '<<px<<' '<<py<<endl;
		px=x[1]; py=y[2];
	}
	if (px<x[1]){
		For(i,0,3) A[i]-=sum(i,px,py,x[1],py);
		px=x[1];
	}
	if (py<y[2]){
		For(i,0,3) A[i]-=sum(i,px,py,px,y[2]);
		py=y[2];
	}
	For(i,0,3)
		A[i]-=sum(i,px,py,n,n);
	//For(i,0,3) cout<<A[i]<<' '; cout<<endl;
	For(i,0,3)
		if (A[i]<0) return 0;
	return 1;
}
int main(){
	scanf("%d%lld%d%d%d",&n,&T,&a,&b,&c);
	v[0]=v[1]=v[2]=v[3]=T;
	x[0]=x[2]=a; x[1]=x[3]=a+c-1;
	y[0]=y[1]=b; y[2]=y[3]=b+c-1;
	int px=1,py=1;
	if (!check(1,1)) return puts("Impossible"),0;
	for (;px!=n||py!=n;){
		if (px!=n&&check(px+1,py)) ans[++top]='R',px++;
		else ans[++top]='U',py++;
		For(j,0,3) v[j]-=abs(px-x[j])+abs(py-y[j]);
	}
	printf("%s",ans+1);
}