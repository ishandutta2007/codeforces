#include <cstdio>
#include <algorithm>

#define MAXN 1005

int n,m,q,f[MAXN],sum[MAXN],nxt[MAXN];
char s[MAXN],t[MAXN];

inline void KMP(){
	int j=0;
	for (int i=1;i<m;i++){
		while (j && t[j]!=t[i]) j=nxt[j];
		if (t[i]==t[j]) nxt[i+1]=++j;
	}
	j=0;
	for (int i=0;i<n;i++){
		while (j && t[j]!=s[i]) j=nxt[j];
		if (s[i]==t[j]) j++;
		if (j==m) f[i]++;
	}
	for (int i=1;i<=n;i++) sum[i]=sum[i-1]+f[i-1];
}

int main(){
	scanf("%d%d%d",&n,&m,&q);
	scanf("%s%s",s,t);
	KMP();
	for (int l,r;q;q--){
		scanf("%d%d",&l,&r);
		printf("%d\n",sum[r]-sum[std::min(l+m-2,r)]);
	}
	return 0;
}