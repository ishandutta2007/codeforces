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
int n=read(),k=read();
char s[100005];
bool vis[1<<17],is[1<<17],hav[1<<17];
inline void deal(int x){
	if(vis[x])	return;vis[x]=1;
	fz(i,0,k-1){
		if(x>>i&1){
			int t=(x^(1<<i));
			deal(t);
			is[x]|=is[t];
		}
	}
}
inline void calc(int x,int y){
	fill0(is);fill0(vis);
	x--;y--;
	int l=0;
	fz(i,1,n){
		if(s[i]-'a'==x||s[i]-'a'==y){
			l=i;
			break;
		}
	}
	if(!l)	return;
	int r=l+1;
	while(l<=n){
		int sta=0;
		while(r<=n){
			if((s[l]-'a'+s[r]-'a')==x+y)	break;
			else if(s[l]==s[r]){
				l=r;r++;sta=0;
				continue;
			}
			sta|=(1<<(s[r]-'a'));
			r++;
		}
		if(r>n)	break;
		is[sta]=1;
		l=r;r++;
	}
	int sta=(1<<k)-1;
	sta^=(1<<x);
	if(x!=y)	sta^=(1<<y);
	deal(sta);
	for(int i=0;i<1<<k;i++)	hav[i]|=is[i];
}
int cnt[20];
signed main(){
	cin>>s+1;
	fz(i,1,n)	cnt[s[i]-'a']++;
	fz(i,1,k){
		fz(j,1,k){
			int t=read();
			if(!t)	calc(i,j);
		}
	}
	int ans=0;
	for(int i=1;i<(1<<k);i++){
		if(!hav[i]){
//			cout<<i<<endl;
			hav[i]=1;
			fz(j,0,k-1){
				if(i>>j&1&&!hav[i^(1<<j)])
					hav[i]=0;
			}
			if(!hav[i]){
				int sum=0;
				fz(j,0,k-1)
					if(i>>j&1)
						sum+=cnt[j];
				ans=max(ans,sum);
			}
		}
	}
	cout<<n-ans<<endl;
	return 0;
}