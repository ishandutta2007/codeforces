#include <bits/stdc++.h>
using namespace std;
map<string,int> sc;
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		sc[s]++;
	}
	string ans;
	int MAX=0;
	for(map<string,int>::iterator it=sc.begin();it!=sc.end();it++){
		if(it->second>MAX)	ans=it->first,MAX=it->second;
	}
	cout<<ans;
	return 0;
}