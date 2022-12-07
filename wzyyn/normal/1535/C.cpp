#include<bits/stdc++.h>
using namespace std;

char s[200005];
int a[2][2];
void solve(){
	scanf("%s",s+1);
	int l=1;
	long long ans=0;
	memset(a,0,sizeof(a));
	for (int r=1;s[r];++r){
		if (s[r]!='?') ++a[s[r]-'0'][r&1];
		for (;(a[0][0]+a[1][1])&&(a[0][1]+a[1][0]);++l)
			if (s[l]!='?') --a[s[l]-'0'][l&1];
		ans+=r-l+1;
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}