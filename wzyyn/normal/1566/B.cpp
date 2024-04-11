#include<bits/stdc++.h>

using namespace std;

char s[200005];
void solve(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	int v=0;
	for (int i=1;i<=n;i++)
		if (s[i]=='0'&&s[i-1]!='0') ++v;
	cout<<min(v,2)<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}