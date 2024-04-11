//
//  main.cpp
//  Round 469
//
//  Created by  on 2018/4/22.
//  Copyright  2018 . All rights reserved.
//

#include <cstring>
#include <iostream>

using namespace std;
typedef long long ll;

ll n,q,p;
ll solve(ll n,ll q){
	//cout<<n<<' '<<q<<endl;
	if(q%2 == 1){
		return (q/2)+1;
	}else{
		if(n%2 == 0)return solve((n-n/2),q/2)+n/2;
		else return solve((n-n/2),q/2+1)+n/2;
	}
}

int main() {
	cin>>n>>q;
	for(int i=0;i<q;i++){
		cin>>p;
		cout<<solve(n,p)<<endl;
	}
	return 0;
}