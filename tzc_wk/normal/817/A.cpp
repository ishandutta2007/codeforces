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
int a=read(),b=read(),c=read(),d=read(),x=read(),y=read();
int main(){
	int dif1=abs(a-c),dif2=abs(b-d);
	if(dif1%x!=0||dif2%y!=0)	return puts("NO"),0;
	int t1=dif1/x,t2=dif2/y;
	if((t1+t2)%2==1)	puts("NO");
	else				puts("YES");
	return 0;
}