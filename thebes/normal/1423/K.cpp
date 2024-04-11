#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e6+5;
vector<bool> sv(N,true);
vector<int> ct((N<<1)+69); // ct[i]: how many primes leq i

signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	for(int i=2;i<N;i++){
		if(sv[i]){
			for(int j=i+i;j<N;j+=i){
				sv[j]=false;
			}
		}
	}
	ct[1]=1;
	for(int i=2;i<N;i++){
		if(sv[i]){
			ct[i]++;
			ct[min(i*i,(int)ct.size()-1)]--;
		}
	}
	partial_sum(ct.begin(),ct.end(),ct.begin());
	int t;cin>>t;
	while(t--){
		int x;cin>>x;
		cout<<ct[x]<<"\n";
	}
}