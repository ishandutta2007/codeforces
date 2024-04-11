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
const int N=2000005;
int n,m1,m2,t,m,a[2][N];
int x1[N],x2[N],q[N];
int f[2][N],pre[2][N];
vector<int> A;
vector<pii> B;
void UPD(int px,int py,int v,int fr){
	if (f[px][py]<v){
		f[px][py]=v;
		pre[px][py]=fr;
	}
}
int main(){
	scanf("%d%d%d%d",&n,&m1,&m2,&t);
	For(i,1,m1) scanf("%d",&x1[i]);
	For(i,1,m2) scanf("%d",&x2[i]);
	For(i,1,m1) q[++m]=x1[i],q[++m]=x1[i]+1;
	For(i,1,m2) q[++m]=x2[i],q[++m]=x2[i]+1;
	q[++m]=1; q[++m]=n+1;
	sort(q+1,q+m+1);
	m=unique(q+1,q+m+1)-q-1;
	For(i,1,m1) a[0][lower_bound(q+1,q+m+1,x1[i])-q]=t;
	For(i,1,m2) a[1][lower_bound(q+1,q+m+1,x2[i])-q]=t;
	memset(f,-1,sizeof(f));
	f[0][0]=f[1][0]=0; pre[1][0]=1;
	For(i,0,m-1){
		For(w,0,1)
			if (f[w][i]!=-1&&!a[w^1][i])
				UPD(w^1,i,min(t,f[w][i]),1);
		For(w,0,1)
			if (f[w][i]!=-1&&f[w][i]+q[i+1]-q[i]-1>=a[w][i+1])
				UPD(w,i+1,f[w][i]+q[i+1]-q[i]-a[w][i+1],0);
	}
	int w=(f[1][m]>f[0][m]);
	if (f[w][m]==-1) return puts("No"),0;
	puts("Yes");
	int px=m,py=w,la=1e9;
	for (;px||py;){
		//cout<<px<<' '<<py<<' '<<q[px]<<' '<<f[py][px]<<' '<<pre[py][px]<<endl;
		if (pre[py][px])
			py^=1,A.PB(q[px]);
		else{
			if (a[py][px]){
				la=min(la-t,q[px]-1);
				B.PB(pii(la,py+1));
			}
			px--;
		}
	}
	printf("%d\n",A.size());
	Rep(i,A.size()-1,0) printf("%d ",A[i]);
	printf("\n%d\n",B.size());
	Rep(i,B.size()-1,0) printf("%d %d\n",B[i].fi,B[i].se);
}