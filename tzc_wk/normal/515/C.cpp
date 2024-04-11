#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		char c;cin>>c;
		if(c=='2')		v.push_back(2);
		else if(c=='3')	v.push_back(3);
		else if(c=='4')	v.push_back(2),v.push_back(2),v.push_back(3);
		else if(c=='5')	v.push_back(5);
		else if(c=='6')	v.push_back(3),v.push_back(5);
		else if(c=='7')	v.push_back(7);
		else if(c=='8')	v.push_back(7),v.push_back(2),v.push_back(2),v.push_back(2);
		else if(c=='9')	v.push_back(7),v.push_back(3),v.push_back(3),v.push_back(2);
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	for(int i=0;i<v.size();i++)	cout<<v[i];
}