#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
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
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
const int N=100005,BAO=200005,mod=998244353,B=200;
int n,m,Q,ans[N],e[N],q[N],tong[N],tt[N];
vector<int> v[N];
map<int,int> M[N];
ll fac[N<<1],ni[N<<1];
void ins(int id){
	if(--M[tong[e[id]]][tt[e[id]]]==0)M[tong[e[id]]].erase(tt[e[id]]);
	M[tong[e[id]]][++tt[e[id]]]++;
}
void del(int id){
	if(--M[tong[e[id]]][tt[e[id]]]==0)M[tong[e[id]]].erase(tt[e[id]]);
	M[tong[e[id]]][--tt[e[id]]]++;
}
void solve(int id){
	v[id].resize(n);
	v[id][0]=1; ll t=(ll)m*id%mod; 
	for(int i=1;i<n;i++)v[id][i]=v[id][i-1]*(t+i)%mod;
}
struct data{
	int l,r,k,id;
}a[N];
bool operator <(data a,data b){
	return a.l/B==b.l/B?(((a.l/B)&1)?(a.r>b.r):(a.r<b.r)):a.l<b.l;
}
inline int ksm(ll a,int b){
	int ans=1;
	for(;b;b>>=1){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
} 
int p(int x,int y){
	return fac[x]*ni[x-y]%mod;
}
int main(){
	n=read(); m=read(); Q=read();
	for(int i=1;i<=n;i++)tong[e[i]=read()]++;
	for(int i=1;i<=m;i++)q[i]=tong[i];
	sort(&q[1],&q[m+1]); int tot=unique(&q[1],&q[m+1])-q-1;
	int l=1,r=0;
	for(int i=1;i<=Q;i++){
		a[i].l=read(); a[i].r=read(); a[i].k=read(); a[i].id=i;
		if(!v[a[i].k].size())solve(a[i].k);
		ans[i]=v[a[i].k][n-(a[i].r-a[i].l+1)];
	}
	sort(&a[1],&a[Q+1]);
	for(int i=fac[0]=1;i<=BAO;i++)fac[i]=fac[i-1]*i%mod; ni[BAO]=ksm(fac[BAO],mod-2); for(int i=BAO;i;i--)ni[i-1]=ni[i]*i%mod;
	for(int i=1;i<=m;i++)M[tong[i]][0]++;
	for(int i=1;i<=Q;i++){
		while(l>a[i].l)ins(--l);
		while(r<a[i].r)ins(++r);
		while(l<a[i].l)del(l++);
		while(r>a[i].r)del(r--); 
		ll dq=1;
		for(int j=1;j<=tot;j++){
			for(auto k:M[q[j]]){//cout<<dq<<" "<<q[j]+a[i].k<<" "<<k.first<<endl;
				dq=dq*ksm(p(q[j]+a[i].k,k.first),k.second)%mod;
			}
		}
		ans[a[i].id]=ans[a[i].id]*dq%mod;
	}
	for(int i=1;i<=Q;i++)writeln(ans[i]);
}
/*
p(mk+n-(r-l+1),n-(r-l+1))
p(n+1,i+1) (n+1)*n*...*(n-i+1)
p(n,i) n*(n-1)*(n-i+1)
*/