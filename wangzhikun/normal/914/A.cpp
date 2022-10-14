//  Created by Zhikun on 2018/10/3.
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
ll n,c;
int isp[1000010] = {0};
int main() {
	ll ans= -1e8;
	cin>>n;
	for(int i=0;i<1001;i++)isp[i*i] = 1;
	for(int i=0;i<n;i++){
		cin>>c;
		if(c<0){
			ans = max(ans,c);
		}else{
			if(!isp[c])ans = max(ans,c);
		}
	}
	cout<<ans<<endl;
	return 0;
}