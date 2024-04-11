#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector<int> factor(){
	vector<int> f;
	for(int i=1;i*i<=n;i++){
		if(n%i==0){
			f.push_back(i);
			if(i*i!=n)	f.push_back(n/i);
		}
	}
	return f;
}
vector<int> ans;
signed main(){
	cin>>n;
	vector<int> f=factor();
	for(int i=0;i<f.size();i++){
		int last=n-f[i]+1,num=n/f[i];
		ans.push_back((1ll+last)*num/2);
	}
	priority_queue<int> st;
	for(int i=0;i<ans.size();i++){
		st.push(ans[i]);
	}
	int k=ans.size();
	ans.clear();
	for(int i=0;i<k;i++){
		ans.push_back(st.top());
		st.pop();
	}
	reverse(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++){
		cout<<ans[i];
		if(i!=ans.size()-1)	cout<<" ";
		else	cout<<endl;
	}
}