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
const int N=100005;
int pri[55],mul[55],cnt[55];
int fac[N],inv[N];
int val[N],sum[N];
int n,mod,l,r;
void divide(){
	For(i,2,50000)
		if (mod%i==0){
			pri[++*pri]=i;
			mul[*pri]=1;
			for (;mod%i==0;mod/=i){
				mul[*pri]*=i;
				cnt[*pri]++;
			}
		}
	if (mod!=1){
		pri[++*pri]=mod;
		mul[*pri]=mod;
		cnt[*pri]=1;
	}
}
int power(int x,int y,int mo){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int C(int x,int y,int id){
	if (x<0||y<0||y>x) return 0;
	int res=1ll*fac[x]*inv[y]%mul[id]*inv[x-y]%mul[id];
	int T=sum[x]-sum[y]-sum[x-y];
	for (;T&&res;T--,res=1ll*res*pri[id]%mul[id]);
	return res;
}
int solve(int id){
	fac[0]=inv[0]=1;
	int phi=mul[id]-mul[id]/pri[id];
	For(i,1,n){
		val[i]=i; sum[i]=0; 
		for (;val[i]%pri[id]==0;)
			val[i]/=pri[id],sum[i]++;
		fac[i]=1ll*fac[i-1]*val[i]%mul[id];
		inv[i]=1ll*inv[i-1]*power(val[i],phi-1,mul[id])%mul[id];
		sum[i]+=sum[i-1];
	}
	int ans=0;
	For(i,0,n){
		int nl=l,nr=min(i,r);
		nl+=(nl+i)&1; nr-=(nr+i)&1;
		if (nl>nr) continue;
		//cout<<i<<' '<<nl<<' '<<nr<<endl;
		int res=(C(i,(i+nl)/2,id)+mul[id]-C(i,(i+nr)/2+1,id))%mul[id];
		//cout<<res<<endl;
		ans=(ans+1ll*res*C(n,i,id))%mul[id];
	}
	//cout<<mul[id]<<' '<<ans<<endl;
	return ans;
}
void exgcd(int x,int y,int &a,int &b){
	if (!y){
		a=1; b=0;
		return;
	}
	exgcd(y,x%y,b,a);
	b-=x/y*a;
}
int getinv(int x,int y){
	int a,b;
	exgcd(x,y,a,b);
	return (a%y+y)%y;
}
pii merge(pii x,pii y){
	pii ans;
	ans.fi=x.fi*y.fi;
	ans.se=(1ll*getinv(x.fi,y.fi)*x.fi%ans.fi*y.se+
			1ll*getinv(y.fi,x.fi)*y.fi%ans.fi*x.se)%ans.fi;
	return ans;
}
/*
inv(3,5)*5 10
inv(5,3)*3 01
*/
int main(){
	scanf("%d%d%d%d",&n,&mod,&l,&r);
	if (mod==1) return puts("0"),0;
	divide();
	static pii ans[25];
	For(i,1,*pri) ans[i]=pii(mul[i],solve(i));
	For(i,2,*pri) ans[i]=merge(ans[i],ans[i-1]);
	printf("%d\n",ans[*pri].se);
}