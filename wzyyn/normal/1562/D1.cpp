#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

const int N=300005;
int n,Q,a[N];
char s[N];
void solve(){
	scanf("%d%d%s",&n,&Q,s+1);
	for (int i=1;i<=n;i++)
		if ((i%2==0)^(s[i]=='-'))
			a[i]=a[i-1]+1;
		else a[i]=a[i-1]-1;
	while (Q--){
		int l,r;
		scanf("%d%d",&l,&r);
		if (a[l-1]==a[r]) puts("0");
		else puts((r-l+1)&1?"1":"2");
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}