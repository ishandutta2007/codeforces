#include<bits/stdc++.h>

using namespace std;

const int N=2005;
char s[N];
int n,k,loc[N],v[N];
long long x,way[N];
void solve(){
	scanf("%d%d%lld",&n,&k,&x);
	scanf("%s",s+1);
	int t=0;
	for (int i=1;i<=n;i++) v[i]=0;
	for (int i=1;i<=n;i++)
		if (s[i]=='*'){
			if (s[i-1]!='*')
				loc[++t]=i;
			++v[t];
		}
	way[t]=1;
	for (int i=t;i>=1;i--){
		int num=k*v[i]+1;
		if (way[i]>x/num) way[i-1]=x+1;
		else way[i-1]=way[i]*num;
	}
	int p=1;
	for (int i=1;i<=t;i++){
		for (;p<loc[i];++p) if (s[p]=='a') putchar('a');
		for (;x>way[i];x-=way[i]) putchar('b');
	}
	for (;p<=n;++p)
		if (s[p]=='a') putchar('a');
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}