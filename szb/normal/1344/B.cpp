#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
const ll N=1010,mod=998244353;
ll a[1010][1010],fx[N],fy[N],ans,f,n,m;
char s[N];
void dfs(ll x,ll y){
	if (a[x][y]==0)return;
	a[x][y]=0;
	dfs(x-1,y);
	dfs(x,y-1);
	dfs(x+1,y);
	dfs(x,y+1);
}
int main(){
	n=read();	m=read();
	For(i,1,n){
		scanf("%s",s+1);
		For(j,1,m)if (s[j]=='#')a[i][j]=1,++fx[i],++fy[j];
		else	a[i][j]==0;
	}
	For(i,1,n){
		ll sum=0;
		For(j,1,m)if (a[i][j]==1&&a[i][j-1]==0)++sum;
		if (sum>1)f=-1;
	}
	For(i,1,m){
		ll sum=0;
		For(j,1,n)if (a[j][i]==1&&a[j-1][i]==0)++sum;
		if (sum>1)f=-1;
	}
	ll A=0,B=0;
	For(i,1,n)A+=(fx[i]==0);
	For(i,1,m)B+=(fy[i]==0);
	if (A&&!B)f=-1;
	if (B&&!A)f=-1;
	if (f==-1){
		puts("-1");
		return 0;
	}
	For(i,1,n)For(j,1,m)if (a[i][j]==1)dfs(i,j),++ans;
	cout<<ans<<endl;
}