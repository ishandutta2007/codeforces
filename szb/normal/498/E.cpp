#include<bits/stdc++.h>
#define ll long long
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
#define For(i,x,y)	for(ll i=x;i<=y;++i)
using namespace std;
namespace SHENZHEBEI{
#ifdef LOCAL
	struct szb{	szb(){	freopen("shenzhebei.in","r",stdin);	}	}shenzhebei;
#endif
#define NEG 0
	const int L=2333333;
	char SZB[L],*S=SZB,*T=SZB;
	inline char gc(){	if (S==T){	T=(S=SZB)+fread(SZB,1,L,stdin);	if (S==T) return '\n';	}	return *S++;	}
#if NEG
	inline ll readint(){	ll x=0,f=1;	char ch=gc();	for (;!isdigit(ch);ch=gc())	if (ch=='-') f=-1;	for (;isdigit(ch);ch=gc())	x=x*10-48+ch;	return x*f;	}
	inline void write(ll x){	if (x<0)	putchar('-'),x=-x;	if (x>=10)	write(x/10);	putchar(x%10+'0');	}
#else
	inline ll readint(){	ll x=0;	char ch=gc();	for (;!isdigit(ch);ch=gc());	for (;isdigit(ch);ch=gc())	x=x*10-48+ch;	return x;	}
	inline void write(ll x){	if (x>=10)	write(x/10);	putchar(x%10+'0');	}
#endif
	inline char readchar(){	char ch=gc();	for(;isspace(ch);ch=gc());	return ch;	}
	inline ll readstr(char *s){	char ch=gc();	int cur=0;	for(;isspace(ch);ch=gc());		for(;!isspace(ch);ch=gc())	s[cur++]=ch;	s[cur]='\0';	return cur;	}
	inline void writeln(ll x){	write(x);	puts("");	}
}using namespace SHENZHEBEI;
const ll mod=1e9+7;
struct data{	ll m[130][130];	}st,zy,tmp;
ll bin[10],a[10],b[10],m,ck=0;
void add(ll &x,ll y){	x=(x+y)%mod;	}
data operator *(data a,data b){
	memset(tmp.m,0,sizeof tmp.m);
	For(i,0,m)	For(k,0,m)	For(j,0,m)
	add(tmp.m[i][j],a.m[i][k]*b.m[k][j]);
return tmp;
}
inline ll work(ll l,ll r,ll n){
	if (!n)	return l|r;
	ll sum=0;
	For(i,0,(1<<n)-1){
		ll ans=1;
		For(j,0,n)	ans&=(j==0?0:(i>>(j-1)&1))||(j==n?0:(i>>j&1))||(l>>j&1)||(r>>j&1);
		sum+=ans;
	}return sum%mod;
}
int main(){
	For(i,0,6)	b[i]=a[i]=readint();
	st.m[0][0]=1;
	For(i,0,6)	if (a[i]){
		memset(zy.m,0,sizeof zy.m);	m=(1<<(i+1))-1;
		For(S,0,(1<<(i+1))-1)	For(T,0,(1<<(i+1))-1)	zy.m[S][T]=work(S,T,i);
		while(a[i]){
			if (a[i]&1)	st=st*zy;	zy=zy*zy;
			a[i]>>=1;
		}
	}
	FOr(i,6,0)	if (b[i])	return writeln(st.m[0][0]),0;
}