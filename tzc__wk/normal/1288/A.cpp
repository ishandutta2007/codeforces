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
int main(){
	int T=read();
	while(T--){
		int d=read(),x=read(),tot=INT_MAX;
		for(int i=0;i<=1000000;i++){
			tot=min(tot,i+((x%(i+1)==0)?x/(i+1):x/(i+1)+1));
		}
//		cout<<tot<<endl;
		if(tot>d)	puts("NO");
		else		puts("YES");
	}
	return 0;
}