#include<bits/stdc++.h>
//#define int long long
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=250005;
typedef long long ll;
int n,P,fac[N],inv[N];
int C(int a,int b){
	if(a<0||b<0||a-b<0)return 0;
	return 1ll*fac[a]*inv[b]%P*inv[a-b]%P;
}
signed main(){
	rd(n),rd(P);
	fac[0]=fac[1]=inv[0]=inv[1]=1;
	for(int i=2;i<N;++i)fac[i]=1ll*fac[i-1]*i%P,inv[i]=1ll*(P-P/i)*inv[P%i]%P;
	int ans=0;
	for(int i=1;i<=n;++i){
		(ans+=1ll*(n-i+1)%P*(n-i+1)%P*fac[n-i]%P*fac[i]%P)%=P;
	}
	pt(ans,'\n');
	return 0;
}