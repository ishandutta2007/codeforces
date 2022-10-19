#include<bits/stdc++.h>
using namespace std;

const int N = 1000005;
#define int long long

int a , b , c1 , c2 , s1, s2;

vector<pair<int,int> >V;

int gcd(int x ,int y) {
	return (y == 0) ? x: gcd(y, x%y);
}

main() {
	cin>>a>>b;
	if(a == b) {
		puts("Equal");
		return 0;
	}
	int p = a * b / gcd(a,b);
	for(int i = 1;i <= p/a;i ++) {
		V.push_back(make_pair(a * i , 1)); 
	}
	V.pop_back();
	for(int i = 1;i <= p/b;i ++) {
		V.push_back(make_pair(b * i , 2)); 
	}
	V.pop_back();
	if(a < b) V.push_back(make_pair(p,2)); else V.push_back(make_pair(p,1));
	sort(V.begin() , V.end());
	int ppp = 0 , bef = 0;
	for(int i = 0;i <(int)V.size();i ++) {
		int p = V[i].first;
		if(V[i].second == 1) c1 += p - bef;
		else c2 += p - bef;
		bef = p;
//		cerr<<p<<endl;
	}
	if(c1 == c2) {
		puts("Equal");
		return 0;
	}
	if(c1 < c2) {
		puts("Masha");
		return 0;
	}
	puts("Dasha");
}