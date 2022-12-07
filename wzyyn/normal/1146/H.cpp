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
const int N=305;
struct P{
	int x,y;
	P(){}
	P(int _x,int _y){
		x=_x; y=_y;
	}
	P operator +(const P &a)const{
		return P(x+a.x,y+a.y);
	}
	P operator -(const P &a)const{
		return P(x-a.x,y-a.y);
	}
	ll operator *(const P &a)const{
		return 1ll*x*a.y-1ll*y*a.x;
	}
	bool bee(){
		return x?x<0:y<0;
	}
}a[N],b[N];
int rk[N][N],id[N][N],n;
int f[N][N][10];
int q1[N],q2[N];
ll ans;
bool cmp(P x,P y){
	return x.x==y.x?x.y<y.y:x.x<y.x;
}
bool cmpp(int x,int y){
	if (b[x].bee()^b[y].bee()) return b[x].bee();
	return b[x]*b[y]>=0;
}
void solve(int x){
	For(j,x+1,n) b[j]=a[j]-a[x];
	//For(j,x+1,n) cout<<b[j].x<<' '<<b[j].y<<endl;
	For(j,x,n) For(k,x,n) For(l,3,5) f[j][k][l]=0;
	For(j,x+1,n) For(k,x+1,n)
		if (rk[x][j]<rk[x][k]) f[j][k][3]=1;//,cout<<j<<' '<<k<<endl;
	For(l,4,5) For(j,x+1,n){
		int pos=rk[j][x];
		int tp1=0,tp2=0,L=n-1;
		for (int p=pos%L+1;p!=pos;p=p%L+1){
			if (id[j][p]>x&&rk[x][id[j][p]]>rk[x][j]) q1[++tp1]=id[j][p];
			if (id[j][p]>x&&rk[x][id[j][p]]<rk[x][j]) q2[++tp2]=id[j][p];
		}
		//cout<<tp1<<' '<<tp2<<' '<<l<<' '<<j<<endl;
		int p2=1,sum=0;
		For(k,1,tp1){
			for (;p2<=tp2&&(b[q1[k]]-b[j])*(b[q2[p2]]-b[j])>0;)
				sum+=f[q2[p2]][j][l-1],p2++;
			f[j][q1[k]][l]+=sum;
		}
		/*For(k,1,tp1) For(kk,1,tp2)
			if ((b[q1[k]]-b[j])*(b[q2[kk]]-b[j])>0)
				f[j][q1[k]][l]+=f[q2[kk]][j][l-1];*/
	}
	For(j,x+1,n) For(k,x+1,n)
		if (rk[x][j]<rk[x][k])
			ans+=f[j][k][5];
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+n+1,cmp);
	For(i,1,n){
		For(j,1,n) if (j!=i)
			b[j]=a[j]-a[i],id[i][j-(j>i)]=j;
		sort(id[i]+1,id[i]+n,cmpp);
		//For(j,1,n-1) printf("%d ",id[i][j]);
		//puts("");
		For(j,1,n-1) rk[i][id[i][j]]=j;
	}
	//solve(1);
	For(i,1,n) solve(i);
	printf("%lld\n",ans);
}