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
int T=read(),n;
char s[5005],ss[10005];
int len[10005];
int cnt=0,ans=0,ansl=0,ansind=0,anslen=0;
inline void manacher(int l,int r){
	fill0(ss);cnt=1;
	ss[0]='!';ss[1]='@';
	fz(i,l,r)	ss[++cnt]=s[i],ss[++cnt]='@';
//	cout<<ss<<endl;
	fill0(len);
	int pos=0,mx=0;
	for(int i=1;i<=cnt;i++){
		len[i]=i<mx?min(len[pos*2-i],mx-i):1;
		while(ss[i-len[i]]==ss[i+len[i]]) len[i]++;
		if(i+len[i]>mx)	mx=i+len[i],pos=i;
//		cout<<len[i]<<" ";
	}
//	puts("");
	fz(i,1,cnt){
		if(i-len[i]+1==1||i+len[i]-1==cnt){
			int _ans=len[i]-1+(l-1)*2;
			if(ans<_ans){
				ans=_ans;
				ansl=l;
				ansind=i;
				anslen=len[i];
			}
		}
	}
}
inline void solve(){
	ans=0;ansl=0,anslen=0,ansind=0;
	cin>>s+1;
	n=strlen(s+1);
	int l=0,r=n+1;
	while(s[l+1]==s[r-1]&&l+1<r-1)	l++,r--;
//	cout<<l<<" "<<r<<endl;
	fz(_l,1,l+1){
		manacher(_l,n+1-_l);
	}
	cnt=1;
	ss[0]='!';ss[1]='@';
	fz(i,ansl,n+1-ansl)	ss[++cnt]=s[i],ss[++cnt]='@';
//	cout<<ss<<endl<<ansl-1<<" "<<ansind<<" "<<anslen<<endl;
	fz(i,1,ansl-1)	cout<<s[i];
	fz(i,ansind-anslen+1,ansind+anslen-1){
		if(ss[i]!='@')	cout<<ss[i];
	}
	fz(i,n-ansl+2,n)	cout<<s[i];puts("");
}
signed main(){
	while(T--)	solve();
	return 0;
}