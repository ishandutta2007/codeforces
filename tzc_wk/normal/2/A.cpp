#include <bits/stdc++.h>
using namespace std;
pair<string,int> b[100005];
map<string,int> a;
string s;
int m;
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int d;
		cin>>s>>d;
		a[s]+=d;
		b[i].first=s;
		b[i].second=a[s];
	}
	for(int i=0;i<n;i++)
		m=max(m,a[b[i].first]);
	for(int i=0;i<n;i++){
		if(b[i].second>=m&&a[b[i].first]==m){
			cout<<b[i].first;
			break;
		}
	}
	return 0;
}