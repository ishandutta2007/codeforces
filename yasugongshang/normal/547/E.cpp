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
const int N=200005,K=26,M=N*40;
vector<int> v[N];
int bj[N],go[N][K],fail[N],rt[N],tr[M],ls[M],rs[M];
int n,q,nodecnt,tot=1;
string s[N];
void buildAC(){
	For(i,0,K-1)go[0][i]=1;
	queue<int> q;q.push(1);
	while(q.size()){
		int t=q.front(); q.pop();
		For(i,0,K-1)if(go[t][i]){
			fail[go[t][i]]=go[fail[t]][i];
			q.push(go[t][i]);
		}else go[t][i]=go[fail[t]][i];
	}
}
void ins(int l,int r,int pos,int &nod){
	if(!nod)nod=++nodecnt;
	tr[nod]++; if(l==r)return;
	int mid=(l+r)>>1;
	if(pos<=mid)ins(l,mid,pos,ls[nod]); else ins(mid+1,r,pos,rs[nod]);
}
int ask(int l,int r,int i,int j,int nod){
	if(j<l||i>r)return 0;
	if(i<=l&&r<=j)return tr[nod];
	int mid=(l+r)>>1;
	return ask(l,mid,i,j,ls[nod])+ask(mid+1,r,i,j,rs[nod]);
}
int mer(int a,int b){
	if(!a||!b)return a|b;
	int k=++nodecnt;
	ls[k]=mer(ls[a],ls[b]);
	rs[k]=mer(rs[a],rs[b]);
	tr[k]=tr[a]+tr[b];
	return k;
}
void dfs(int p){
	for(auto i:v[p]){dfs(i); rt[p]=mer(rt[p],rt[i]);  }
	//cout<<p<<" fjz "<<tr[rt[p]]<<endl;
}
int main(){
	n=read(),q=read();
	For(i,1,n){
		int p=1;
		cin>>s[i];
		For(j,0,s[i].length()-1){
			s[i][j]-='a';
			int t=s[i][j];
			if(!go[p][t])go[p][t]=++tot;
			p=go[p][t];
		}
		bj[i]=p;
	}
	buildAC();
	For(i,2,tot)v[fail[i]].pb(i);
	//For(i,1,tot)cout<<i<<" "<<fail[i]<<endl;
	For(i,1,n){
		int p=1;
		For(j,0,s[i].length()-1){
			p=go[p][s[i][j]];
			ins(1,n,i,rt[p]);
		}
	}
	dfs(1);
	while(q--){
		int l=read(),r=read(),k=read();
		//cout<<bj[k]<<endl;
		writeln(ask(1,n,l,r,rt[bj[k]]));
	}
}