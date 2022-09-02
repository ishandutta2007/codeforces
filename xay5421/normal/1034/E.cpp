#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define pp(x) __builtin_popcount(x)
#define LL long long
using namespace std;
const int N=(1<<21)+5;
int n;char s[N];LL a[N],b[N];
void fwt(LL*a,int o){
	for(int i=1;i<n;i<<=1)for(int j=0;j<n;j+=i<<1)rep(k,0,i-1){
		if(o==1)a[i+j+k]+=a[j+k];
		else a[i+j+k]-=a[j+k];
	}
}
int main(){
	scanf("%d",&n);n=(1<<n);
	scanf("%s",s);rep(i,0,n-1)a[i]=(s[i]&3)*(1LL<<(pp(i)<<1));
	scanf("%s",s);rep(i,0,n-1)b[i]=(s[i]&3)*(1LL<<(pp(i)<<1));
	fwt(a,1),fwt(b,1);rep(i,0,n-1)a[i]=1LL*a[i]*b[i];fwt(a,-1);
	rep(i,0,n-1)putchar(((a[i]>>(pp(i)<<1))&3)+48);
	return 0;
}