#include<bits/stdc++.h>

using namespace std;

const int N=300005;
int n,a[N];
map<long long,int> mp;
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	mp.clear();
	long long off=0;
	long long coeff=1;
	long long ans=0;
	for (int i=1;i<=n;i++){
		mp[(0-off)*coeff]+=1;
		int c=a[i];
		off=c-off;
		coeff=-coeff;
		for (;!mp.empty()&&coeff*mp.begin()->first+off<0;)
			mp.erase(mp.begin());
		for (;!mp.empty()&&coeff*mp.rbegin()->first+off<0;)
			mp.erase(prev(mp.end()));
		ans+=mp[(0-off)*coeff];
	}
	cout<<ans<<endl;
}
/*
0 -2 0
0 -1 1 0 -2 -1 -3 -2 -4

*/
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}