#include <bits/stdc++.h>
using namespace std;
#define ll			long long
#define ld			long double
#define go(i,l,r)	for(int i=l;i<=r;i++)
#define rep(i,n)	for(int i=1;i<=n;i++)
#define rep0(i,n)	for(int i=0;i<n;i++)
#define PB			push_back
#define MP			make_pair
#define PII			pair<int,int>
#define VI			vector<int>
#define ALL(x)		(x).begin(),(x).end()
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
#define int long long
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
signed main(){
	int n=read(),p=read(),w=read(),d=read();
	int gcd=__gcd(w,d),lcm=w*d/gcd;
	int x=0,y=0,z=0;
	bool found=0;
	for(int i=0;i<=10000000;i++){
		int lft=p-i*d;
		if(lft%w==0&&lft>=0){
			x+=lft/w;y+=i;
			found=1;
			break;
		}
	}
	if(!found)	return puts("-1"),0;
	if(x+y>n)	return puts("-1"),0;
	cout<<x<<" "<<y<<" "<<n-x-y<<endl;
	return 0;
}
/*
10 11 4 2
12 10 3 2
5 13 3 2
1000000000 9900 101 100
100 10200 102 100
100 0 102 100
51 101 2 1
1 51 100 51
10000 1 3 2
4 7 3 2
1000000000000 100000000000000000 100000 100000
*/