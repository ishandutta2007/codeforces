// Author : WangZhikun
// Date   : 2018.07.26

#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int ans = 1;
void opyn(){if(ans)cout<<"Yes"<<endl;else cout<<"No"<<endl;}
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int n,k,cans,cur;
int main() {
	cin>>n>>k;
	cans = k;
	for(int i=0;i<n;i++){
		cin>>cur;
		cur = gcd(cur,k);
		cans = gcd(cans,cur);
	}
	cout<<k/cans<<endl;
	for(int i=0;i<k;i+=cans){
		cout<<i<<' ';
	}
	return 0;
}