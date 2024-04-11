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
char s[200005];
int sum[200005][30];
int main(){
	cin>>s+1;int n=strlen(s+1);
	fz(i,1,n){
		fz(j,0,25){
			if((s[i]-'a')==j)	sum[i][j]=sum[i-1][j]+1;
			else				sum[i][j]=sum[i-1][j];
		}
	}
	int T=read();
	while(T--){
		int l=read(),r=read();int cnt=0;
		fz(i,0,25){
			if((sum[r][i]-sum[l-1][i])>0){
				cnt++;
			}
		}
		if(cnt>=3)	puts("Yes");
		else if(cnt==1){
			if(l==r)	puts("Yes");
			else		puts("No");
		}
		else{
			if(s[l]==s[r])	puts("No");
			else			puts("Yes");
		}
	}
	return 0;
}