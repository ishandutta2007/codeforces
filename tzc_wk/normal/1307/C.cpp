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
#define y1			y_chenxiaoyan_1
#define y0			y_chenxiaoyan_0
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
inline int qpow(int x,int e,int _MOD){
	int ans=1;
	while(e){
		if(e&1)	ans=ans*x%_MOD;
		x=x*x%_MOD;
		e>>=1;
	}
	return ans;
}
char s[100005];
int num[30];
signed main(){
	cin>>s+1;
	int n=strlen(s+1),ans=0;
	fz(i,1,n)	num[s[i]-'a']++;
	fz(i,0,25)	ans=max(ans,num[i]);
	fz(i,0,25){
		fz(j,0,25){
			int sum=0,cnt=0;
			fz(k,1,n){
				if(s[k]-'a'==j){
					cnt+=sum;
				}
				if(s[k]-'a'==i){
					sum++;
				}
			}
			ans=max(ans,cnt);
		}
	}
	print(ans);eoln;
	return 0;
}