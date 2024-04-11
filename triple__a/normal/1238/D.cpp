#include<bits/stdc++.h>
using namespace std;

int n;
long long ans;
string s;
vector<int> vec;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>s;
	ans=(long long)n*(n-1)/2;
	int i=0;
	while (i<n){
		int l=i;
		while (i+1<n&&s[i+1]==s[i]) i++;
		++i;
		vec.push_back(i-l);
	}
	int m=vec.size();
	for (int i=0;i<m-1;++i){
		ans-=vec[i]+vec[i+1]-1;
	}
	cout<<ans<<endl;
}