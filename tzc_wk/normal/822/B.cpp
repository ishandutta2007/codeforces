#include <bits/stdc++.h>
using namespace std;
int n,m,ans=INT_MAX;
string s,t;
vector<int> ansv,v;
int main(){
	cin>>n>>m;
	cin>>s>>t;
	s=" "+s;
	t=" "+t;
	for(int i=1;i<=m+1-n;i++){
		int sum=0;
		v.clear();
		for(int j=i;j<i+n;j++){
			if(t[j]!=s[j-i+1])	sum++,v.push_back(j-i+1);
		}
		if(sum<ans){
			ans=sum;
			ansv=v;
		}
	}
	cout<<ans<<endl;
	for(int i=0;i<ans;i++)	cout<<ansv[i]<<" ";
}