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
const int mo=1000000007;
const int N=1000005;
int n,a[N],bas[N];
int cnt[N],cntb[N];
int matl[N],matr[N];
vector<int> di[N];
void GG(){
	puts("0");
	exit(0);
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) bas[i]=1;
	For(i,2,n) if (bas[i]==1){
		++cnt[n/i];
		For(j,1,n/i){
			bas[i*j]*=i;
			di[i*j].PB(i);
		}
	}
	di[1].PB(n); ++cnt[1];
	For(i,1,n) ++cntb[bas[i]];
	For(i,1,n) if (a[i]){
		if (di[i].size()!=di[a[i]].size()) GG();
		For(j,0,di[i].size()-1){
			int v1=di[i][j],v2=di[a[i]][j];
			if (n/v1!=n/v2) GG();
			if (matl[v1]&&matl[v1]!=v2) GG();
			if (matr[v2]&&matr[v2]!=v1) GG();
			if (!matr[v2]) matl[v1]=v2,matr[v2]=v1,cnt[n/v1]--;
		} 
		cntb[bas[i]]--;
	}
	int ans=1;
	For(i,1,n) For(j,1,cnt[i]) ans=1ll*ans*j%mo;
	For(i,1,n) For(j,1,cntb[i]) ans=1ll*ans*j%mo;
	printf("%d\n",ans);
}