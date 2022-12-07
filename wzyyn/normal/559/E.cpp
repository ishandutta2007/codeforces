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
const int N=105;
int R[N][N],q[N*2];
int f[N][N*2],n;
pii a[N];
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d%d",&a[i].fi,&a[i].se);
	sort(a+1,a+n+1);
	For(i,1,n){
		q[++*q]=a[i].fi;
		q[++*q]=a[i].fi+a[i].se;
	}
	q[++*q]=-(1<<30);
	sort(q+1,q+*q+1);
	*q=unique(q+1,q+*q+1)-q-1;
	For(i,1,n) For(j,i,n)
		if (a[j].fi-a[j].se<=a[i].fi){
			R[i][j]=a[j].fi;
			For(k,i,j-1)
				R[i][j]=max(R[i][j],a[k].fi+a[k].se);
		}
	f[0][0]=0;
	For(i,1,n){
		int pos=lower_bound(q+1,q+*q+1,a[i].fi+a[i].se)-q;
		For(j,1,*q) f[i][j]=f[i-1][j];
		For(j,1,pos) f[i][pos]=max(f[i][pos],f[i-1][j]+q[pos]-max(q[j],a[i].fi));
		For(j,0,i-1){
			int pp=lower_bound(q+1,q+*q+1,R[j+1][i])-q;
			For(k,1,pp) f[i][pp]=max(f[i][pp],f[j][k]+q[pp]-max(q[k],a[i].fi-a[i].se));
		}
	}
	int ans=0;
	For(k,1,*q) ans=max(ans,f[n][k]);
	printf("%d\n",ans);
}