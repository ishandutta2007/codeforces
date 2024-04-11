#include<bits/stdc++.h>

using namespace std;

int F(int p,int d){
	int r=p/(2*d);
	int ans=r*d+min(p%(2*d)+1,d);
	return ans;
}
void solve(){
	int l,r,ans=1<<30;
	scanf("%d%d",&l,&r);
	for (int d=1;d<=r;d<<=1)
		ans=min(ans,F(r,d)-F(l-1,d));
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}