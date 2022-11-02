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
#define SZ(x) ((int)(x.size()))
#define re resize
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
ll rnd(){
	ull ans=0;
	For(i,0,4)ans=ans<<15^rand();
	return ans%((ull)1<<63);
}
const int N=100005;
vector<int> v[N];
int n,x,y,tot,fff,m2[N],cnt[N],q[N],vis[N],ab[N],mm[N],mx[N],fa[N];
void dfs(int p){
	for(auto i:v[p])if(i!=fa[p]){
		fa[i]=p; dfs(i);
	}
}
void bao(int p){
	mx[p]=1;
	cnt[p]=0;
	for(auto i:v[p])if(i!=fa[p]){
		bao(i);
		if(mx[i]+1>mx[p]){
			m2[p]=mx[p]; mx[p]=mx[i]+1;
		}else{
			m2[p]=max(m2[p],mx[i]+1);
		}
		
		if(mx[i]+1>=tot)cnt[p]++;
	} //cout<<p<<" "<<fa[p]<<" "<<mx[p]<<" "<<cnt[p]<<endl;
}
void ddd(int p){
	mm[p]=1;
	for(auto i:v[p])if(i!=fa[p]&&!vis[i]){
		ddd(i);
		mm[p]=max(mm[i]+1,mm[p]);
	}
}
void bbb(int p){
	if((ab[p]>=tot)+cnt[p]>=3)fff=1;
	//cout<<fa[p]<<" "<<p<<" "<<ab[p]<<" "<<cnt[p]<<endl;
	for(auto i:v[p])if(i!=fa[p]){
		ab[i]=max(ab[i],ab[p]+1);
		if(mx[i]+1==mx[p])ab[i]=max(ab[i],m2[p]+1); else ab[i]=max(ab[i],mx[p]+1);
		bbb(i);
	}
}
int main(){
	#ifdef Brollan
		freopen("std.in","r",stdin);
	#endif
	int T=read();
	For(o,1,T){
		
		n=read(),x=read(),y=read();
		//if(o==19)cerr<<n<<" "<<x<<" "<<y<<endl;
		For(i,1,n){
			v[i].clear(); vis[i]=0; m2[i]=mx[i]=mm[i]=ab[i]=fa[i]=0;
		}
		For(i,1,n-1){
			int s=read(),t=read();
			v[s].pb(t); v[t].pb(s);
		}
		dfs(x);
		tot=fff=0;ab[x]=1;
		for(int i=y;i!=x;i=fa[i])q[++tot]=i; q[++tot]=x;
		For(i,1,tot)vis[q[i]]=1;
		bao(x);
		bbb(x);
		//cout<<ab[4]<<" "<<mx[4]<<" "<<fff<<" "<<ab[1]<<endl;
		if(!fff){
			puts("NO"); continue;
		}
		For(i,1,tot)ddd(q[i]);
		int dx=1,dy=tot,Dx=1,Dy=tot;
		while(dx<=Dx||dy>=Dy){
			int p=dx<=Dx?q[dx]:q[dy];
			//cout<<dx<<" "<<dy<<" "<<p<<" "<<mm[p]<<endl;
			if(mm[p]>=tot){fff=0; break;}
			if(dx<=Dx){
				Dy=min(Dy,tot-(mm[p]-dx));
				dx++;
			}else{
				Dx=max(Dx,1+(mm[p]-(tot-dy+1)));
				dy--;
			}
		}
		if(fff)puts("NO"); else puts("YES");
	}
	
}