// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <tr1/unordered_map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-5
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
using namespace std;
using namespace std::tr1;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int l1,r1,l2,r2;
	cin >> l1 >> r1 >> l2 >> r2;
	int ans =0;
	for(int i =1; i <= 30; i++) {
		// delitelne 1<<i, < l1 / > r1
		int k1l =l1/(1<<i), k1r =r1/(1<<i);
		while(k1l*(1<<i) >= l1) k1l--;
		while((k1l+1)*(1<<i) < l1) k1l++;
		while(k1r*(1<<i) <= r1) k1r++;
		while((k1r-1)*(1<<i) > r1) k1r--;
		int k2l =l2/(1<<i), k2r =r2/(1<<i);
		while(k2l*(1<<i) >= l2) k2l--;
		while((k2l+1)*(1<<i) < l2) k2l++;
		while(k2r*(1<<i) <= r2) k2r++;
		while((k2r-1)*(1<<i) > r2) k2r--;
		if(k2r-k2l > 2 && k1l-k1r > 2) {
			ans =max(ans,(1<<i)-1);
			continue;}
		vector< pair<int,int> > p1,p2;
		for(int k =k1l; k < k1r; k++) {
			int x =0, y =(1<<i)-2;
			if(k == k1l) x =max(x,(l1%(1<<i) == 0)?((1<<i)-1):(l1%(1<<i)-1));
			if(k == k1r-1) y =min(y,r1%(1<<i)-1);
			p1.push_back(make_pair(x,y));
			if(k == k1l+1) k =max(k,k1r-1);}
		for(int k =k2l; k < k2r; k++) {
			int x =0, y =(1<<i)-2;
			if(k == k2l) x =max(x,(l2%(1<<i) == 0)?((1<<i)-1):(l2%(1<<i)-1));
			if(k == k2r-1) y =min(y,r2%(1<<i)-1);
			p2.push_back(make_pair(x,y));
			if(k == k2l+1) k =max(k,k2r-1);}
		ALL_THE(p1,it) ALL_THE(p2,jt) ans =max(ans,min(jt->ss,it->ss)-max(it->ff,jt->ff)+1);
		}
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing