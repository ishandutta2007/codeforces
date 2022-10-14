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
ll sa[100010] = {0},cna[100010] = {0},sb[100010] = {0};
int main() {
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(sa[a[i]] == 0){
			sa[a[i]] = i;
			cna[i] = cna[i-1]+1;
		}else{
			cna[i] = cna[i-1];
		}
		//cout<<cna[i]<<' ';
	}
	//cout<<endl;
	for(int i=n;i>1;i--){
		if(sb[a[i]] == 0){
			sb[a[i]] = i;
			ans+=cna[i-1];
		}
	}
	cout<<ans<<endl;
	return 0;
}