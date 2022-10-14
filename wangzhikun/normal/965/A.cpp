//
//  main.cpp
//  Round 476
//
//  Created by  on 2018/4/26.
//  Copyright  2018 . All rights reserved.
//

#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int k,n,s,p;

int main() {
	cin>>k>>n>>s>>p;
	cout<<((((n+s-1)/s)*k)+p-1)/p<<endl;
	return 0;
}