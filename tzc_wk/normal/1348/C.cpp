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
int n,k,cnt[26];
char s[100005];
inline void solve(){
	cin>>n>>k>>s+1;
	fill0(cnt);
	fz(i,1,n)	cnt[s[i]-'a']++;
	int t=0;
	while(!cnt[t])	t++;
	bool flag=1;
	fz(i,t+1,25)	if(cnt[i])	flag=0;
	if(flag){
		fz(i,1,(cnt[t]-1)/k+1)	putchar(t+'a');
		puts("");
		return;
	}
	int old_t=t,tmp_k=k;
	cnt[t]--;tmp_k--;
	while(tmp_k&&t<=25){
		if(cnt[t])	cnt[t]--,tmp_k--;
		else		t++;
	}
	putchar(t+'a');
	if(t!=old_t){
		puts("");
		return;
	}
	while(!cnt[t])	t++;
	flag=0;
	fz(i,t+1,25)	if(cnt[i])	flag=1;
	if(flag){
		fz(i,t,25)	fz(j,1,cnt[i])	putchar(i+'a');
		puts("");
	}
	else{
		fz(i,1,(cnt[t]-1)/k+1)	putchar(t+'a');
		puts("");
	}
}
signed main(){
	int T=read();
	while(T--)	solve();
	return 0;
}