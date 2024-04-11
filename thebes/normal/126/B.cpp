#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;

const int MN=1e6+6;
int hsh[MN], pw[MN]={1}, N, i, lo, hi;
int getH(int x,int y){return hsh[y]-hsh[x-1]*pw[y-x+1];}
vector<int> vec;

bool check(int m){
	int h=getH(1,m),fnd=0;
	for(i=2;i+m-1<N;i++)
		if(getH(i,i+m-1)==h) fnd=1;
	return fnd;
}

int main(){
	string s; cin >> s;
	N = s.size();
	for(i=1;i<=N;i++){
		hsh[i]=hsh[i-1]*31+s[i-1];
		pw[i]=pw[i-1]*31;
	}
	for(i=1;i<N;i++){
		if(getH(1,i)==getH(N-i+1,N))
			vec.push_back(i);
	}
	lo=0; hi=vec.size();
	while(lo<hi){
		int m=(lo+hi)/2;
		if(check(vec[m])) lo=m+1;
		else hi=m;
	}
	if(hi==0) printf("Just a legend\n");
	else printf("%s\n",s.substr(0,vec[hi-1]).c_str());
	return 0;
}