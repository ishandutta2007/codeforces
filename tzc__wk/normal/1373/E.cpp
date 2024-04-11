/*
Contest: Educational Codeforces Round 90
Problem: Codeforces 1373E
Author: tzc_wk
Time: 2020.6.25
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define giveup(...) return printf(__VA_ARGS__),0;
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define fillsmall(a) memset(a,0xcf,sizeof(a))
#define mask(a)		(1ll<<(a))
#define maskx(a,x)	((a)<<(x))
#define _bit(a,x)	(((a)>>(x))&1)
#define _sz(a)		((int)(a).size())
#define filei(a)	freopen(a,"r",stdin);
#define fileo(a)	freopen(a,"w",stdout);
#define fileio(a) 	freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
#define y1			y1010101010101
#define y0			y0101010101010
#define int long long
typedef pair<int,int> pii;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	neg=-1;
		c=getchar();
	}
	while(isdigit(c))	x=x*10+c-'0',c=getchar();
	return x*neg;
}
inline int qpow(int x,int e,int _MOD){
	int ans=1;
	while(e){
		if(e&1)	ans=ans*x%_MOD;
		x=x*x%_MOD;
		e>>=1;
	}
	return ans;
}
inline int f(int x){
	int sum=0;
	while(x){
		sum+=x%10;
		x/=10;
	}
	return sum;
}
signed main(){
	int T=read();
	while(T--){
		int n=read(),k=read();
//		if(n<=50){
//			bool flg=0;
//			fz(i,0,1e6){
//				int sum=0;
//				for(int j=0;j<=k;j++)	sum+=f(i+j);
//				if(sum==n){
//					cout<<i<<endl;
//					flg=1;
//					break;
//				}
//			}
//			if(!flg)	puts("-1");
//			continue;
//		}
		if(k==0){
			int cnt=0;
			while(n>9)	n-=9,cnt++;
			cout<<n;fz(i,1,cnt)	cout<<9;
			puts("");
			continue;
		}
		k++;
		int final=LLONG_MAX;
		for(int i=0;i<=9;i++){
			int sum=0,cnt=0;
			for(int j=0;j<k;j++){
				sum+=(i+j)%10;
				if((i+j)<10)	cnt++;
			}
			for(int t=0;t<=13;t++){
				int sum2=sum+cnt*9*t+k-cnt;
				if(sum2>n)	continue;
				if((n-sum2)%k!=0)	continue;
				int allsum=(n-sum2)/k,cnt9=0;
				int num=0;
				if(allsum>8){
					allsum-=8;
					while(allsum>9)	allsum-=9,cnt9++;
					num=allsum;
					fz(s,1,cnt9)	num=num*10+9;
					num=num*10+8;
					fz(s,1,t)	num=num*10+9;
					num=num*10+i;
				}
				else{
					num=allsum;
					fz(s,1,t)		num=num*10+9;
					num=num*10+i;
				}
//				cout<<i<<" "<<t<<" "<<sum<<" "<<sum2<<" "<<allsum<<" "<<num<<endl;
				final=min(final,num);
			}
		}
		if(final!=LLONG_MAX)	cout<<final<<endl;
		else					puts("-1");
	}
	return 0;
}