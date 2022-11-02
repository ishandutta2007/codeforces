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
const int N=5005;
void GG(){
	puts("NO"); exit(0);
}
vector<int> s[2],S[N][2];
int col[N],nn[3],ans[N];
vector<int> v[N];
bitset<N> f[N];
void dfs(int p,int c){
	if(col[p]==-1)col[p]=c;
	else if(col[p]!=c)GG();
	else return;
	s[c].pb(p);
	for(auto i:v[p])dfs(i,c^1);
}
int main(){
	#ifdef Brollan
		freopen("1.in","r",stdin);
	#endif
	int n=read(),m=read();
	For(i,0,2)nn[i]=read();
	while(m--){
		int s=read(),t=read();
		v[s].pb(t); v[t].pb(s);
	}
	nn[0]+=nn[2];
	memset(col,-1,sizeof(col));
	f[0][0]=1;
	int tot=0;
	For(i,1,n)if(col[i]==-1){
		s[0].clear(); s[1].clear();
		dfs(i,0);
		tot++; S[tot][0]=s[0]; S[tot][1]=s[1];
		f[tot]=(f[tot-1]<<s[0].size())|(f[tot-1]<<s[1].size());
	}
	if(!f[tot][nn[0]])GG();
	int dq=nn[0];
	Rep(i,tot,1){
		if(dq>=S[i][0].size()&&f[i-1][dq-S[i][0].size()]){
			dq-=S[i][0].size();
			for(auto j:S[i][1])ans[j]=1;
		}else{
			dq-=S[i][1].size();
			for(auto j:S[i][0])ans[j]=1;
		}
	}
	nn[0]-=nn[2];
	For(i,1,n)if(!ans[i]){
		if(!nn[0])
			ans[i]=2;
		else nn[0]--;
	}
	puts("YES");
	For(i,1,n)write(ans[i]+1);
}