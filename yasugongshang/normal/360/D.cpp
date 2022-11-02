#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
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
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
int n,m,mod,tot,q[10005],g,ans,dp[10005],vis[10005],a[10005];

const int B=2000;
const int p=2000000000/B+7;
struct hash_table{
	int a[p]; int b[p];
	bool hash[p];
	int tot,pos[p];
	void insert(int x,int y){
		for(int i=x%p;;i=i+1==p?0:i+1){
			if(!hash[i]||a[i]==x){
				hash[i]=1; a[i]=x; b[i]=y; return;
			}
		}
	}
	int find(int x){
		for(int i=x%p;;i=i+1==p?0:i+1){
			if(!hash[i])return -1;
			if(a[i]==x)return b[i];
		}
	}
}M;
vector<int> an;
inline int ksm(ll a,int b){
	int ans=1;
	for(;b;b>>=1){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
bool check(int x){
	for(int i=1;i<=tot;i++)if(ksm(x,(mod-1)/q[i])==1)return 0;
	return 1;
}
void init(){
	ll t=1,gg=ksm(g,B);
	for(int i=0;i*B<mod;i++){M.insert(t,i); t=t*gg%mod; }
}
int qiu(int x){
	ll t=x,gg=ksm(g,mod-2);
	for(int i=0;;i++){
		if(M.find(t)!=-1)return M.find(t)*B+i;
		t=t*gg%mod; 
	}
}
signed main(){
	n=read(); m=read(); mod=read(); int t=mod-1,s=0;
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=m;i++)s=__gcd(s,(int)read());
	for(int i=2;i*i<=t;i++)if(t%i==0){
		while(t%i==0)t/=i; q[++tot]=i;
	}
	if(t>1)q[++tot]=t;
	for(int i=2;i<mod;i++){
		if(check(i)){g=i; break;}
	}
	init();
	int sss=(mod-1)/__gcd(mod-1,s);
	for(int i=1;i<=n;i++){
		int x=a[i];
		int t=qiu(x); //cout<<t<<endl;
		an.push_back(__gcd(sss,t));
	}
	sort(an.begin(),an.end());
	an.resize(unique(an.begin(),an.end())-an.begin());
	tot=0;
	for(int i=1;i*i<=sss;i++)if(sss%i==0){
		q[++tot]=i; if(i*i!=sss)q[++tot]=sss/i;
	}
	sort(&q[1],&q[tot+1]);
	for(unsigned i=0;i<an.size();i++)for(int j=1;j<=tot;j++)if(q[j]%an[i]==0)vis[j]=1;
	for(int i=tot;i;i--){
		dp[i]=sss/q[i];
		for(int j=i+1;j<=tot;j++)if(q[j]%q[i]==0)dp[i]-=dp[j];
		if(vis[i])ans+=dp[i];
	}
	cout<<ans<<endl;
}