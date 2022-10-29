#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 998244353;
const int N = 100010;

LL n,a[N],tot=0;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n;
	rep(i,1,n)cin>>a[i];
	sort(a+1,a+n+1);
	
	bool flag = true;
	rep(i,1,n)if(a[i]!=0)flag=false;
	if(flag){
		cout<<"cslnb\n";
		return 0;
	}
	
	int cnt=0;
	rep(i,1,n-1)if(a[i]==a[i+1])++cnt;
	if(!cnt)flag=false;
	if(cnt==1){
		flag = false;
		a[0]=-1;
		rep(i,1,n-1)
			if(a[i]==a[i+1]&&(a[i]==0||a[i]==a[i-1]+1)) flag = true;
	}
	if(cnt>=2)flag=true;
	if(flag){
		cout<<"cslnb\n";
		return 0;
	}
	
	rep(i,1,n)tot=(tot+a[i]-(i-1))%2;
	cout<<(tot%2 ? "sjfnb" : "cslnb")<<endl;
	return 0;
}