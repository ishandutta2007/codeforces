#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
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
int n=read(),x=read(),y=read(),t=read();
inline int calc(int s){
	if(s<=0)	return 0;
    return		1ll*(s+1)*s/2;
}
inline bool check(int s){
	int a=x-1,b=y-1,c=n-x,d=n-y;
	int ans=min(s,a)+min(s,b)+min(s,c)+min(s,d)+1;s--;
	ans+=calc(s)*4-2*calc(s-a)-2*calc(s-b)-2*calc(s-c)-2*calc(s-d);
	ans+=calc(s-a-b)+calc(s-b-c)+calc(s-c-d)+calc(s-d-a);
	return ans>=t;
}
signed main(){
	int l=0,r=INT_MAX,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
//		cout<<mid<<endl; 
		if(check(mid))	ans=mid,r=mid-1;
		else			l=mid+1;
	}
	print(ans);
	return 0;
}