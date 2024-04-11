#include<bits/stdc++.h>
#define ll long long
using namespace std;

char s[105];
void solve(){
	int n,a,b;
	scanf("%d%d%d%s",&n,&a,&b,s+1);
	if (b>=0) cout<<n*(a+b)<<endl;
	else{
		int t=1;
		for (int i=2;i<=n;i++)
			if (s[i]!=s[i-1]) ++t;
		cout<<n*a+(t/2+1)*b<<endl; 
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}