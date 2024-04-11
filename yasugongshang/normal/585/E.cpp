#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<ll>
#define mem(a) memset((a),0,sizeof(a))
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
const int N=10000005,mod=1000000007;
int n,tong[N],miu[N],f[N],tot,ans,q[1000005],ycl[500005];
ll g[N];
bitset<N> heshu;
int main(){
	n=read();
	ycl[0]=1;
	for(int i=1;i<=n;i++){ycl[i]=ycl[i-1]*2%mod; tong[read()]++;}
	heshu[1]=miu[1]=1;
	for(int i=1;i<N;i++){
		if(!heshu[i]){
			q[++tot]=i; miu[i]=-1; 
		}
		for(int j=1;i*q[j]<N&&j<=tot;j++){
			heshu[i*q[j]]=1;
			if(i%q[j]==0){
				miu[i*q[j]]=0; break;
			}
			miu[i*q[j]]=-miu[i];
		}
	}
	For(i,1,tot){
		int meiju=(N-1)/q[i];
		Rep(j,meiju,1)tong[j]+=tong[j*q[i]];
	}
	For(i,1,N-1)g[i]=ycl[tong[i]]-1;
	//Rep(i,N-1,1)for(int j=i+i;j<N;j+=i)g[i]=(g[i]-g[j])%mod;
	For(i,1,tot){
		int meiju=(N-1)/q[i];
		For(j,1,meiju)g[j]-=g[j*q[i]];
	}
	For(i,1,N-1){g[i]%=mod; f[i]=tong[i]*miu[i];}
	For(i,1,tot){
		int meiju=(N-1)/q[i];
		For(j,1,meiju)f[j*q[i]]+=f[j];
	}
	
	For(i,1,N-1){
		//if(g[i])cout<<i<<" "<<g[i]<<" "<<miu[i]<<" "<<f[i]<<endl;
		if(i>1)ans=(ans+(ll)g[i]*f[i])%mod;
	}
	cout<<(ans+mod)%mod<<endl;
}