#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<ll,ll>
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
const int N=300005,inf=1e9;
char ch[N];
int fa[N],bj[N],BJ[N],fy[N];
ll ans;
vector<int> v[N];
inline int gf(int x){
	if(fa[x]==x)return x;
	int f=gf(fa[x]);
	bj[x]^=bj[fa[x]];
	return fa[x]=f;
}
int main(){
	int n=read(),k=read();
	scanf("%s",ch+1);
	For(i,1,k){
		fa[i]=i; fy[i]=1;
		int c=read();
		For(j,1,c){
			v[read()].pb(i);
		}
	}
	For(i,1,n){
		int t=ch[i]=='0';
		for(auto j:v[i]){
			gf(j); t^=bj[j]^BJ[fa[j]];
			//cout<<i<<" fjzzq "<<j<<" "<<bj[j]<<endl;
		}
		vector<int> V;
		for(auto j:v[i])V.pb(gf(j));
		if(t){
			if(V.size()==2&&fy[V[1]]<fy[V[0]])swap(V[0],V[1]);
			BJ[V[0]]^=1;
			ans+=fy[V[0]];
			//if(i==3)cout<<i<<" "<<"fjz "<<vis[2]<<" "<<V[0]<<" "<<fy[V[0]]<<endl;
		}
		if(V.size()==2){
			int x=V[0],y=V[1];
			if(x!=y){
				//cout<<x<<" fj "<<y<<endl;
				fa[x]=y; swap(bj[x],BJ[x]); bj[x]^=BJ[y];
				fy[y]=t?fy[y]-fy[x]:min(inf,fy[y]+fy[x]);
			//	cout<<t<<" "<<y<<" fjzzq "<<fy[y]<<endl;	
			}
		}else if(V.size())fy[V[0]]=inf;
		writeln(ans);
	}
}