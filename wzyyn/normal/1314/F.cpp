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
ull f[65][65];
ull pr[8][8][256][256];
int vis[65][65];
ull M2(int x,int y);
ull M(ull x,ull y){
	ull ans=0;
	For(i,0,63) if (x&(1ull<<i))
		For(j,0,63) if (y&(1ull<<j))
			ans^=M2(i,j);
	return ans;
}
ull M2(int x,int y){
	if (!x||!y) return f[x][y]=1ll<<(x+y);
	if (vis[x][y]) return f[x][y];
	int n=1; vis[x][y]=1;
	for (;(n<<1)<=max(x,y);n<<=1);
	if (x>=n&&y>=n) return f[x][y]=M((1ull<<n)/2*3,M2(x-n,y-n));
	if (x>=n) return f[x][y]=M2(x-n,y)<<n;
	if (y>=n) return f[x][y]=M2(x,y-n)<<n;
}
ull MulN(ull x,ull y){
	ull ans=0;
	For(i,0,7) For(j,0,7)
		ans^=pr[i][j][(x>>(i<<3))&255][(y>>(j<<3))&255];
	return ans;
}
ull PowN(ull x,ull y){
	ull s=1;
	for (;y;y/=2,x=MulN(x,x))
		if (y&1) s=MulN(s,x);
	return s;
}
const ull bas=-1;
const ull w=1145141919811ull;
const ull di[]={3,5,17,257,641,65537,6700417};
ull InvN(ull x){
	return PowN(x,bas-1);
}
ull getordN(ull x,ull di){
	static map<ull,int> mp;
	ull v=PowN(w,bas/di),y=1,z=1;
	x=PowN(x,bas/di);
	mp.clear();
	int B=0,C=0;
	for (;1ll*B*B<=di;++B)
		mp[y]=B,y=MulN(y,v);
	y=PowN(y,bas-1);
	for (;C<=B;++C){
		if (mp.find(x)!=mp.end())
			return C*B+mp[x];
		x=MulN(x,y);
	}
	return -1;
}
ull Mul(ull x,ull y,ull mod){
	ull s=0;
	for (;y;y/=2,x=x+x-(x>=mod-x?mod:0))
		if (y&1) s=s+x-(s>=mod-x?mod:0);
	return s;
}
ull getinv(ull x,ull y){
	ull t=y,s=1; x%=y;
	For(i,0,6) if (y%di[i]==0) t-=t/di[i];
	for (--t;t;t/=2,x=Mul(x,x,y))
		if (t&1) s=Mul(s,x,y);
	return s;
}
ull gcd(ull x,ull y){
	return y?gcd(y,x%y):x;
} 
ull getordN(ull x){
	ull ans=0;
	static ull val[10];
	For(i,0,6) val[i]=getordN(x,di[i]);
	For(i,0,6) assert(val[i]!=-1);
	For(i,0,6){
		ll v=Mul(val[i],(bas/di[i])*getinv(bas/di[i],di[i]),bas);
		ans=(ans+v-(ans>=bas-v?bas:0));
	}
	//cout<<x<<' '<<ans<<' '<<PowN(w,ans)<<endl;
	assert(PowN(w,ans)==x);
	return ans;
}
int main(){
	//freopen("1.in","r",stdin);
	For(i,0,63) For(j,0,63) f[i][j]=M2(i,j);
	For(i,0,7) For(j,0,7)
		For(v1,0,255) For(va,0,7) if (v1&(1<<va))
			For(v2,0,255) For(vb,0,7) if (v2&(1<<vb))
				pr[i][j][v1][v2]^=f[(i<<3)|va][(j<<3)|vb];
	For(i,0,6) assert(PowN(w,bas/di[i])!=1);
	int T;
	scanf("%d",&T);
	while (T--){
		ull x,y,v;
		scanf("%llu%llu",&x,&y);
		ull vx=getordN(x),vy=getordN(y),t=bas;
		if (vy==0) printf("%llu\n",bas);
		else if (vx==0) puts("-1");
		else{
			ull G=gcd(vx,t); vx/=G; t/=G;
			if (vy%G) puts("-1");
			else{
				vy/=G;
				//cout<<"WZP "<<vx<<' '<<vy<<' '<<t<<endl;
				printf("%llu\n",Mul(getinv(vx,t),vy,t));
			}
		}
	}
}
/*


 
*/