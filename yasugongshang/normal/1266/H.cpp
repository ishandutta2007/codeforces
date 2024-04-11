#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<ll>
#define mem(a) memset(a,0,sizeof(a))
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define fi first
#define se second
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
const int N=60,mod1=1e9+7,mod2=1e9+9;
ll A[N][N],B[N][N],a[N][N];

struct d1{
	const int mod=mod1;
	ll ksm(ll a,int b){
		int ans=1;
		for(;b;b>>=1){
			if(b&1)ans=ans*a%mod;
			a=a*a%mod;
		}
		return ans;
	}
	ll b[N][N];
	
	void solve(int n){
		memcpy(a,A,sizeof(a));
		memcpy(b,B,sizeof(b));
		For(i,1,n){
			For(j,i,n)if(a[j][i]){
				swap(a[j],a[i]);
				swap(b[j],b[i]); 
				break;
			}
			ll zs=ksm(a[i][i],mod-2);
			For(j,1,n){
				a[i][j]=a[i][j]*zs%mod; b[i][j]=b[i][j]*zs%mod;
			}
			For(j,1,n)if(i!=j){
				zs=a[j][i];
				For(k,1,n){
					if(a[i][k])a[j][k]=(a[j][k]-a[i][k]*zs)%mod;
					b[j][k]=(b[j][k]-b[i][k]*zs)%mod;
				}
			}
		}
	}
	void bao(int n,ll aa[],ll AA[]){
		mem(AA);
		For(i,1,n){
			For(j,1,n)AA[i]=(AA[i]+aa[j]*b[i][j])%mod;AA[i]=(AA[i]+mod)%mod;
		}
	}
}T1;
struct d2{
	const int mod=mod2;
	ll ksm(ll a,int b){
		int ans=1;
		for(;b;b>>=1){
			if(b&1)ans=ans*a%mod;
			a=a*a%mod;
		}
		return ans;
	}
	ll b[N][N];
	
	void solve(int n){
		memcpy(a,A,sizeof(a));
		memcpy(b,B,sizeof(b));
		For(i,1,n){
			For(j,i,n)if(a[j][i]){
				swap(a[j],a[i]);
				swap(b[j],b[i]); 
				break;
			}
			ll zs=ksm(a[i][i],mod-2);
			For(j,1,n){
				a[i][j]=a[i][j]*zs%mod; b[i][j]=b[i][j]*zs%mod;
			}
			For(j,1,n)if(i!=j){
				zs=a[j][i];
				For(k,1,n){
					if(a[i][k])a[j][k]=(a[j][k]-a[i][k]*zs)%mod;
					b[j][k]=(b[j][k]-b[i][k]*zs)%mod;
				}
			}
		}
		//For(i,1,n){For(j,1,n){wri(b[i][j]);}puts("");}	For(i,1,n)wri(A[i][1]); puts("");
	}
	void bao(int n,ll aa[],ll AA[]){
		mem(AA);
		For(i,1,n){
			For(j,1,n)AA[i]=(AA[i]+aa[j]*b[i][j])%mod;AA[i]=(AA[i]+mod)%mod;
		}
	}
}T2;
int b[N],r[N];
bool bj[N];
char s[N];
ll aa[N],bb[N],AA[N],BB[N],ans[N];
vector<int> e[N];
void dfs(int p){
	if(bj[p])return; else bj[p]=1;
	for(auto i:e[p])dfs(i);
}
int main(){
	int n=read();
	ll inv2=T1.ksm(mod2,mod1-2),inv1=T2.ksm(mod1,mod2-2);
	For(i,1,n-1){
		b[i]=read(); r[i]=read();
		A[r[i]][i]--; A[b[i]][i]--;
		A[i][i]+=2; B[i][i]=1;
	}
	T1.solve(n-1);
	T2.solve(n-1);
	int q=read();
	while(q--){
		int v=read();
		scanf("%s",s+1);
		For(i,1,n-1)aa[i]=bb[i]=(s[i]=='R')+(i==1)-(i==v);
		For(i,1,n-1)if(s[i]=='R'){
			aa[b[i]]--; bb[b[i]]--;
		}
		mem(AA); mem(BB);
		T1.bao(n-1,aa,AA); T2.bao(n-1,bb,BB);
		For(i,1,n-1){
			//cout<<A[1][i]*AA[i]<<" "<<T1.b[i][1]%mod1<<" "<<AA[i]%mod1<<" "<<BB[i]<<endl;
			ans[i]=(AA[i]*inv2%mod1*mod2+BB[i]*inv1%mod2*mod1)%((ll)mod1*mod2);
			//cout<<ans[i]<<" "<<aa[i]<<" "<<AA[i]<<" "<<BB[i]<<endl;
		}//cout<<aa[1]<<endl;
		For(i,1,n-1)For(j,1,n-1)aa[i]-=A[i][j]*ans[j];
		int f=1;
		For(i,1,n-1){if(aa[i]||(ans[i]-(s[i]=='R'))<0)f=0; e[i].clear();}
		mem(bj);
		For(i,1,n-1){
			if(s[i]=='B')e[b[i]].pb(i); else e[r[i]].pb(i);
		}
		dfs(v);
		For(i,1,n-1)if(!bj[i]&&ans[i]){
			f=0; // cout<<ans[i]<<" "<<f<<" "<<aa[i]<<endl;
		}
		if(!f)puts("-1");else{
			ll sum=0;
			For(i,1,n-1)sum+=ans[i]*2-(s[i]=='R');
			writeln(sum);
		}
	}
}