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
char s[1000000];
ll a[200][200],ans[1000000],n,m;
void doit(ll x,ll y){
	ll sum=a[x][y]+a[x+1][y]+a[x][y+1]+a[x+1][y+1];
	if (sum==4){
		ans[++ans[0]]=x;
		ans[++ans[0]]=y;
		ans[++ans[0]]=x+1;
		ans[++ans[0]]=y;
		ans[++ans[0]]=x;
		ans[++ans[0]]=y+1;
		a[x][y]=a[x+1][y]=a[x][y+1]=0;
		doit(x,y);
	}else if (sum==3){
		For(i,0,1)For(j,0,1)if (a[x+i][y+j]){
			ans[++ans[0]]=x+i;
			ans[++ans[0]]=y+j;
			a[x+i][y+j]^=1;
		}
	}else if (sum==2){
		ll num1=0,num2=0;
		For(i,0,1)For(j,0,1){
			if (a[x+i][y+j]&&(num1<1)){
				ans[++ans[0]]=x+i;
				ans[++ans[0]]=y+j;
				a[x+i][y+j]^=1;
				++num1;
			}else
			if (!a[x+i][y+j]&&(num2<2)){
				ans[++ans[0]]=x+i;
				ans[++ans[0]]=y+j;
				a[x+i][y+j]^=1;
				++num2;
			}
		}
		doit(x,y);
	}else if (sum==1){
		ll num1=0,num2=0;
		For(i,0,1)For(j,0,1){
			if (a[x+i][y+j]&&(num1<1)){
				ans[++ans[0]]=x+i;
				ans[++ans[0]]=y+j;
				a[x+i][y+j]^=1;
				++num1;
			}else
			if (!a[x+i][y+j]&&(num2<2)){
				ans[++ans[0]]=x+i;
				ans[++ans[0]]=y+j;
				a[x+i][y+j]^=1;
				++num2;
			}
		}
		doit(x,y);
	}
}
int main(){
	for(ll T=read();T--;){
		ans[0]=0;
		n=read();	m=read();
		For(i,1,n){
			scanf("%s",s+1);
			For(j,1,m)a[i][j]=s[j]-'0';
		}bool fl=0;
		if (n>m){
			For(i,1,n)For(j,1,i)swap(a[i][j],a[j][i]);
			swap(n,m);fl=1;
		}
		for(ll i=1;i<n;){
			for(ll j=1;j<m-1;++j){
				if (a[i][j]&&a[i+1][j]){
					ans[++ans[0]]=i;
					ans[++ans[0]]=j;
					ans[++ans[0]]=i+1;
					ans[++ans[0]]=j;
					ans[++ans[0]]=i;
					ans[++ans[0]]=j+1;
					a[i][j]=a[i+1][j]=0;a[i][j+1]^=1;
				}
				if (a[i][j]){
					ans[++ans[0]]=i;
					ans[++ans[0]]=j;
					ans[++ans[0]]=i;
					ans[++ans[0]]=j+1;
					ans[++ans[0]]=i+1;
					ans[++ans[0]]=j+1;
					a[i][j]=a[i+1][j]=0;a[i][j+1]^=1;a[i+1][j+1]^=1;
				}
				if (a[i+1][j]){
					ans[++ans[0]]=i+1;
					ans[++ans[0]]=j;
					ans[++ans[0]]=i;
					ans[++ans[0]]=j+1;
					ans[++ans[0]]=i+1;
					ans[++ans[0]]=j+1;
					a[i][j]=a[i+1][j]=0;a[i][j+1]^=1;a[i+1][j+1]^=1;
				}
			}
			doit(i,m-1);
			if (i+2==n)i=i+1;
			else i=i+2;
		}
		write(ans[0]/6);puts("");
		if (fl)For(i,1,ans[0]/2)swap(ans[i*2-1],ans[i*2]);
		For(i,1,ans[0]/6){For(j,-5,0)write(ans[i*6+j]),putchar(' ');puts("");}
	}
}