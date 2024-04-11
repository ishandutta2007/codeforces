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
int x=read(),y=read();
int a[62],b[62];
signed main(){
	if(x>y||(x&1)!=(y&1))	return puts("-1"),0;
	if(!x&&!y)	return puts("0"),0;
	if(x==y)	return cout<<"1\n"<<x<<endl,0;
	int dif=(y-x)/2;
	bool flag=1;
	for(int i=0;i<=62;i++){
		int dig1=dif>>i&1;
		int dig2=x>>i&1;
		if(dig1&&dig2)	flag=0;
	}
	if(flag){
		int a=0,b=0;
		for(int i=62;i>=0;i--){
//			cout<<i<<endl;
			int dig1=dif>>i&1;
			int dig2=x>>i&1;
			if(dig1){
				a=(a<<1|1);
				b=(b<<1|1);
			}
			if(dig2)	a=(a<<1|1),b=b<<1;
			if(!dig1&&!dig2)	a=a<<1,b=b<<1;
		}
		cout<<"2\n"<<a<<" "<<b<<endl;
		return 0;
	}
	cout<<3<<endl;
	int a=0,b=0,c=0;
	for(int i=62;i>=0;i--){
		int dig1=dif>>i&1;
		int dig2=x>>i&1;
		if(dig1&&!dig2) 	a=(a<<1|1),b=(b<<1|1),c=c<<1;
		if(dig2&&!dig1)		a=(a<<1|1),b=b<<1,c=c<<1;
		if(dig1&&dig2)		a=(a<<1|1),b=(b<<1|1),c=(c<<1|1);
		if(!dig1&&!dig2)	a=a<<1,b=b<<1,c=c<<1;
	}
	cout<<a<<" "<<b<<" "<<c<<endl;
	return 0;
}