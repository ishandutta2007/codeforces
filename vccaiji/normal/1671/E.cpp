#include<bits/stdc++.h>
using namespace std;
int n;
char s[1<<19];
const int p=998244353;
int tot=2;
map<pair<pair<int,int>,int>,int> mp;
int f[1<<19];
int ans[1<<19];
void cal(int i){
	if(i>=(1<<(n-1))){
		if(s[i]=='A')f[i]=1;
		else f[i]=2;
		ans[i]=1;
		return;
	}
	cal(2*i);
	cal(2*i+1);
	auto ss=make_pair(make_pair((int)s[i],min(f[2*i],f[2*i+1])),max(f[2*i],f[2*i+1]));
	if(mp.count(ss))f[i]=mp[ss];
	else {
		mp[ss]=++tot;
		f[i]=tot;
	}
	if(f[2*i]==f[2*i+1]){
		assert(ans[2*i]==ans[2*i+1]);
		ans[i]=1ll*ans[2*i]*ans[2*i+1]%p;
	}
	else ans[i]=2ll*ans[2*i]*ans[2*i+1]%p;
}
int main(){
	cin>>n;
	scanf("%s",s+1);
	cal(1);
	cout<<ans[1];
	return 0;
}