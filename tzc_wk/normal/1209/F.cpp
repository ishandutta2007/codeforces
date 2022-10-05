//Coded by tzc_wk
/*




D P 




 l l
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define giveup(...) return printf(__VA_ARGS__),0;
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define fillsmall(a) memset(a,0xcf,sizeof(a))
#define mask(a)		(1ll<<(a))
#define maskx(a,x)	((a)<<(x))
#define _bit(a,x)	(((a)>>(x))&1)
#define _sz(a)		((int)(a).size())
#define filei(a)	freopen(a,"r",stdin);
#define fileo(a)	freopen(a,"w",stdout);
#define fileio(a) 	freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
#define y1			y_chenxiaoyan_1
#define y0			y_chenxiaoyan_0
#define int long long
typedef pair<int,int> pii;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	neg=-1;
		c=getchar();
	}
	while(isdigit(c))	x=x*10+c-'0',c=getchar();
	return x*neg;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		print(abs(x));
		return;
	}
	if(x<=9)	putchar(x+'0');
	else{
		print(x/10);
		putchar(x%10+'0');
	}
}
inline int qpow(int x,int e,int _MOD){
	int ans=1;
	while(e){
		if(e&1)	ans=ans*x%_MOD;
		x=x*x%_MOD;
		e>>=1;
	}
	return ans;
}
int n=read(),m=read(),cnt=n;
vector<int> g[2000005][10];
inline void add(int x,int y,int z){
	vector<int> t;
	while(z){t.push_back(z%10);z/=10;}
	reverse(all(t));
	int cur=x;
	for(int i=0;i<t.size();i++){
		int nxt=(i==t.size()-1)?y:++cnt;
		g[cur][t[i]].push_back(nxt);
		cur=nxt;
	}
}
const int MOD=1e9+7;
queue<vector<int> > q;
bool vis[2000005];
int dist[2000005];
signed main(){
	dist[1]=0;vis[1]=1;
	fz(i,1,m){
		int x=read(),y=read();
		add(x,y,i);
		add(y,x,i);
	}
	vector<int> tmp;
	tmp.push_back(1);
	q.push(tmp);
	while(!q.empty()){
		vector<int> v=q.front();q.pop();
		for(int j=0;j<10;j++){	
			vector<int> nxt;
			for(int i=0;i<v.size();i++){
				int x=v[i];
				foreach(it,g[x][j]){
					int y=*it;
					if(vis[y])	continue;
					vis[y]=1;nxt.push_back(y);
					dist[y]=(dist[x]*10+j)%MOD;
				}	
			}
			if(!nxt.empty())	q.push(nxt);
		}
	}
	fz(i,2,n)	cout<<dist[i]<<endl;
	return 0;
}