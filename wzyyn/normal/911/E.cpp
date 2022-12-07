#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long LL;
#define sqr(x) ((x)*(x))
#define mp make_pair
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
	int x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
const int N=200005;
int dq=1,n,k,vis[N],que[N],top,a[N];
int main(){
	n=read(); k=read(); que[0]=n+1;
	for(int i=1;i<=k;i++){
		vis[que[++top]=a[i]=read()]=1;
		while(que[top]==dq){
			top--; dq++; 
		}
		if(top>1&&que[top]>que[top-1]){
			puts("-1"); return 0;
		}
	}
	for(int i=1;i<=k;i++){
		write(a[i]); putchar(' ');
	}
	que[top+1]=0;
	for(int i=top;i>=0;i--){
		for(int j=que[i]-1;j>que[i+1];j--)if(!vis[j]){
			write(j); putchar(' ');
		}
	}
}