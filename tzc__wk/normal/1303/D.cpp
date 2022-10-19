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
int n,m,a[100005],cntt[70];
inline void solve(){
	n=read(),m=read();
	memset(cntt,0,sizeof(cntt));
	fz(i,1,m){
		a[i]=read();
		int j=1,cnt=0;
		while(j!=a[i])	j<<=1,cnt++;
		cntt[cnt]++; 
	}
	int sum=0;
	fz(i,1,m)	sum+=a[i];
	if(sum<n){
		puts("-1");
		return;
	}
	int ans=0;
	for(int i=0;i<64;i++){
		int dig=n>>i&1;
		if(dig==1){
			if(cntt[i]>0){
				cntt[i]--;
				cntt[i+1]+=cntt[i]/2;
				cntt[i]%=2;
			}
			else{
//				cout<<"i="<<i<<endl;
				for(int j=i+1;j<64;j++){
					if(cntt[j]>0){
						cntt[j]--;
						for(int k=j-1;k>i;k--){
							cntt[k]++;
							ans++;
						}
						ans++;
//						cout<<"j="<<j<<endl;
						break;
					}
				}
			}
		}
		else{
			cntt[i+1]+=cntt[i]/2;
			cntt[i]%=2;
		}
	}
	cout<<ans<<endl;
}
signed main(){
	int T=read();while(T--)	solve();
	return 0;
}