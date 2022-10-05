/*




D P 




 l l
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
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
int n,x,pre[100005];
char s[100005];
inline void solve(){
	cin>>n>>x>>s+1;
	fz(i,1,n){
		if(s[i]=='1')	pre[i]=pre[i-1]-1;
		else			pre[i]=pre[i-1]+1;
	}
	int mx=-0x3f3f3f3f,mn=0x3f3f3f3f;
	fz(i,1,n)	mx=max(mx,pre[i]),mn=min(mn,pre[i]);
	if(pre[n]==0&&x<=mx&&x>=mn){
		puts("-1");
		return;
	}
	else if(pre[n]==0){
		puts("0");
		return;
	}
	int ans=0;
	fz(i,0,n-1){
		int cyc=x-pre[i];
		if(cyc%pre[n]==0&&(cyc/pre[n])>=0)	ans++;
	}
	cout<<ans<<endl;
}
int main(){
	int T=read();
	while(T--)	solve();
	return 0;
}