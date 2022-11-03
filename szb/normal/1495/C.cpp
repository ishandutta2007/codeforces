#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define ld long double
#define For(i,x,y)	for(ll i=(x);i<=(y);++i)
#define FOr(i,x,y)	for(ll i=(x);i>=(y);--i)
#define rep(i,x,y)	for(ll i=(x);i<(y);++i)
#define clr(a,v)	memset(a,v,sizeof(a))
#define cpy(a,b)	memcpy(a,b,sizeof(a))
#define fi	first
#define se	second
#define	pb	push_back
#define mk	make_pair
#define pa	pair<ll,ll>
#define y1	y11111111111111
#define debug	puts("@@@@@@@@@@@@@@@@@@@@@@@")
ll read(){
	ll x=0,f=1;	char ch=getchar();	
	for(;ch<'0'||ch>'9';ch=getchar())	if (ch=='-')	f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())	x=x*10+ch-'0';
	return x*f;
}
void write(ll x){
	if (x<0)	putchar('-'),write(-x);
	else{
		if (x>=10)	write(x/10);
		putchar(x%10+'0');
	}
}
const ll mod=1e9+7,N=550;
char s[N];
ll a[N][N],n,m;
int main(){
	ll T=read();
	for(;T--;){
		n=read();	m=read();
		For(i,1,n){
			scanf("%s",s+1);
			For(j,1,m)a[i][j]=s[j]=='X';
		}
		For(i,1,n)if (i%3==1){
			For(j,1,m)a[i][j]=1;
		}else if(i%3==2){
			bool fl=0;
			For(j,1,m)if(a[i][j]==1){
				fl=1;
				if(i<n)a[i+1][j]=1;
				break;
			}
			if (!fl&&(i<n)){
				For(j,1,m)if (a[i+1][j]==1){
					a[i][j]=1;
					fl=1;
					break;
				}
				if (!fl){
					a[i][1]=a[i+1][1]=1;
				}
			}
		}else if((i%3==0)&&(i==n)){
			For(j,1,m)if (a[i][j]){
				ll pos=j;
				while((pos>1)&&(!a[i][pos-1]&&!a[i-1][pos])){
					a[i][pos-1]=1;
					--pos;
				}
				if (pos==1&&!a[i-1][1]){
					a[i-1][1]=1;
				}
			}
		}
		For(i,1,n){
			For(j,1,m)putchar(a[i][j]?'X':'.');
			puts(""); 
		}
	}
}
/*
6 6
......
......
...X..
......
.X...X
...X..
*/