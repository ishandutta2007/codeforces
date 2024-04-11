#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> ans;
int main(){
	cin>>n>>m;
	while(n>0&&m>0){
//		cout<<n<<endl;
		if((m&(-m))<=n){
			ans.push_back(m);
			n-=(m&(-m));
		}
		m--;
	}
	if(n==0){
		cout<<ans.size()<<endl;
		for(int i=0;i<ans.size();i++)	cout<<ans[i]<<" ";
	}
	else
		puts("-1");
}