#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;

int w,h;

int get(int u){
	int ans=1;
	for (int i=1;i<=u;++i){
		ans=(2*ans)%mod;
	}
	return ans;
}

#undef int
int main(){
	cin>>w>>h;
	cout<<get(w+h);
}