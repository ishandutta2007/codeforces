//  Created by WangZhikun on 2018/10/21.

#include <cstdio>
#include <vector>
#include <iostream>
#define PB push_back
#define MP make_pair
#define VI vector<int>
#define PII pair<int,int>
using namespace std;
typedef long long ll;

ll a,b,nua,taken[100010] = {0};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>b;
	ll c = a+b,s = 0,nu;
	for(ll i = 1;i<100000;i++){
		if(s+i>c){
			nu = i-1;
			break;
		}
		s+=i;
	}
	//cout<<nu<<endl;
	vector<ll> aa,ab;
	for(ll i = nu;i>=1;i--){
		if(a>i){
			a-=i;
			aa.PB(i);
			taken[i] = 1;
		}else{
			if(a == 0)break;
			aa.PB(a);
			taken[a] = 1;
			break;
		}
	}
	for(ll i = nu;i>=1;i--){
		if(!taken[i])ab.PB(i);
	}
	cout<<aa.size()<<endl;
	for(int i=0;i<aa.size();i++)cout<<aa[i]<<' ';
	cout<<endl;
	cout<<ab.size()<<endl;
	for(int i=0;i<ab.size();i++)cout<<ab[i]<<' ';
	cout<<endl;
	return 0;
}