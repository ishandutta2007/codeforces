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
int n,m;
char s[66][66];
int cntr[66],cntc[66];
inline void solve(){
	memset(cntr,0,sizeof(cntr));
	memset(cntc,0,sizeof(cntc));
	cin>>n>>m;
	fz(i,1,n)	cin>>s[i]+1;
	int tot=0;
	fz(i,1,n)	fz(j,1,m)	if(s[i][j]=='A')	cntr[i]++,cntc[j]++,tot++;
	if(tot==n*m){puts("0");return;}
	if(tot==0){puts("MORTAL");return;}
	if(cntr[1]==m||cntr[n]==m||cntc[1]==n||cntc[m]==n){puts("1");return;}
	if(s[1][1]=='A'||s[1][m]=='A'||s[n][1]=='A'||s[n][m]=='A'){puts("2");return;}
	int mxr=0,mxc=0;
	fz(i,1,n)	mxr=max(mxr,cntr[i]);
	fz(i,1,m)	mxc=max(mxc,cntc[i]);
	if(mxr==m||mxc==n){puts("2");return;}
	if(cntr[1]>0||cntr[n]>0||cntc[1]>0||cntc[m]>0){puts("3");return;}
	puts("4");
}
int main(){
	int T;cin>>T;while(T--)	solve();
	return 0;
}