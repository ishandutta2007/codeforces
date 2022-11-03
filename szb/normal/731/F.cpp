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
#define maxn 400010
#define For(i,x,y) for(ll i=x;i<=y;i++)
#define FOr(i,x,y) for(ll i=x;i>=y;i--)
using namespace std;
inline int read(){int x=0,f=0;char ch=getchar();for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;return f?-x:x;}
inline void write(ll x){if(x<10) putchar(x+48);else write(x/10),putchar(x%10+48);}
inline void writeln(ll x){if(x<0) x=-x,putchar('-');write(x);putchar('\n');}
ll mark[maxn],n,ans;
int main(){
	n=read();
	For(i,1,n)	mark[read()]++;
	For(i,1,400000)	mark[i]+=mark[i-1];
	For(i,1,200000)	if (mark[i]-mark[i-1]){
		ll now=0;
		for(ll j=i;j<=200000;j+=i)	now+=(mark[j+i-1]-mark[j-1])*j;
		ans=max(ans,now);
	}writeln(ans);
}