#include<cstring>
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string>
#define rep(i,a,b) for (int i=a;i<=b;++i)
#define For(i,u) for (int i=H[u];i;i=nxt[i])
#define N 100005
using namespace std;
template<class T> inline void read(T&x){bool fu=0;char c;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x=-x;};
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z){read(x,y);read(z);}
string s1[N],s2[N],now;int n;
int main() {  
	read(n);rep(i,1,n)cin>>s1[i]>>s2[i];
	rep(i,1,n) {
		int p;read(p);
		if (i==1) now=(s1[p]>s2[p])?s2[p]:s1[p];
		else {
			if (s1[p]<=now&&s2[p]<=now) return puts("NO"),0;
			if (s1[p]<=now) now=s2[p];
			else if (s2[p]<=now) now=s1[p];
			else now=(s1[p]>s2[p])?s2[p]:s1[p];
		}
	}
	puts("YES");
	return 0;
}