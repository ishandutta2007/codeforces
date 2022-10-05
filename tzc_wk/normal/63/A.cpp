#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<pair<int,int>,string> > v;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		string a,b;
		cin>>a>>b;
		if(b=="rat")	v.push_back({{1,i},a});
		else if(b=="woman"||b=="child")	v.push_back({{2,i},a});
		else if(b=="man")	v.push_back({{3,i},a});
		else	v.push_back({{4,i},a});
	}
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++){
		cout<<v[i].second<<endl;
	}
}//