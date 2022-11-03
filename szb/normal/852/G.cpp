#include<queue>
#include<algorithm> 
#include<bitset> 
#include<memory.h> 
#include<set>
#include<map>
#include<cstring>
#include<cstdio> 
#include<cmath> 
#define maxn 100010
#define ll long long
#define pa pair<ll,ll>
#define ld long double 
#define For(i,x,y)  for(ll i=x;i<=y;++i) 
#define FOr(i,x,y)  for(ll i=x;i>=y;--i) 
using namespace std; 
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; } 
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  } 
inline void writeln(ll x){ write(x);   puts("");   }
map<ll,ll>mp;	const ll mod=1e15+7;
ll bin[maxn],q[maxn],tot,S,now,ans,m,n;
char s[maxn];
set<ll> ss;
void dfs(ll p,ll now){
	if (p>S){	if (ss.count(now)) return; ss.insert(now);	ans+=mp[now];	return;	}
	if (s[p]!='?'){
		dfs(p+1,(now*31+s[p]-'a'+1)%mod);
		return;
	}
	dfs(p+1,now);
	For(i,1,5)	dfs(p+1,(now*31+i)%mod);
}
int main(){
	bin[0]=1;	For(i,1,100)	bin[i]=bin[i-1]*31%mod;
	n=read();	m=read();
	//writeln(mod);
	For(i,1,n){
		scanf("%s",s+1);	S=strlen(s+1);	ll hash=0;
		For(j,1,S)	hash=(hash*31+s[j]-'a'+1)%mod;
		mp[hash]++;
		//writeln(hash);
	}
	For(i,1,m){
		scanf("%s",s+1);	S=strlen(s+1);	tot=0;	now=0;	ans=0;
		dfs(1,now);	writeln(ans);	ss.clear();
	}
}