#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define y1 y1111111111111111111
#define pa pair<ll,ll>
#define mk make_pair
#define For(i,x,y)	for(ll i=(x);i<=(y);++i)
ll read(){
	ll x=0,f=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if (ch=='-')f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-'0';
	return x*f;
}
void write(ll x){
	if (x<0)putchar('-'),x=-x;
	if (x>=10)write(x/10);
	putchar(x%10+'0');
}
char s[100];
ll ans,a[100];
ll sum(ll x){
	return (x+1)/2;
}
ll Q(ll l,ll r){
	return sum(r)-sum(l-1);
}
void dfs(ll x){
	if (x==11){
		ll A=0,B=0;
		For(i,1,10){
			if (i&1)A+=a[i]; 
			else	B+=a[i];
			if (A+Q(i+1,10)<B){
				ans=min(ans,i);
				return;
			}
			if (B+Q(i+2,11)<A){
				ans=min(ans,i);
				return;
			}
		}
		return;
	}
	if (s[x]=='1'||s[x]=='?'){
		a[x]=1;
		dfs(x+1);
	}
	if (s[x]=='0'||s[x]=='?'){
		a[x]=0;
		dfs(x+1);
	}
}
int main(){
	ll T=read();
	for(;T--;){
		ans=10;
		scanf("%s",s+1);
		dfs(1);
		cout<<ans<<endl; 
	}
}