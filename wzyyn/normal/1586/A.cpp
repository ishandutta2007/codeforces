#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int n,a[105];
int He(int x){
	for (int i=2;i*i<=x;i++)
		if (x%i==0) return 1;
	return 0;
}
void solve(){
	int S=0;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),S+=a[i];
	if (He(S)){
		printf("%d\n",n);
		for (int i=1;i<=n;i++)
			printf("%d%c",i,i==n?'\n':' ');
	}
	else{
		int re=0,p=0;
		for (int i=1;i<=n;i++)
			if (S-a[i]>re&&He(S-a[i]))
				re=S-a[i],p=i;
		printf("%d\n",n-1);
		for (int i=1;i<=n;i++)
			if (i!=p) printf("%d%c",i,(i-(i>p))==(n-1)?'\n':' ');
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}