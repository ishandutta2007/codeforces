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
#define max(x,y)	((x)<(y)?(y):(x))
#define min(x,y)	((x)<(y)?(x):(y))	
typedef complex<double> E;
namespace SHENZHEBEI{
#define NEG 0
    const int L=2333333;
    char SZB[L],*S=SZB,*T=SZB;
    inline char gc(){   if (S==T){  T=(S=SZB)+fread(SZB,1,L,stdin); if (S==T) return '\n';  }   return *S++;    }
#if NEG
    inline ll readint(){    ll x=0,f=1; char ch=gc();   for (;!isdigit(ch);ch=gc()) if (ch=='-') f=-1;  for (;isdigit(ch);ch=gc())  x=x*10-48+ch;   return x*f; }
    inline void write(ll x){    if (x<0) putchar('-'),x=-x;  if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#else
    inline ll readint(){    ll x=0; char ch=gc();   for (;!isdigit(ch);ch=gc());    for (;isdigit(ch);ch=gc())  x=x*10-48+ch;   return x;   }
    inline void write(ll x){    if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#endif
    inline char readchar(){ char ch=gc();   for(;isspace(ch);ch=gc());  return ch;  }
    inline ll readstr(char *s){ char ch=gc();   int cur=0;  for(;isspace(ch);ch=gc());      for(;!isspace(ch);ch=gc())  s[cur++]=ch;    s[cur]='\0';    return cur; }
    inline void writeln(ll x){  write(x);   puts("");   }
}using namespace SHENZHEBEI;
const ll N=1000010;
char s1[N],s2[N],s3[N];
ll n,f[N],g[N],mn[N],tmp[N];
void exkmp(char t[],char s[],ll g[]){
	memset(tmp,0,sizeof tmp);
	tmp[1]=n;	ll mx=0,id=0;
	For(i,2,n){
		tmp[i]=max(min(tmp[i-mx+1],mx+tmp[mx]-i),0);
		while(i+tmp[i]<=n&&s[i+tmp[i]]==s[tmp[i]+1])	++tmp[i];
		if (i+tmp[i]>tmp[mx]+mx)	mx=i;
	}mx=0;
//	For(i,1,n)	printf("%d ",tmp[i]);	puts("");
	For(i,1,n){
		g[i]=max(min(tmp[i-mx+1],mx+g[mx]-i),0);
		while(i+g[i]<=n&&t[i+g[i]]==s[g[i]+1])	++g[i];
		if (i+g[i]>g[mx]+mx)	mx=i;
	}
}
int main(){
//	freopen("s.in","r",stdin);
	gets(s1+1);	n=strlen(s1+1);	gets(s2+1);
	if (n^strlen(s2+1))	return puts("-1 -1"),0;
	For(i,1,n)	s3[i]=s1[n-i+1];
	exkmp(s1,s2,f);	exkmp(s2,s3,g);
	For(i,0,n)	mn[i]=1e9;
	FOr(i,n,1)	mn[-g[i]+n-i+1]=i;
	For(i,1,n)	mn[i]=min(mn[i],mn[i-1]);
//	For(i,1,n)	writeln(mn[i]);
	ll lbc_ak=1;	while(lbc_ak<n&&s1[lbc_ak]==s2[n-lbc_ak+1])	++lbc_ak;	--lbc_ak;
//	writeln(lbc_ak);
	while(lbc_ak){
//		writeln(f[lbc_ak+1]);
		if (mn[lbc_ak]-1<=f[lbc_ak+1])	return printf("%d %d\n",lbc_ak-1,lbc_ak+mn[lbc_ak]-1),0;
		--lbc_ak;
	}
	puts("-1 -1");
}/*
namespace SHENZHEBEI{
#define NEG 0
    const int L=2333333;
    char SZB[L],*S=SZB,*T=SZB;
    inline char gc(){   if (S==T){  T=(S=SZB)+fread(SZB,1,L,stdin); if (S==T) return '\n';  }   return *S++;    }
#if NEG
    inline ll readint(){    ll x=0,f=1; char ch=gc();   for (;!isdigit(ch);ch=gc()) if (ch=='-') f=-1;  for (;isdigit(ch);ch=gc())  x=x*10-48+ch;   return x*f; }
    inline void write(ll x){    if (x<0) putchar('-'),x=-x;  if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#else
    inline ll readint(){    ll x=0; char ch=gc();   for (;!isdigit(ch);ch=gc());    for (;isdigit(ch);ch=gc())  x=x*10-48+ch;   return x;   }
    inline void write(ll x){    if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#endif
    inline char readchar(){ char ch=gc();   for(;isspace(ch);ch=gc());  return ch;  }
    inline ll readstr(char *s){ char ch=gc();   int cur=0;  for(;isspace(ch);ch=gc());      for(;!isspace(ch);ch=gc())  s[cur++]=ch;    s[cur]='\0';    return cur; }
    inline void writeln(ll x){  write(x);   puts("");   }
}using namespace SHENZHEBEI;
348E

12345

i,j
lcp j-i-1      n-j+1      i
    s[i+1,j-1] r[1,n-j+1] r[n-i+1,n]
    t[1,j-i-1] t[j-i,n-i] t[n-i+1,n]
lcp(t[1],s[i+1])>=j-i-1
lcp(r[1],t[j-i])>=n-j+1
i<=lbc_ak

q=j-i
lcp(s[i+1],t[1])>=j-i-1
lcp(r[1],t[j-i])>=n-j+1
lcp(r[1],t[p])>=n-(q+i)+1
-lcp(r[1],t[p]+n-q+1<=iq

lcp(s[i+1],t[1])>=q-1
-lcp(r[1],t[p]+n-q+1<=iq

s aa|aacd|aab
t |aacd|baa|aa
r baadcaaaa
*/