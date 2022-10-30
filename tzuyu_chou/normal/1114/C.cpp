#include<iostream>
using namespace std;
typedef long long ll;
ll n,d;
ll ans=1e18;
void test(ll num,int cnt){
	ll res=0;
	ll cur=num;
	while(n>=cur){
		res+=n/cur;
		if(cur>n/num+1) break;
		cur*=num;
	}
	ans=min(ans,res/cnt);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> d;
	for(ll i=2; i*i<=d ;i++){
		if(d%i==0){
			int cnt=0;
			while(d%i==0){
				d/=i;++cnt;
			}
			test(i,cnt);
		}
	}
	if(d!=1) test(d,1);
	cout << ans << endl;
}