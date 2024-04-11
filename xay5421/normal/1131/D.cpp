#include<cstdio>
#include<vector>
#include<algorithm>
typedef long long ll;
#define int long long 
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
template<typename T>void read(T&x){int fl=0,ch;while(ch=getchar(),ch<48||57<ch)fl^=!(ch^45);x=(ch&15);while(ch=getchar(),47<ch&&ch<58)x=(x+(x<<2)<<1)+(ch&15);if(fl)x=-x;} 
template<typename T>void print(T x){if(x<0)x=-x,putchar('-');if(x>9)print(x/10);putchar(x%10+48);}
template<typename T>void print(T x,int ch){print(x),putchar(ch);}
int n,m,q[1005*1005],d[2005],fa[2005],ans[2005];
char s[1005][1005];
std::vector<int>g[2005];
int get(int x){return fa[x]==x?x:fa[x]=get(fa[x]);}
struct ed{ed*nxt;int to;}pool[1005*1005],*p=pool,*lnk[2005];
void add_e(int u,int v){*++p=(ed){lnk[u],v},lnk[u]=p,++d[v];}
signed main(){
	read(n),read(m);
	rep(i,1,n+m)fa[i]=i;
	rep(i,1,n)scanf("%s",s[i]+1);
	rep(i,1,n)rep(j,1,m)if(s[i][j]=='=')fa[get(i)]=get(j+n);
	rep(i,1,n+m)g[get(i)].push_back(i);
	rep(i,1,n)rep(j,1,m)if(get(i)==get(j+n)&&s[i][j]!='=')return puts("No");
	rep(i,1,n)rep(j,1,m){
		if(s[i][j]=='<')add_e(get(i),get(j+n));else
		if(s[i][j]=='>')add_e(get(j+n),get(i));
	}
	int he=0,ta=0,sum=0;
	rep(i,1,n+m)
		if(get(i)==i){
			++sum;
			if(!d[i])q[++ta]=i,ans[i]=1;
		}
	while(he!=ta){
		int u=q[++he];
		for(ed*i=lnk[u];i;i=i->nxt)if(!--d[i->to]){
			q[++ta]=i->to;
			ans[i->to]=std::max(ans[i->to],ans[u]+1);
		}
	}
	if(ta!=sum)return puts("No"),0;
	else{
		puts("Yes");
		rep(i,1,n)print(ans[get(i)],' ');puts("");
		rep(i,n+1,n+m)print(ans[get(i)],' ');puts("");
	}
	return 0;
}