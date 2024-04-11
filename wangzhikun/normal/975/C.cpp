//
//  main.cpp
//  Round 478
//
//  Created by  on 2018/5/2.
//  Copyright  2018 . All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n,q,def[200020],dd[200020],atk[200020];
int main() {
	cin>>n>>q;
	dd[0] = 0 ;
	for(int i=1;i<=n;i++){
		cin>>def[i];
		dd[i] = def[i]+dd[i-1];
	}
	ll left = def[1];
	ll ans = 1;
	for(int i=0;i<q;i++){
		cin>>atk[i];
		if(atk[i]<left){
			left-=atk[i];
			cout<<n-ans+1<<endl;
			continue;
		}
		ll l = ans-1,r = n,mid;
		while(r-l>1){
			mid = (l+r)/2;
			if(dd[mid]-dd[ans]+left>=atk[i]) r = mid;
			else l = mid;
		}
		left = dd[r]-dd[ans]+left-atk[i];
		//cout<<left<<endl;
		if(left == 0 && r!=n){
			left = def[r+1];
			r+=1;
			//cout<<"H"<<r<<endl;
		}
		ans = r;
		if(ans == n && left <= 0){
			left = def[1];
			ans = 1;
		}
		cout<<n-ans+1<<endl;
	}
	return 0;
}