#include <bits/stdc++.h>
#define rep(i, n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	vector<int> x(n), y(n);
	rep(i,n)cin>>x[i]>>y[i];
	vector<int> ord(n);
	rep(i,n)ord[i]=i;
	sort(ord.begin(),ord.end(),[&](int l, int r){
		return x[l]==x[r] ? y[l]>y[r] : x[l]<x[r];
	});
	int ma = 0, idx = 0;
	for(auto i: ord){
		if(y[i]<=ma){
			cout<<i+1<<" "<<idx+1<<endl;
			return 0;
		}
		if(y[i]>ma){
			ma=y[i];
			idx=i;
		}
	}
	cout<<-1<<" "<<-1<<endl;
}