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
const ll N=1000100;
ll n,m,Q;
ll a[N],b[N];
char s[N];
int main(){
    for(ll T=read();T--;){
        n=read();
        scanf("%s",s+1);
        For(i,1,n)a[i]=read();
        ll need_move_max=0,not_need=0;
        For(i,1,n){
            ll A=0,B=0;
            if (s[i]=='1'){
                A=max(need_move_max+a[i],not_need+a[i]);
                B=max(need_move_max,not_need+a[i]);
            }else{
                A=not_need+a[i];
                B=not_need;
            }
            need_move_max=A;
            not_need=B;
        }
        cout<<not_need<<endl;
    }
}