#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<int>
#define mem(a) memset((a),0,sizeof(a))
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define fi first
#define se second
#define SZ(x) ((int)(x.size()))
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
const int N=105,mod=998244353;
ll f[N],dp[N],DP[N<<1],val[N][N];
poly v[N],way[N][N],d[N];
PI a[N];
int n,rt,e[N][N],fir[N][N],lst[N][N],cover[N][N];
void dfs_way(int p,int fa){
	way[rt][p]=way[rt][fa]; way[rt][p].pb(p);
	for(auto i:v[p])if(i!=fa)dfs_way(i,p);
}
ll mul(PI a,PI b){
	return (ll)a.fi*b.se-(ll)a.se*b.fi;
}
PI operator -(PI a,PI b){
	return mp(a.fi-b.fi,a.se-b.se);
}
bool cmp(int x,int y){
	return a[x].se==a[y].se?a[x].fi<a[y].fi:a[x].se<a[y].se;
}
int half(PI x){
	return x.se<0||(x.se==0&&x.fi<0);
}
bool cnm(PI x,PI y){
	PI A=a[x.se]-a[x.fi],B=a[y.se]-a[y.fi];
	int X=half(A),Y=half(B);
	return X==Y?mul(A,B)>0:X<Y;
}

void dfs(int p,int fa){
	for(auto it=v[p].begin();it!=v[p].end();it++)if(*it==fa){v[p].erase(it); break;}
	d[p].pb(p);
	for(auto i:v[p]){
		dfs(i,p); for(auto j:d[i])d[p].pb(j);
	}
	f[p]=1;
	for(auto i:v[p])f[p]=f[p]*dp[i]%mod;
	dp[p]=f[p];
	for(auto i:v[p]){
		ll zs=f[i];
		for(auto j:v[p])if(i!=j)zs=zs*dp[j]%mod;
		dp[p]=(dp[p]+zs)%mod;
	}
	int k=0;
	mem(e);
	for(auto i:d[p])for(auto j:v[i]){
		e[i][j]=++k; e[j][i]=++k;
	}
	vector<PI> al;
	sort(d[p].begin(),d[p].end(),cmp);
	int m=d[p].size();
	for(auto i:d[p])for(auto j:d[p])if(way[i][j].size()>=3&&mul(a[j]-a[i],a[p]-a[i])>=0){
		al.pb(mp(i,j));
		int sz=way[i][j].size();
		fir[i][j]=e[way[i][j][0]][way[i][j][1]];
		lst[i][j]=e[way[i][j].back()][way[i][j][sz-2]];
		cover[i][j]=0; val[i][j]=1;
		For(o,0,sz-1){
			int x=o?way[i][j][o-1]:-1,y=o<=sz-2?way[i][j][o+1]:-1,dq=way[i][j][o];
			for(auto son:v[dq])if(son!=x&&son!=y){
				if(x<0){
					if(mul(a[y]-a[dq],a[son]-a[dq])>0)continue;
				}else if(y<0){
					if(mul(a[son]-a[x],a[dq]-a[x])<0)continue;
				}else{
					int A=mul(a[y]-a[dq],a[son]-a[dq])>0,B=mul(a[son]-a[x],a[dq]-a[x])<0;
					if(mul(a[dq]-a[x],a[y]-a[x])>0){
						if(A&&B)continue;
						//if(A||B)cout<<p<<" "<<x<<" "<<dq<<" "<<y<<" "<<son<<endl;
					}else{
						if(A||B)continue;
					}
				}
				val[i][j]=val[i][j]*dp[son]%mod;
				//cover[i][j]|=son==p;
				//if(i==3&&j==4&&p==4)cout<<son<<endl;
			}
			cover[i][j]|=dq==p;
		}
	}
	sort(al.begin(),al.end(),cnm);
	//if(p==1)for(auto i:al)cout<<i.fi<<" zyy "<<i.se<<endl;
	//if(p==4)For(i,0,m-1)cout<<d[p][i]<<endl;
	//if(p==4)cout<<e[4][2]<<endl;
	For(i,0,m-1)For(j,i+1,m-1)if(e[d[p][i]][d[p][j]]){
		//cout<<d[p][i]<<" fly "<<d[p][j]<<" "<<a[d[p][i]].se<<" "<<a[d[p][j]].se<<endl;
		for(int ban=-1;ban<=1;ban+=2){
			mem(DP);
			DP[e[d[p][i]][d[p][j]]]=1;
			for(auto o:al){
				if(ban==-1&&cover[o.fi][o.se])continue;
				int S=fir[o.fi][o.se],T=lst[o.fi][o.se];
				DP[T]=(DP[T]+DP[S]*val[o.fi][o.se])%mod;
				//if(p==1&&d[p][i]==4&&d[p][j]==6)cout<<o.fi<<" "<<o.se<<" "<<val[o.fi][o.se]<<endl;
			}
			DP[e[d[p][i]][d[p][j]]]+=mod-1;
			dp[p]+=ban*DP[e[d[p][i]][d[p][j]]];
			//if(p==1)cout<<d[p][i]<<" "<<d[p][j]<<" "<<dp[p]<<" "<<ban*DP[e[d[p][i]][d[p][j]]]<<endl;
		}
	}
	//cout<<dp[p]<<" dpdpdp "<<d[p].size()<<endl;
	dp[p]=(dp[p]%mod+mod)%mod;
}
int main(){
	#ifdef Brollan	
		freopen("1.in","r",stdin);
	#endif
	n=read();
	For(i,1,n){
		a[i].fi=read(); a[i].se=read();
	}
	For(i,1,n-1){
		int s=read(),t=read();
		v[s].pb(t); v[t].pb(s);
	}
	For(i,1,n){
		rt=i; dfs_way(i,0); 
		For(j,1,n){
			for(auto k:way[i][j])if(mul(a[j]-a[i],a[k]-a[i])<0){way[i][j].clear(); break;}
		}
	}
	dfs(1,0);
	cout<<dp[1]<<endl;
}
/*
4
0 -3
-5 -3
5 -5
4 5
3 1
4 1
1 2

*/