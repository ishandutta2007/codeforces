/*




D P 




 l l
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
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
long long n=read(),a[200005],sum[200005];
map<int,int> mp;
long double ans;
int main(){
	fz(i,1,n)	a[i]=read();
	fz(i,1,n){
		mp[a[i]]++;
		ans-=mp[a[i]-1];
		ans+=mp[a[i]+1];
		sum[i]=sum[i-1]+a[i];
		ans+=(i-1)*a[i]-sum[i-1];
	}
	cout<<fixed<<setprecision(0)<<ans<<endl;
	return 0;
}