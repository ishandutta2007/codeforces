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
const int dx[]={-1,0,1,0};
const int dy[]={0,-1,0,1};
const int mo=1000000007;
const int N=55;
int R,P[4],nd,eq;
int vis[N*2][N*2];
int f[N*2][N*2][N*4];
int a[N*4][N*4],q[N*4];
int tmp[N*4];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
void GAUSS(int nd){
	For(i,1,nd){
		a[i][nd+1]=mo-a[i][0];
		a[i][0]=0;
	}
	For(i,1,nd){
		assert(a[i][i]);
		int inv=power(a[i][i],mo-2);
		*q=0;
		For(j,i,nd+1) if (a[i][j]) q[++*q]=j;
		For(j,i+1,nd) if (a[j][i]){
			int val=1ll*a[j][i]*(mo-inv)%mo;
			For(k,1,*q) a[j][q[k]]=(a[j][q[k]]+1ll*val*a[i][q[k]])%mo;
		}
	}
	Rep(i,nd,1){
		For(j,i+1,nd)
			a[i][nd+1]=(a[i][nd+1]+mo-1ll*a[i][j]*a[j][nd+1]%mo)%mo;
		a[i][nd+1]=1ll*a[i][nd+1]*power(a[i][i],mo-2)%mo;
	}
}
int main(){
	scanf("%d",&R);
	For(i,0,3) scanf("%d",&P[i]);
	int S=power(P[0]+P[1]+P[2]+P[3],mo-2);
	For(i,0,3) P[i]=1ll*P[i]*S%mo;
	For(i,-R,R) For(j,-R,R)
		if (i*i+j*j<=R*R) vis[i+N][j+N]=1;
	//cout<<nd<<endl;
	For(i,-R+N,R+N+1) For(j,-R+N,R+N)
		if (vis[i-1][j]){
			memcpy(tmp,f[i-1][j],sizeof(tmp));
			tmp[0]=(tmp[0]+mo-1)%mo;
			int val=power(P[2],mo-2);
			For(k,0,nd){
				tmp[k]=(tmp[k]+mo-1ll*P[0]*f[i-2][j][k]%mo)%mo;
				tmp[k]=(tmp[k]+mo-1ll*P[1]*f[i-1][j-1][k]%mo)%mo;
				tmp[k]=(tmp[k]+mo-1ll*P[3]*f[i-1][j+1][k]%mo)%mo;
				tmp[k]=1ll*tmp[k]*val%mo;
			}
			if (vis[i][j])
				memcpy(f[i][j],tmp,sizeof(f[i][j]));
			else{
				++eq;
				memcpy(a[eq],tmp,sizeof(a[eq]));
			}
		}
		else if (vis[i][j])
			f[i][j][++nd]=1;
	GAUSS(nd);
	int ans=f[N][N][0];
	For(i,1,nd) ans=(ans+1ll*f[N][N][i]*a[i][nd+1])%mo;
	printf("%d\n",ans);
}
/*
i,j
i-1,j
i-1,j 

i+1,j 
*/