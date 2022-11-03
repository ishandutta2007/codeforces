#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define For(i,x,y) for(ll i = (ll)(x);i <= (ll)(y);++i)
#define FOr(i,x,y) for(ll i = (ll)(x);i >= (ll)(y);--i)
#define rep(i,x,y) for(ll i = (ll)(x);i < (ll)(y);++i)
#define fi first
#define se second
#define pa pair<ll,ll>
#define pb push_back
#define y1 y11111111111111
#define debug puts("@@@@@@@@@@@@@@@@@@@")
 
#define cpy(a,b) memcpy(a,b,sizeof(b))
inline ll read()
{
	ll x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0';ch = getchar();}
	return x*f;
}
 
void write(ll x)
{
	if(x < 0) putchar('-'), x= -x;
	if(x > 9)write(x/10);
	putchar(x%10+'0');
}
const ll N=200010,_bas=19375331;
char s[N];
ll n;
struct node{
	ll len,v;
	unsigned ll Hsh[18];
	node *nxt[18];
	node(){
		For(i,0,17)nxt[i]=NULL,Hsh[i]=0;
	}
}ans[N];
unsigned long long bas[100];
node Expand(node &p,ll x){
	node res;
	res.len=p.len+1;
	res.v=x;
	res.Hsh[0]=x;
	res.nxt[0]=&p;
	For(i,1,17)if (res.nxt[i-1]->nxt[i-1]!=NULL){
		res.nxt[i]=res.nxt[i-1]->nxt[i-1];
		res.Hsh[i]=res.Hsh[i-1]+bas[i-1]*res.nxt[i-1]->Hsh[i-1];
	}else	break;
	return res;
}
bool cmp(node a,node b){
	FOr(i,17,0)if (a.nxt[i]!=NULL&&b.nxt[i]!=NULL)
		if (a.Hsh[i]==b.Hsh[i])a=*(a.nxt[i]),b=*(b.nxt[i]);
	return a.v>b.v;
}
void print(node q){
	write(q.len);putchar(' ');
	node *p=&q;
	if (q.len<=10){
		for(;p!=NULL&&p->len;p=p->nxt[0])
			printf("%c",char(p->v));
	}else{
		For(i,1,5)	printf("%c",char(p->v)),p=p->nxt[0];
		printf("...");
		FOr(i,17,0){
			if (p->len-(1<<i)>=2)	p=p->nxt[i]; 
		}
		for(;p!=NULL&&p->len;p=p->nxt[0])
			printf("%c",char(p->v));		
	}
	puts("");
}
int main(){
	scanf("%s",s+1);	n=strlen(s+1);
	bas[0]=_bas;
	For(i,1,17)	bas[i]=bas[i-1]*bas[i-1];
	FOr(i,n,1){
		ans[i]=Expand(ans[i+1],s[i]);
		if (s[i]==s[i+1])
			if (cmp(ans[i],ans[i+2]))
				ans[i]=ans[i+2]; 
	}
	For(i,1,n)print(ans[i]);
}