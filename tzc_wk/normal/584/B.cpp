#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=1e9+7;
int n,ans1=1,ans2=1;
signed main(){
	cin>>n;
	for(int i=1;i<=3*n;i++)	ans1=ans1*3%MOD;
	for(int i=1;i<=n;i++)	ans2=ans2*7%MOD;
	cout<<(ans1-ans2+MOD*2)%MOD<<endl;
}