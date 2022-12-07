#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N=1000005;
int n,m,Q,f[N];
char s[N],t[N];
int main(){
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for (int i=2;i<=n;i++){
		scanf("%s",t+1);
		for (int j=2;j<=m;j++)
			if (t[j-1]=='X'&&s[j]=='X')
				f[j]=1;
		for (int j=1;j<=m;j++)
			swap(s[j],t[j]);
	}
	for (int i=1;i<=m;i++)
		f[i]+=f[i-1];
	scanf("%d",&Q);
	while (Q--){
		int l,r;
		scanf("%d%d",&l,&r);
		puts(f[l]==f[r]?"YES":"NO");
	}
}