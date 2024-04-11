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
#define db long double
const int N=10005;
int n,Q;
db x[N],y[N];
db dis[N],angx,angy;
void getP(int id,db &px,db &py){
	px=x[id]*angx-y[id]*angy;
	py=x[id]*angy+y[id]*angx;
}
int main(){
	scanf("%d%d",&n,&Q);
	For(i,1,n){
	    int aaa,bbb;
	    scanf("%d%d",&aaa,&bbb);
	    x[i]=aaa; y[i]=bbb;
	}
	db dx=x[1],dy=y[1],cx=0,cy=0,S=0;
	For(i,1,n) x[i]-=dx,y[i]-=dy;
	For(i,1,n){
		db v=x[i]*y[i%n+1]-y[i]*x[i%n+1];
		cx+=(x[i]+x[i%n+1])*v/3;
		cy+=(y[i]+y[i%n+1])*v/3;
		S+=v;
	}
	dx+=(cx/=S); dy+=(cy/=S); angx=1;
	For(i,1,n) x[i]-=cx,y[i]-=cy;
	For(i,1,n) dis[i]=sqrt(x[i]*x[i]+y[i]*y[i]);
	int pin=3;
	while (Q--){
		int tp,vx,vy;
		scanf("%d",&tp);
		if (tp==1){
			scanf("%d%d",&vx,&vy);
			pin-=vx;
			db px,py;
			getP(pin,px,py);
			dx+=px; dy+=py-dis[pin];
			angx=y[pin]/dis[pin];
			angy=x[pin]/dis[pin];
			pin+=vy;
		}
		else{
			scanf("%d",&vx);
			db px,py;
			getP(vx,px,py);
			px+=dx; py+=dy;
			printf("%.10lf %.10lf\n",(double)(px),(double)(py));
		}
	}
	//cout<<cx<<' '<<cy<<endl;
}