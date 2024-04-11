// author: xay5421
// created: Fri Jun  4 23:44:51 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long LL;
const int N=200005;
int T,n,cnt[2];
char s[N];
bool ps(int x){
	if(s[x]=='?')return 1;
	int cur=(x&1)^(s[x]&1);
	if(cnt[cur^1])return 0;
	++cnt[cur];
	return 1;
}
void pop(int x){
	if(s[x]!='?'){
		--cnt[(x&1)^(s[x]&1)];
	}
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1),n=strlen(s+1);
		int j=1;
		LL ans=0;
		for(int i=1;i<=n;++i){
			while(j<=n&&ps(j))++j;
			ans+=j-i;
			pop(i);
		}
		printf("%lld\n",ans);
	}
	return 0;
}