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
int n=read(),m=read(),a[2005],b[2005],c[2005];
int main(){
	go(i,1,n)	a[i]=read();
	go(i,1,n)	b[i]=read();
	sort(a+1,a+n+1);
	sort(b+1,b+1+n);
	int ans=0x3f3f3f3f;
	go(i,1,n){
		int num=b[i]-a[1];
		if(num<0)	num+=m;
		go(j,1,n)	c[j]=(a[j]+num)%m;
		sort(c+1,c+n+1);
		bool ok=1;
		go(j,1,n)	if(c[j]!=b[j])	ok=0;
		if(ok)	ans=min(ans,num);
	}
	cout<<ans<<endl;
	return 0;
}