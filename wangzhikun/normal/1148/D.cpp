#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define debug(x) cerr<<#x<<'='<<x<<endl
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

ll n,a[300010],b[300010];
vector< pair<int,int> > A,B;

int main() {
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i]);read(b[i]);
		if(a[i]<b[i]){
			A.push_back(make_pair(-a[i],i));
		}else{
			B.push_back(make_pair(a[i],i));
		}
	}
	sort(A.begin(),A.end());sort(B.begin(),B.end());
	cout<<max(A.size(),B.size())<<endl;
	if(A.size()>B.size()){
		for(auto ct:A){
			cout<<ct.second<<' ';
		}
	}else{
		for(auto ct:B){
			cout<<ct.second<<' ';
		}
	}
	return 0;
}