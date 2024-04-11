#include<bits/stdc++.h>

using namespace std;

namespace Tzh{
	
	typedef long long ll;
	typedef double dd;
	ll n,ans,sum1,sum2,m,x,d;

	void work(){
		cin>>n>>m;
		for(int i=1;i<=m;i++){
			cin>>x>>d; if(d<0) sum1+=d;
			else sum2+=d;
			ans+=x*n;
		}
		for(int i=1;i<=n;i++){
			ans+=abs(i-1)*sum2+abs(i-(n+1)/2)*sum1;
		}
		printf("%.9lf",(dd)ans/n);
		return ;
	}	
}

int main(){
	ios::sync_with_stdio(false);
	Tzh::work();
	return 0;
}