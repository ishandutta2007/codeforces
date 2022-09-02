#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int T,n,k,m,b[N];
bool Solve(){
	if((n-m)%(k-1))return false;
	int p=(k-1)/2;
	b[m+1]=n+1;
	for(int i=1,now=0;i<=m+1;++i){
		now+=b[i]-b[i-1]-1;
		if(now>=p&&(n-m)-now>=p)return true;
	}
	return false;
}
int main(){
	T=read();
	while(T--){
		n=read(),k=read(),m=read();
		for(int i=1;i<=m;++i){
			b[i]=read();
		}
		printf(Solve()?"YES\n":"NO\n");
	}
	return 0;
}