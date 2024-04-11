#include<stdio.h>
#include<string.h>
#include<string>
#include<math.h>
#include<iostream>
#include<bitset>
#include<map>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
#include<limits.h>
#include<stdlib.h>
#include<time.h>
#define ll long long
#define maxn 200010
#define For(i,x,y) for(ll i=x;i<=y;i++)
#define FOr(i,x,y) for(ll i=x;i>=y;i--)
using namespace std;
inline int read(){int x=0,f=0;char ch=getchar();for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;return f?-x:x;}
inline void write(ll x){if(x<10) putchar(x+48);else write(x/10),putchar(x%10+48);}
inline void writeln(ll x){if(x<0) x=-x,putchar('-');write(x);putchar('\n');}
set<ll>s;
ll n,v[maxn],c;
int main(){
	c=read();	n=read();
	For(i,1,n)	v[read()]++;
	For(i,0,c)	if (v[i])	s.insert(i);
	if (v[c])	return puts("Greed is good"),0;
	For(i,1,c-1){
		if (!v[i])	s.insert(i);
		v[i]++;
		ll x=c,f=c;
		while(x){
			set<ll>::iterator p=s.upper_bound(f);
			if (p==s.begin())	break;
			p--;
			ll y=*p;
			x-=min(x/y,v[y])*y;
			f=min(y-1,x);
		}
		if (x)	return writeln(i),0;
		if (!(--v[i]))	s.erase(i);
	}puts("Greed is good");
}
/*
12
3
5
3
4
*/