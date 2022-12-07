#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	char s[105];
	scanf("%d%s",&n,s+1);
	int sum=0;
	for (int i=1;i<=n;i++)
		sum+=(s[i]-'0')+(s[i]=='0'||i==n?0:1);
	cout<<sum<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}