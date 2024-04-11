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

ll a[60],ans = 0,csum;
int main() {
	for(int i=0;i<14;i++){
		cin>>a[i];
		a[i+14] = a[i];
		a[i+28] = a[i];
	}
	for(int i=0;i<14;i++){
		csum = 0;
		a[i+14] = 0;
		a[i+28] = 0;
		for(int j=i+1;j<=i+14;j++){
			if(a[i]%14>=j-i){
				if(((a[i]/14)+1+a[j]) %2 == 0) csum+=((a[i]/14)+1+a[j]);
			}else{
				if(((a[i]/14)+a[j]) %2 == 0) csum+=((a[i]/14)+a[j]);
			}
		}
		a[i+14] = a[i];
		a[i+28] = a[i];
		ans = max(ans,csum);
	}
	cout<<ans<<endl;
	return 0;
}