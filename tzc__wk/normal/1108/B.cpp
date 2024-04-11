#include <bits/stdc++.h>
using namespace std;
int n,a[130];
set<int> s;
int x,y;
vector<int> factor(int a){
	vector<int> x;
	for(int i=1;i*i<=a;i++){
		if(a%i==0){
			x.push_back(i);
			if(i*i!=a)	x.push_back(a/i);
		}
	}
	return x;
}
int main(){
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>a[i];
		x=max(x,a[i]);
	}
	vector<int> f=factor(x);
	map<int,bool> used;
	for(int i=0;i<f.size();i++){
		for(int j=0;j<n;j++){
			if(a[j]==f[i]&&!used[a[j]])	used[a[j]]=true,
			a[j]=-1;
		}
	}
	for(int i=0;i<n;i++){
		y=max(y,a[i]);
	}
	cout<<x<<" "<<y<<endl;
}