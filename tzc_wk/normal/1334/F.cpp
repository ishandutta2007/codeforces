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
//#define int long long
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
int n=read(),a[1000005],p[1000005],m,b[1000005];
long long dp[1000005];
long long bit[1000005];
inline void modify(int x,int v){
	for(int i=x;i<=n;i+=(i&(-i)))	bit[i]+=v;
}
inline long long query_single(int x){
	if(!x)	return 0;
	long long ans=0;
	for(int i=x;i;i-=(i&(-i)))	ans+=bit[i];
	return ans;
}
inline long long query(int l,int r){
	return query_single(r)-query_single(l-1);
}
vector<int> pos[1000005];
signed main(){
	fz(i,1,n)	a[i]=read();
	fz(i,1,n)	p[i]=read(),modify(i,p[i]);
	m=read();
	fz(i,1,m)	b[i]=read();
	fz(i,1,m)	if(b[i]<=b[i-1])	return puts("NO"),0;
	int cur=1;
	fz(i,1,n)	if(a[i]==b[cur])	cur++;
	if(cur!=m+1)	return puts("NO"),0;
	puts("YES");
	fz(i,1,n){
		pos[a[i]].push_back(i);
	}
	fillbig(dp);dp[0]=0;
	pos[0].push_back(0);
	fz(i,1,m){
		int now=0;
		for(int j=0;j<pos[b[i]].size();j++){
    		int _p=pos[b[i]][j];
    		if(j)
				dp[_p]=min(dp[_p],dp[pos[b[i]][j-1]]+query(pos[b[i]][j-1],_p-1));
    		
			while(now<(int)(pos[b[i-1]].size())&&pos[b[i-1]][now]<=_p){
    			int _q=pos[b[i-1]][now];
    			dp[_p]=min(dp[_p],dp[_q]+query(_q+1,_p-1));
    			now++;
    		}
    	}
    	if(i!=m+1)
			fz(j,b[i-1]+1,b[i])
				foreach(k,pos[j])
					if(p[*k]>0)
						modify(*k,-p[*k]);
	}
//	fz(i,1,n)	cout<<dp[i]<<endl;
	long long ans=0x3f3f3f3f3f3f3f3fll;
	fz(i,1,n){
		if(a[i]==b[m]){
			ans=min(ans,dp[i]+query(i+1,n));
		}
	}
	cout<<ans<<endl;
	return 0;
}