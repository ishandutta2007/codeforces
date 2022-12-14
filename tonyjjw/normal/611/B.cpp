
//*

#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long ll;

vector<ll> ones, one;

int main(){
	ll st,ed;
	scanf("%lld%lld",&st,&ed);
	for(int i=0;i<63;i++){
		ones.push_back(((ll)1<<i) - 1);
		one.push_back((ll)1<<i);
	}
	int ans=0;
	for(auto &n1:ones)for(auto &n2:one){
		if((n1+1) <= 2*n2)continue;
		if(st<=n1-n2 && n1-n2<=ed)ans++;
	}
	printf("%d\n",ans);
	return 0;
}

//*/