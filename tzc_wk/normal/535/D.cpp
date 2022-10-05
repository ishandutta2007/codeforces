#include <bits/stdc++.h>
using namespace std;
#define int long long
char s[1000005];
int z[1000005],n,m,pos[1000005],p,delta[1000005],sum=0;
inline void Z_algorithm(){
	int l=0,r=0;
	for(int i=1;i<p;i++){
		if(i<=r)	z[i]=min(z[i-l],r-i);
		while(i+z[i]<n&&s[i+z[i]]==s[z[i]])	z[i]++;
		if(i+z[i]>r){
			l=i;
			r=i+z[i];
		}
	}
}
bool check(int x,int y){
	return (x+n<=y)?1:z[y-x]>=x+p-y;
}
int getpow(int x,int e,int MOD){
	int ans=1;
	while(e){
		if(e&1)	ans=ans*x%MOD;
		e>>=1;
		x=x*x%MOD;
	}
	return ans;
}
signed main(){
	scanf("%lld%lld%s",&n,&m,s);
	if(m==0){
		printf("%lld\n",getpow(26,n,1e9+7));
		return 0;
	}
	p=(int)strlen(s);
	Z_algorithm();
	for(int i=1;i<=m;i++){
		scanf("%d",&pos[i]);
		pos[i]--;
	}
	int tot=0;
	for(int i=1;i<m;i++){
		if(check(pos[i],pos[i+1])){
			delta[pos[i]]++;
			delta[pos[i]+p]--;
		}
		else
			return puts("0"),0;
	}
	delta[pos[m]]++;
	delta[pos[m]+p]--;
	for(int i=0;i<n;i++){
		sum+=delta[i];
		if(!sum)	tot++;
	}
	printf("%lld\n",getpow(26,tot,1e9+7));
	return 0;
}