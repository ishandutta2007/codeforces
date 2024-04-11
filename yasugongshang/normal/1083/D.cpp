#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define ld long double
#define PI pair<int,int>
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
const int N=100005,M=1<<18|3,K=18,mod=1000000007;
int n,ans,qf[N],qg[N],sf,sg,lg[N],a[N],f[N],g[N],F[N][K],G[N][K];
map<int,int> Ma;
ll tr[M],tf[M],ycl[M],lm[M],la[M],yyy[M],YYY[M],tg[M],lA[M],X,Y;
bool check(int l,int r){
	int zs=lg[r-l+1]; 
	if(l<max(F[l][zs],F[r-(1<<zs)+1][zs]))return 0;
	if(r>min(G[l][zs],G[r-(1<<zs)+1][zs]))return 0;
	return 1;
}
inline void Mul(int nod,ll de){
	tr[nod]=tr[nod]*de%mod; lm[nod]=lm[nod]*de%mod;
}
inline void Add(int nod,ll de){
	tf[nod]=(tf[nod]+de*yyy[nod])%mod; la[nod]=(la[nod]+de)%mod;
}
inline void ADD(int nod,ll de){
	tg[nod]=(tg[nod]+de*YYY[nod])%mod; lA[nod]=(lA[nod]+de)%mod;
}
inline void pushdown(int nod){
	if(lm[nod]!=1){
		Mul(nod<<1,lm[nod]); Mul(nod<<1|1,lm[nod]); lm[nod]=1;
	}
	if(la[nod]){
		Add(nod<<1,la[nod]); Add(nod<<1|1,la[nod]); la[nod]=0;
	}
	if(lA[nod]){
		ADD(nod<<1,lA[nod]); ADD(nod<<1|1,lA[nod]); lA[nod]=0;
	}
}
int id;
void insert(int l,int r,int i,int j,int nod){
	if(l==i&&r==j){
		Mul(nod,X); if(id==0)Add(nod,Y); else ADD(nod,Y);return;
	}
	pushdown(nod);
	int mid=(l+r)>>1;
	if(j<=mid)insert(l,mid,i,j,nod<<1); else if(i>mid)insert(mid+1,r,i,j,nod<<1|1);
	else{
		insert(l,mid,i,mid,nod<<1); insert(mid+1,r,mid+1,j,nod<<1|1);
	}
	tr[nod]=(tr[nod<<1]+tr[nod<<1|1])%mod;
	tf[nod]=(tf[nod<<1]+tf[nod<<1|1])%mod;
	tg[nod]=(tg[nod<<1]+tg[nod<<1|1])%mod;
}
ll ask(int l,int r,int i,int j,int nod){
	if(l==i&&r==j)return (tf[nod]+tg[nod]*X-tr[nod])%mod;
	pushdown(nod);
	int mid=(l+r)>>1;
	if(j<=mid)return ask(l,mid,i,j,nod<<1); else if(i>mid)return ask(mid+1,r,i,j,nod<<1|1);
	else return (ask(l,mid,i,mid,nod<<1)+ask(mid+1,r,mid+1,j,nod<<1|1))%mod;
}
void build(int l,int r,int nod){
	yyy[nod]=(ycl[r]-ycl[l-1])%mod; YYY[nod]=r-l+1;
	tr[nod]=r-l+1;
	if(l==r)return; lm[nod]=1;
	int mid=(l+r)>>1;
	build(l,mid,nod<<1); build(mid+1,r,nod<<1|1);
}
inline ll ksm(ll a,int b){
	int ans=1; 
	for(;b;b>>=1){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
int main(){
	n=read(); lg[0]=-1;
	for(int i=1;i<=n;i++){
		a[i]=read(); lg[i]=lg[i>>1]+1; ycl[i]=(ycl[i-1]+i)%mod;
		auto it=Ma.find(a[i]);
		if(it!=Ma.end())f[i]=it->second; else f[i]=0; Ma[a[i]]=i; f[i]++;
	}
	Ma.clear();
	for(int i=n;i;i--){
		auto it=Ma.find(a[i]);
		if(it!=Ma.end())g[i]=it->second; else g[i]=n+1; Ma[a[i]]=i; g[i]--;
	}
	for(int i=n;i;i--){
		F[i][0]=f[i]; for(int j=1;i+(1<<j)-1<=n;j++)F[i][j]=max(F[i][j-1],F[i+(1<<(j-1))][j-1]);
		G[i][0]=g[i]; for(int j=1;i+(1<<j)-1<=n;j++)G[i][j]=min(G[i][j-1],G[i+(1<<(j-1))][j-1]);
	}
	int dq=n;
	qf[0]=qg[0]=n+1;
	build(1,n,1);
	for(int i=n;i;i--){
		while(!check(i,dq))dq--; id=0;
		while(sf&&f[qf[sf]]<=f[i]){
			X=ksm(f[qf[sf]],mod-2); Y=-f[qf[sf]];
			insert(1,n,qf[sf],qf[sf-1]-1,1); sf--;
		}
		X=f[i]; Y=f[i];
		insert(1,n,i,qf[sf]-1,1); qf[++sf]=i; id=1;
		while(sg&&g[qg[sg]]>=g[i]){
			X=ksm(g[qg[sg]],mod-2); Y=-g[qg[sg]];
			insert(1,n,qg[sg],qg[sg-1]-1,1); sg--;
		}
		X=g[i]; Y=g[i];
		insert(1,n,i,qg[sg]-1,1); qg[++sg]=i; X=i;
		ans=(ans+ask(1,n,i,dq,1)-i*(ycl[dq]-ycl[i-1])%mod)%mod;
		//cout<<ask(1,n,i,dq,1)<<" "<<ans<<" "<<dq<<endl;
	}
	ans=(ans+mod)%mod;
	cout<<ans<<endl;
}
/*
l-maxf[l,r] ming[l,r]-r
*/