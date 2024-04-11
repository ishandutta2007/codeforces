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
#define fi first 
#define se second
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
const ll N=1200010;
char u[N],v[N],w[N],s3[N];
ll n,m1,m2;
void did(char *s1,char *s2,char p){
	ll l=1,r=1,tot=0;
	for(;l<=n*2||r<=n*2;){
		if (l>n*2){
			s3[++tot]=s2[r++];
		}else if (r>n*2){
			s3[++tot]=s1[l++];
		}else{
			if (s1[l]==s2[r]){
					s3[++tot]=s1[l];
				++l;
				++r;
			}else{
				s3[++tot]='1'+'0'-p;
				if (s1[l]=='1'+'0'-p)++l;
				if (s2[r]=='1'+'0'-p)++r;
			}
		}
//		cout<<l<<' '<<r<<' '<<tot<<endl;
//		puts(s3+1);
	}
	for(;tot<n*3;)s3[++tot]='1';
	For(i,1,tot)putchar(s3[i]);puts("");
}
bool work(char *s1,char *s2){
	m1=m2=0;
	For(i,1,n*2)m1+=s1[i]-'0';
	For(i,1,n*2)m2+=s2[i]-'0';
//	cout<<m1<<' '<<m2<<endl; 
	if (m1>=n&&m2>=n){
		did(s1,s2,'1'); 
		return 1; 
	}else if (2*n-m1>=n&&2*n-m2>=n){
		did(s1,s2,'0');
		return 1;
	}
	return 0;
}
int main(){
	ll T=read();
	for(;T--;){
		n=read();
		scanf("%s%s%s",u+1,v+1,w+1);
		if (work(u,v)){
			continue;
		}else if (work(u,w)){
			continue;
		}else if (work(v,w)){
			continue; 
		}
	}
}
/*
1 
*/