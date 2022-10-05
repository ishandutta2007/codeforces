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
int n=read(),q=read();
multiset<int> st;
int cnt=0;
bool vis[3][100005];
int main(){
	while(q--){
		int a=read(),b=read();
		a--;
		vis[a][b]=vis[a][b]^1;
		if(vis[a][b]){
			if(vis[a^1][b-1])	cnt++;
			if(vis[a^1][b])		cnt++;
			if(vis[a^1][b+1])	cnt++;
		}
		else{
			if(vis[a^1][b-1]==1)	cnt--;
			if(vis[a^1][b]==1)	cnt--;
			if(vis[a^1][b+1]==1)	cnt--;
		}
//		cout<<cnt<<endl;
		if(cnt)	puts("No");
		else	puts("Yes");
	}
	return 0;
}