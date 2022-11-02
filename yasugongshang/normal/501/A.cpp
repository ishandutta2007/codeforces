#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;
inline int read(){
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(int a){
	write(a); puts("");
}
int s[10];
inline double chu(int s1,int s2){
	return max((double)3*s1/10,s1-(double)s1/250*s2);
}
int main(){
	for(int i=1;i<=4;i++)cin>>s[i];
	double t1=chu(s[1],s[3]),t2=chu(s[2],s[4]);
	if(t1>t2)puts("Misha"); else if(t1==t2)puts("Tie"); else puts("Vasya");
}