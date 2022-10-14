//
//  main.cpp
//  Round 483
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

ll mod = 1e9+7;
ll gcd(ll a,ll b){
	if(b == 0) return a;
	return gcd(b, a%b);
}
ll read(){
	ll an = 0;char ch = getchar();
	while(!isdigit(ch))ch = getchar();
	while(isdigit(ch)){
		an = an*10+ch-48;
		ch = getchar();
	}
	return an;
}

ll q,a,b,c,d,ccc;
double cc;
int main() {
	cin>>q;
	for(int i=0;i<q;i++){
		a = read();
		b = read();
		c = read();
		cc = c;
		ccc = c;
		d = gcd(a,b);
		a/=d;
		b/=d;
		int ans = 0;
		for(int i=0;i<60;i++){
			d = gcd(c,b);
			while(b%d == 0 && d!=1)b/=d;
			if(b == 1)break;
			if(b!=1 && gcd(c,b) == 1)break;
		}
		if(b == 1){
			cout<<"Finite"<<endl;
		}else{
			cout<<"Infinite"<<endl;
		}
	}
	return 0;
}