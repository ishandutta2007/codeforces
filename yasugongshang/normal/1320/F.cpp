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
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvvvi vector<vvvi>
vvi a[6],A[6];
vvvi vis;
struct da{
	int x,y,z;
};
int cnt[200005];
vector< vector<vector<vector<da> > > > v; 
int n,m,k,N[6],M[6];
da get(da jb){
	int id=jb.x,x=jb.y,y=jb.z;
	if(id<2)return (da){A[id][x][y],x,y};
	else if(id<4) return(da){x,A[id][x][y],y};
	else return (da){x,y,A[id][x][y]};
}
void GG(){
	puts("-1"); exit(0);
}
bool ou(int x,int l,int r){
	return x<l||x>r;
}
void ins(da zs);
void bao(da zs){
	int id=zs.x,x=zs.y,y=zs.z; 
	A[id][x][y]+=id%2?-1:1; 
	ins(zs);
}
void erase(da zb){//cout<<zb.x<<" "<<zb.y<<" "<<zb.z<<endl;
	vis[zb.x][zb.y][zb.z]=0;
	vector<da> wzp;
	swap(wzp,v[zb.x][zb.y][zb.z]);
	for(auto i:wzp)bao(i);
}
void ins(da zs){
	da zb=get(zs);
	int id=zs.x,x=zs.y,y=zs.z; // cout<<id<<" "<<x<<" "<<y<<" "<<zb.x<<" "<<zb.y<<" "<<zb.z<<endl;
	if(ou(zb.x,1,n)||ou(zb.y,1,m)||ou(zb.z,1,k)){
		if(a[id][x][y])GG();
		return;
	}
	if(vis[zb.x][zb.y][zb.z]){
		v[zb.x][zb.y][zb.z].pb(zs);
		if(!a[id][x][y])erase(zb);
		set<int> s;
		for(auto i:v[zb.x][zb.y][zb.z])s.insert(a[i.x][i.y][i.z]);
		if(s.size()==2)erase(zb);
	}else{
		bao(zs);
	}  
}
int main(){
	n=read(); m=read(); k=read();
	For(i,0,5){
		N[i]=i/2?n:m;
		M[i]=i/2==2?m:k;
		a[i].assign(N[i]+2,vi(M[i]+2,0));
		A[i].assign(N[i]+2,vi(M[i]+2,0));
	}
	v.resize(n+2); vis.resize(n+2);
	For(i,1,n){
		v[i].resize(m+2); vis[i].resize(m+2);
		For(j,1,m){
			v[i][j].resize(k+2); vis[i][j].resize(k+2);
		}
	}
	For(i,0,5){
		For(j,1,N[i]){
			For(o,1,M[i]){
				A[i][j][o]=i%2?n+m+k-N[i]-M[i]:1;
	//if(i==1)cout<<A[i][j][k]<<" fjzzq "<<n+m+k-N[i]-M[i]<<" "<<n+m+k<<" "<<N[i]+M[i]<<endl;
				a[i][j][o]=read();
			}
		}
	}
	For(i,1,n)For(j,1,m)For(o,1,k)vis[i][j][o]=1;
	For(i,0,5){
		For(j,1,N[i]){
			For(o,1,M[i]){
				ins((da){i,j,o});
			}
		}
	}
	For(i,1,n){
		For(j,1,m){
			For(o,1,k){
				if(v[i][j][o].size()){
					da t=v[i][j][o][0];
					wri(a[t.x][t.y][t.z]);
				}else wri(0);
			}
			puts("");
		}
		puts("");
	}
}