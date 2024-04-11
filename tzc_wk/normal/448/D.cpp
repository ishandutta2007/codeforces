#include <bits/stdc++.h>
using namespace std;
#define lint long long
lint n,m,k;
signed main(){
	cin>>n>>m>>k;
	lint l=1,r=n*m;
	while(l!=r){
		lint cnt=0;
		lint mid=(l+r)/2;
		for(int i=1;i<=n;i++){
			lint c=mid/i;
			c=min(c,m);
			cnt+=c;
		}
		if(cnt<k)	l=mid+1;
		else r=mid;
	}
	cout<<l<<endl;
}