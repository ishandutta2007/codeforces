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
const ll N=500010;
char s[N];
ll v[N],a[N],sum[N],n,m,ans,val;
int main(){
	m=read();
	scanf("%s",s+1);
	For(i,1,m)	if (s[i]!=s[i-1])	v[++n]=s[i]-'0',a[n]=1;
				else				++a[n];
	For(i,1,n)	if (v[i]==0)	ans+=a[i]*val,sum[0]+=a[i];
	else{
		For(j,1,a[i]){
			val+=sum[j-1];
			sum[j]+=sum[j-1];
			sum[j-1]=0;
			ans+=val;
		}
		For(j,1,a[i]){
			++sum[j];
			val+=j;
			ans+=j*(a[i]-j+1);
		}
	}
	cout<<ans<<endl;
}