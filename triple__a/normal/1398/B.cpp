#include<bits/stdc++.h>
using namespace std;

const int maxn=200007;
int t;
string s;
vector<int> ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>t;
	while (t--){
		cin>>s;
		int len=0;
		ans.clear();
		for (auto c:s){
			if (c=='0'){
				ans.push_back(-len);
				len=0;
			}
			else{
				len++;
			}
		}
		ans.push_back(-len);
		sort(ans.begin(),ans.end());
		bool fg=1;
		int res=0;
		for (auto c:ans){
			if (fg) res+=c;
			fg=1-fg;
		}
		cout<<-res<<"\n";
	}
}