#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=200007;
int t;
string s;
int sum[maxn];
map<int,int> res;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>t;
	while (t--){
		int n;
		cin>>n;
		cin>>s;
		for (int i=0;i<n;++i){
			sum[i]=s[i]-'0';
		}
		res.clear();
		for (int i=1;i<n;++i) sum[i]+=sum[i-1];
		res[0]++;
		for (int i=0;i<n;++i) res[sum[i]-i-1]++;
		int ans=0;
		for (auto c:res){
			ans+=c.second*(c.second-1);
		}
		cout<<ans/2<<"\n";
	}
}