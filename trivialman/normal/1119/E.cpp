#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 1e9+7;
const int N = 300010;

LL n,a[N],ans=0;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	int j=0;
	rep(i,1,n){
		ans+=a[i]/3;
		a[i]%=3;
		if(a[i]>=1){
			j = max(i+1,j);
			for(;j<=n;++j)if(a[j]>=2){
				--a[i];a[j]-=2;++ans;
				if(a[i]==0)break;
				if(a[i]==1&&a[j]>=2){
					--a[i];a[j]-=2;++ans;
					break;
				}
			}
		}
		//cout<<i<<" "<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}