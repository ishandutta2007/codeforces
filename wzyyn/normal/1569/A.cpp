#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
using namespace std;

int n;
char s[55];
void solve(){
	scanf("%d%s",&n,s+1);
	for (int i=1;i<n;i++)
		if (s[i]!=s[i+1])
			return printf("%d %d\n",i,i+1),void(0);
	puts("-1 -1");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}