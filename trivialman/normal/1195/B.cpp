#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PII pair<int,int>
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 998244353;
const int N = 100010;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

LL n,k;

int main(){
	//freopen("test.in","r",stdin);
	cin>>n>>k;
	LL l=0,r=n,mid;
	while(l<=r){
		mid = (l+r)/2;
		LL candy = mid*(mid+1)/2+mid-n;
		if(candy==k)break;
		else if(candy>k)r=mid-1;
		else l=mid+1;
	}
	cout<<n-mid<<endl;
	return 0;
}