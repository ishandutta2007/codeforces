//
//  main.cpp
//  Round 482
//
//  Created by  on 2018/5/15.
//  Copyright  2018 . All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll n;
int main() {
	cin>>n;
	n+=1;
	if(n%2 && n>1){
		cout<<n<<endl;
	}else{
		cout<<n/2<<endl;
	}
	return 0;
}