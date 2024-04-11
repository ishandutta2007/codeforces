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
int n=read(),mx[100005],mn[100005],a[100005];
bool is[100005];
int cnt[1000005],frt[100005];
signed main(){
	memset(mn,63,sizeof(mn));
	fz(i,1,n){
		int x=read();
		fz(j,1,x){
			a[j]=read();
		}
		is[i]=1;
		fz(j,1,x-1){
			if(a[j]<a[j+1])	is[i]=0;
		}
		if(is[i]){
			frt[i]=a[1];
			cnt[a[x]]++;
		}
	}
	fz(i,1,1000000)	cnt[i]+=cnt[i-1];
	int ans=0;
	fz(i,1,n)	if(is[i])	ans+=cnt[1000000]-cnt[frt[i]-1];
	cout<<n*n-ans<<endl;
	return 0;
}