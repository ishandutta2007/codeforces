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
const int M=5005;
int a;
int vis[1005][M*2];
int fr[1005][M*2];
pii q[1005*M*2];
char ans[M*2];
int main(){
	scanf("%d",&a);
	int h=0,t=1;
	q[1]=pii(0,M);
	while (h!=t){
		int x=q[++h].fi,y=q[h].se;
		//if (h%10==0) cout<<h<<' '<<t<<' '<<x<<' '<<y<<endl;
		For(dig,0,9){
			if (h==1&&dig==0) continue;
			int nx=(x+dig*a)/10;
			int ny=y+dig-(x+dig*a)%10*a;
			if (ny<0||ny>=2*M||vis[nx][ny]) continue;
			vis[nx][ny]=1; q[++t]=pii(nx,ny);
			fr[nx][ny]=y*11000+x*10+dig;
		}
	}
	if (!vis[0][M]) return puts("-1"),0;
	int top=0,px=0,py=M;
	for (;;){
		int ny=fr[px][py]/11000;
		int nx=fr[px][py]%11000/10;
		ans[++top]=fr[px][py]%10+'0';
		px=nx; py=ny;
		if (px==0&&py==M) break;
	}
	int p=1;
	for (;ans[p]=='0';++p);
	printf("%s\n",ans+p);
}
/*
76662
*/