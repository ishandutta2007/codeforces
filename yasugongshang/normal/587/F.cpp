#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<int>
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define mem(a) memset((a),0,sizeof(a))
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
const int N=100005,K=26,B=300;
int tot=1,ti,a[N],A[N],L[N],R[N],bel[N],to[N],go[N][K],fail[N],q[N],jb[N],l[N],r[N],k[N],in[N],out[N];
ll ans[N],S[N];
string s[N];
vector<int> v[N],V[N],e[N];
void dfs(int p){
	in[p]=++ti;
	for(auto i:e[p])dfs(i);
	out[p]=ti;
}
void build(){
	For(i,0,K-1)go[0][i]=1;
	q[++*q]=1;
	For(i,1,*q){
		int p=q[i]; //cout<<p<<" "<<fail[p]<<endl;
		For(i,0,K-1)if(go[p][i]){fail[go[p][i]]=go[fail[p]][i]; q[++*q]=go[p][i];}
		else go[p][i]=go[fail[p]][i];
	}
	For(i,2,tot)e[fail[i]].pb(i);
	dfs(1);
}
void ins(int l,int r){
	if(bel[l]==bel[r]){
		For(i,l,r)a[i]++; return;
	}
	For(i,l,R[bel[l]])a[i]++;
	For(i,L[bel[r]],r)a[i]++;
	For(i,bel[l]+1,bel[r]-1)A[i]++;
}
inline int ask(int x){
	return a[x]+A[bel[x]];
}
int main(){
	int n=read(),Q=read();
	For(i,1,n){
		cin>>s[i];
		int p=1;
		For(j,0,s[i].length()-1){
			int t=s[i][j]-'a';
			if(!go[p][t])go[p][t]=++tot;
			p=go[p][t];
		}
		jb[i]=p;
	}
	build();
	For(i,1,Q){
		l[i]=read(); r[i]=read(); k[i]=read();
		if(s[k[i]].length()>B){
			V[k[i]].pb(i);
		}else{
			v[l[i]-1].pb(i);
			v[r[i]].pb(i);
		}
	}
	For(i,1,n)if(s[i].length()>B){
		int p=1;
		mem(to);
		For(j,0,s[i].length()-1){p=go[p][s[i][j]-'a']; to[p]++;}
		Rep(j,tot,1)to[fail[q[j]]]+=to[q[j]];
		For(k,1,n)S[k]=S[k-1]+to[jb[k]];
		for(auto j:V[i])ans[j]=S[r[j]]-S[l[j]-1];
	}
	For(i,1,tot){
		if((i-1)%B==0)L[bel[i]=bel[i-1]+1]=i; else bel[i]=bel[i-1];
		R[bel[i]]=i;
	}
	For(i,1,n){
		ins(in[jb[i]],out[jb[i]]); //cout<<in[jb[i]]<<" fjzq "<<out[jb[i]]<<" "<<jb[i]<<endl;
		for(auto j:v[i]){
			int id=k[j],sum=0,o=1;
			For(k,0,s[id].length()-1){
				sum+=ask(in[o=go[o][s[id][k]-'a']]);
				//cout<<in[o]<<" "<<ask(in[o])<<endl;
			}
			ans[j]+=(i==r[j]?1:-1)*sum;
		}
	}
	For(i,1,Q)writeln(ans[i]);
}