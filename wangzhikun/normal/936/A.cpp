//
//  main.cpp
//  Round 467
//
//  Created by  on 2018/7/19.
//  Copyright  2018 . All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
typedef long double lld;

ll k,d,t,ont,oft;
int main() {
	cin>>k>>d>>t;
	t*=2;
	ont = k;
	oft = (d-k%d)%d;
	//cout<<ont<<' '<<oft<<endl;
	ll et = ont*2+oft;
	ll stt = t/et;
	if(stt*et+ont*2>=t){
		cout<<stt*(ont+oft)+(t-stt*et)/2;
		if((t-stt*et)%2)cout<<".5"<<endl;
	}else{
		cout<<stt*(ont+oft)+ont+(t-stt*et-ont*2)<<endl;
	}
	return 0;
}