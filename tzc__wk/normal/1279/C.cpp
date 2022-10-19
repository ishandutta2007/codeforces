#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
#define int long long
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	neg=-1;
		c=getchar();
	}
	while(isdigit(c))	x=x*10+c-'0',c=getchar();
	return x*neg;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		print(abs(x));
		return;
	}
	if(x<=9)	putchar(x+'0');
	else{
		print(x/10);
		putchar(x%10+'0');
	}
}
int n,m,a[100005],b[100005],pos[100005];
inline void solve(){
	n=read(),m=read();
	fz(i,1,n)	a[i]=read(),pos[a[i]]=i;
	int cur=0,ans=0;
	fz(i,1,m){
		int x=read();
		if(pos[x]>cur){
			ans+=2*(pos[x]-i)+1;
			cur=pos[x];
		}
		else	ans++;
//		cout<<ans<<endl;
	}
	print(ans);eoln;
}
signed main(){
	int T=read();
	while(T--)	solve();
	return 0;
}