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
const int N=200005;
int fa[N];
bitset<1<<18|2> bj;
vector<int> v[1<<18|2];
ll ans;
inline int gf(int x){
	return fa[x]==x?x:fa[x]=gf(fa[x]);
}
inline int mer(int x,int y){
	x=gf(x); y=gf(y);
	if(x!=y){
		fa[x]=y; return 1;
	}
	return 0;
}
int main(){
	int n=read();
	v[0].pb(0);
	For(i,1,n)v[read()].pb(fa[i]=i);
	Rep(i,(1<<18)-1,1){
		int zs=i&-i,jb=i^zs; 
		for(int j=jb;;j=(j-1)&jb){
			if(v[j].size()&&v[i-j].size()){//cout<<j<<" "<<i-j<<endl;
				if(!bj[j]){
					For(k,1,v[j].size()-1)ans+=mer(v[j][0],v[j][k])*i; bj[j]=1;
				}
				if(!bj[i-j]){
					for(auto k:v[i-j])ans+=mer(v[j][0],k)*i; bj[i-j]=1;
				}else ans+=mer(v[j][0],v[i-j][0])*i;
				
			}
			if(!j)break;
		}
	}
	For(i,0,(1<<18)-1)ans-=(ll)v[i].size()*i; 
	cout<<ans<<endl;
}