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

ll n,m,ans = 0;
char sm[1010][1010];
int main() {
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>sm[i];
		m = strlen(sm[i]);
		sort(sm[i],sm[i]+m);
		ll st = 0;
		for(int j=1;j<m;j++){
			if(sm[i][j]!=sm[i][st]){
				st+=1;
				sm[i][st] = sm[i][j];
				
			}
		}
		for(int j=st+1;j<100;j++){
			sm[i][j] = 0;
		}
		//cout<<sm[i]<<endl;
		ll oo = 1;
		for(int j=0;j<i;j++){
			ll o = 1;
			for(int k=0;k<50;k++){
				if(sm[j][k]!=sm[i][k])o = 0;
			}
			if(o)oo = 0;
		}
		if(oo){
			ans+=1;
		}
	}
	cout<<ans<<endl;
	return 0;
}