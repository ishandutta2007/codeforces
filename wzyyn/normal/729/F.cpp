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
const int N=4005,M=95;
char vis[N][M][M];
int fl[N][M][M];
int fr[N][M][M];
int n,S[N],a[N];
int Fr(int,int,int);
int Fl(int dl,int k,int dif){
	int dr=dl+dif;
	if (dl+dr+k>n) return S[dl]-(S[n]-S[n-dr]);
	if (vis[dl][k][dif]&1) return fl[dl][k][dif];
	vis[dl][k][dif]|=1;
	int res=Fr(dr,k,dl+k-dr);
	if (dl+dr+k!=n) res=max(res,Fr(dr,k+1,dl+k+1-dr));
	return fl[dl][k][dif]=res;
}
int Fr(int dr,int k,int dif){
	//cout<<dr<<' '<<k<<' '<<dif<<endl;
	int dl=dr+dif;
	if (dl+dr+k>n) return S[dl]-(S[n]-S[n-dr]);
	if (vis[dr][k][dif]&2) return fr[dr][k][dif];
	vis[dr][k][dif]|=2;
	int res=Fl(dl,k,dr+k-dl);
	if (dl+dr+k!=n) res=min(res,Fl(dl,k+1,dr+k+1-dl));
	return fr[dr][k][dif]=res;
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) S[i]=S[i-1]+a[i];
	printf("%d\n",Fl(0,1,0));
}