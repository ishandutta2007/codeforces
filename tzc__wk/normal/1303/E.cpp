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
inline int qpow(int x,int e,int _MOD){
	int ans=1;
	while(e){
		if(e&1)	ans=ans*x%_MOD;
		x=x*x%_MOD;
		e>>=1;
	}
	return ans;
}
int dp[405][405];
char s[405],t[405];
inline void solve(){
	cin>>s+1>>t+1;
	int n=strlen(s+1),m=strlen(t+1);
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(s[i]==t[cnt+1]){
			cnt++;
		}
		if(cnt==m){
			puts("YES");
			return;
		}
	}
	fz(i,1,m-1){
//		cout<<"i="<<i<<endl;
		fz(j,1,m)	dp[0][j]=-405;
		fz(j,1,n)	fz(k,0,m)	dp[i][j]=0;
		fz(j,1,n){
			if(s[j]==t[dp[j-1][0]+1+i])	dp[j][0]=dp[j-1][0]+1;
			else						dp[j][0]=dp[j-1][0];
//			cout<<j<<" "<<0<<" "<<dp[j][0]<<endl;
		}
		fz(j,1,n){
			fz(k,1,i){
				dp[j][k]=dp[j-1][k];
				if(s[j]==t[k])	dp[j][k]=max(dp[j][k],dp[j-1][k-1]);
				if(s[j]==t[i+dp[j-1][k]+1]){
					dp[j][k]=max(dp[j][k],dp[j-1][k]+1);
				}
//				cout<<j<<" "<<k<<" "<<dp[j][k]<<endl;
			}
		}
//		cout<<endl<<endl;
		if(dp[n][i]==m-i){
			puts("YES");
			return;
		}
	}
	puts("NO");
}
signed main(){
	int T=read();
	while(T--)	solve();
	return 0;
}