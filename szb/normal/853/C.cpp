#include<bits/stdc++.h>
#define ll long long
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
#define For(i,x,y)	for(ll i=x;i<=y;++i)
using namespace std;
namespace SHENZHEBEI{
#ifdef LOCAL
	struct szb{	szb(){	freopen("shenzhebei.in","r",stdin);	}	}shenzhebei;
#endif
#define NEG 1
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
const ll N=200010;
struct data{	ll x,y,id,typ,inf;	}q[N*4];
ll c[N],a[N],n,Q,cnt[N][5],ans[N],tot;
void add(ll x){	for(;x<=n;x+=x&-x)	c[x]++;	}
ll ask(ll x){	ll ans=0;	for(;x;x-=x&-x)	ans+=c[x];	return ans;	}
ll QQ(ll x){	return x*(x-1)/2;	}
bool operator < (data a,data b){	return a.x<b.x;	}
int main(){
	n=readint();	Q=readint();
	For(i,1,n)	a[i]=readint();
	For(i,1,Q){
		ll x1=readint(),y1=readint(),x2=readint(),y2=readint();
		ans[i]=QQ(n)-QQ(x1-1)-QQ(y1-1)-QQ(n-x2)-QQ(n-y2);
		q[++tot]=(data){x1-1,y1-1,i,1,1};
		q[++tot]=(data){x2,y1-1,i,2,-1};
		q[++tot]=(data){x1-1,y2,i,3,-1};
		q[++tot]=(data){x2,y2,i,4,1};
		cnt[i][2]=y1-1;
		cnt[i][3]=x1-1;
		cnt[i][4]=n-x2-y2;
	}sort(q+1,q+tot+1);
	ll j=0;
	for(;!q[j+1].x&&j<tot;)	j++;
	For(i,1,n){
		add(a[i]);
		while(q[j+1].x==i&&j<tot){
			++j;
			ans[q[j].id]+=QQ(cnt[q[j].id][q[j].typ]+ask(q[j].y)*q[j].inf);
		}
	}
	For(i,1,Q)	writeln(ans[i]);
}
/*
n*n 
 
Codeforces853C
*/