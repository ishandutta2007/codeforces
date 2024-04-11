#include <set>
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

typedef pair<pair<int,int>,int> piii;
ll n,ca[300010],b[300010];
pii a[300010];
vector<piii > LG;
void draw(int x,int y,int z){
	LG.push_back(make_pair(make_pair(x,y),z));
}

int main() {
	read(n);
	ll csu = 0,dsu;
	for(int i=1;i<=n;i++){
		read(ca[i]);
		csu+=ca[i];
		a[i] = make_pair(ca[i],i);
	}
	for(int i=1;i<=n;i++){
		read(b[i]);
		dsu+=b[i];
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	if(csu!=dsu){cout<<"NO\n";return 0;}
	if(a[1].first > b[1] ||a[n].first < b[n]){cout<<"NO\n";return 0;}
	
	int j = 1;
	for(int i = 1;i <= n;i++) {
		if(a[i].first > b[i]) {cout<<"NO\n";return 0;}
		while(a[i].first != b[i] && j <= n) {
			while(a[j].first <= b[j] && j <= n) j++;
			if(j > n) {cout<<"NO\n";return 0;}
			if(a[j].first - b[j] >= b[i] - a[i].first) {
				draw(a[i].second , a[j].second , b[i] - a[i].first);
				a[j].first -= (b[i] - a[i].first);
				a[i].first = b[i];break;
			}
			else {
				draw(a[i].second , a[j].second , a[j].first - b[j]);
				a[i].first += (a[j].first - b[j]);
				a[j].first = b[j];j++;
			}
		}
		if(j > n) {cout<<"NO\n";return 0;}
	}
	cout<<"YES"<<endl;
	cout<<LG.size()<<endl;
	for(auto ct:LG){
		cout<<ct.first.first<<' '<<ct.first.second<<' '<<ct.second<<endl;
	}
	return 0;
}