// Author : WangZhikun
// 2018.7.6

#include <map>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll n,a[100010],d,ans = 0;
map<ll,ll> sss;
int main() {
	cin>>n>>d;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=1;j>-3;j-=2){
			ll cup = a[i]+d*j,mint = d;
			for(int k=0;k<n;k++){
				mint = min(mint,abs(a[k]-cup));
			}
			if(mint == d && sss[cup] == 0){
				sss[cup] = 1;
				ans++;
				//cout<<cup<<endl;
			}
		}
	}
	cout<<ans<<endl;
	/*
	if(ans){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	*/
	return 0;
}