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
char s[100005],ss[200005];
int n,len=0,z[200005],buc[200005],suf[200005];
signed main(){
	cin>>s+1;
	n=strlen(s+1);
	for(int i=1;i<=n;i++)	ss[len++]=s[i];
	ss[len++]='|';
	for(int i=1;i<=n;i++)	ss[len++]=s[i];
	int l=0,r=0;
	for(int i=1;i<len;i++){
		if(i<=r)	z[i]=min(z[i-l],r-i);
		while(i+z[i]<len&&ss[i+z[i]]==ss[z[i]])	z[i]++;
		if(i+z[i]>r){
			l=i;r=i+z[i];
		}
	}
	int cnt=0;
	vector<int> v;
	for(int i=n+1;i<=(n<<1);i++){
		if(z[i]==(n<<1)-i+1){
			cnt++;
			v.push_back((n<<1)-i+1);
		}
		buc[z[i]]++;
	}
	reverse(all(v));
	fd(i,n,1)	suf[i]=suf[i+1]+buc[i];
	cout<<cnt<<endl;
	foreach(it,v){
		cout<<*it<<" "<<suf[*it]<<endl;
	}
	return 0;
}