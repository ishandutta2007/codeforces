#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

int n;
char s[20005];
void solve(){
	scanf("%d%s",&n,s+1);
	int l=n/2;
	for (int i=l+1;i<=n;i++)
		if (s[i]=='0')
			return printf("%d %d %d %d\n",1,i,1,i-1),void(0);
	for (int i=1;i<=l;i++)
		if (s[i]=='0')
			return printf("%d %d %d %d\n",i,n,i+1,n),void(0);
	printf("%d %d %d %d\n",1,l,n-l+1,n);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}