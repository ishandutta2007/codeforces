//  Created by Zhikun on 2018/10/3.
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
ll n,c;
int cnt[100010] = {0};
int main() {
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>c;
		cnt[c]++;
	}
	int sum = 0,ans = 0;
	for(int i=100000;i>=0;i--){
		sum+=cnt[i];
		ans|=sum%2;
	}
	if(ans){
	cout<<"Conan"<<endl;
	}else{
	cout<<"Agasa"<<endl;
	}
	return 0;
}