#include<bits/stdc++.h>
using namespace std; 
#define ll int
#define rep(i,x,y)  for(ll i=x;i<y;++i)
#define For(i,x,y)  for(ll i=x;i<=y;++i) 
#define FOr(i,x,y)  for(ll i=x;i>=y;--i) 
#define pi acos(-1)
#define mk make_pair<ll,ll>
#define pa pair<ll,ll>
#define fi first
#define se second
#define max(x,y)    ((x)<(y)?(y):(x))
#define min(x,y)    ((x)<(y)?(x):(y))    
#define EXIT(x)	return writeln(x),0;
typedef complex<double> E;
namespace SHENZHEBEI{
#ifdef LOCAL
	struct _{_(){freopen("cf.in","r",stdin);}}_;
#endif 
#define NEG 1
    const int L=2333333;
    char SZB[L],*S=SZB,*T=SZB;
    inline char gc(){   if (S==T){  T=(S=SZB)+fread(SZB,1,L,stdin); if (S==T) return '\n';  }   return *S++;    }
#if NEG
    inline ll read(){    ll x=0,f=1; char ch=gc();   for (;!isdigit(ch);ch=gc()) if (ch=='-') f=-1;  for (;isdigit(ch);ch=gc())  x=x*10-48+ch;   return x*f; }
    inline void write(ll x){    if (x<0) putchar('-'),x=-x;  if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#else
    inline ll read(){    ll x=0; char ch=gc();   for (;!isdigit(ch);ch=gc());    for (;isdigit(ch);ch=gc())  x=x*10-48+ch;   return x;   }
    inline void write(ll x){    if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#endif
    inline char readchar(){ char ch=gc();   for(;isspace(ch);ch=gc());  return ch;  }
    inline ll readstr(char *s){ char ch=gc();   int cur=0;  for(;isspace(ch);ch=gc());      for(;!isspace(ch);ch=gc())  s[cur++]=ch;    s[cur]='\0';    return cur; }
    inline void writeln(ll x){  write(x);   puts("");   }
}using namespace SHENZHEBEI;
const ll N=30010;
vector<pa>h[N];
ll pre[N],id[N],q[210][N],a[210][N],vis[N],n,k;
int main(){
	n=read();	k=read();
	For(i,1,k){	For(j,1,n)	if (!(a[i][j]=read()))	id[i]=j;	if (!id[i])	EXIT(-1)	}
	For(i,2,k){
		For(j,1,n)	if (a[1][j]+a[i][j]==a[1][id[i]])	q[i][a[1][j]]=j,vis[j]=1;
		FOr(j,a[1][id[i]],1){	if (!q[i][j])	EXIT(-1)	pre[q[i][j]]=q[i][j-1];	}
	}vis[id[1]]=1;
	For(i,1,n)	if (!vis[i]){
		ll cho=id[1],mn=0,now;
		For(j,2,k)	if ((now=(a[1][id[j]]+a[1][i]-a[j][i])/2)>=mn)	mn=now,cho=q[j][now];
		h[cho].push_back(mk(a[1][i],i));
	}
	For(lzh,1,n){
		sort(h[lzh].begin(),h[lzh].end());
		for(ll i=0,las=a[1][lzh],cur=lzh;i<h[lzh].size();pre[h[lzh][i].se]=cur,cur=h[lzh][i++].se){
			if (++las^h[lzh][i].fi)	EXIT(-1)
			while((i<h[lzh].size()-1)&&(h[lzh][i+1].fi==las))	pre[h[lzh][i++].se]=cur;
		}
	}
	For(i,1,n)	if (pre[i])	printf("%d %d\n",pre[i],i);
}
/*
10 3
x 0 7 0 0 9 6 0 0 9
2 2 3 1 2 1 2 1 0 1
0 4 5 3 4 3 4 3 2 1
5 5 0 4 3 2 1 4 3 4
*/