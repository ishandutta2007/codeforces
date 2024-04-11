#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define For(i,x,y) for(ll i = (ll)(x);i <= (ll)(y);++i)
#define rep(i,x,y) for(ll i = (ll)(x);i < (ll)(y);++i)
#define FOr(i,x,y) for(ll i = (ll)(x);i >= (ll)(y);--i)
#define fi first
#define se second
#define cpy(a,b) memcpy(a,b,sizeof (b))
#define pa pair<ll,ll>
#define y1 yyyyyyyyyyyyyyyyy
#define pb push_back
#define mk make_pair
#define debug puts("@@@@@@@@@@@@@@@@@@@@@@@")
inline ll read(){
	ll x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0'; ch = getchar();}
	return x*f;
}
void write(ll x){
	if (x<0)putchar('-'),x=-x;
	if (x>=10)write(x/10);
	putchar(x%10+'0');
}
const ll N=1000010,mod=1e9+7;
char s1[N],s2[N],s[N];
ll n;
bool work(){
	ll a=0,b=0,c=0,d=0;
	For(i,1,n-1){
		if (s[i]=='1'){
			if ((a==c||d==b)||(a==c+1&&b==d+1)){
				s1[i]=s2[i]='(';
				++a;
				++b;
			}else{
				s1[i]=s2[i]=')';
				++c;
				++d;
			}
		}else{
			if (a>b){
				s1[i]=')';
				s2[i]='(';
				++c;
				++b;
			}else{
				s1[i]='(';
				s2[i]=')';
				++a;
				++d;
			}
			if (c>a)return 0;
			if (d>b)return 0;
		}
	}
	if (s[n]!='1')return 0;
	s1[n]=s2[n]=')';
	++c;++d;
	if (a!=n/2||b!=n/2||c!=n/2||d!=n/2)return 0; 
	return 1; 
}
int main(){
	for(ll T=read();T--;){
		n=read();
		scanf("%s",s+1);
		if (work()){
			puts("YES");
			For(i,1,n)putchar(s1[i]);puts("");
			For(i,1,n)putchar(s2[i]);puts("");
		}else{
			puts("NO");
		}
	}
}