// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890123456780LL
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-10
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define M_PI 3.14159265359
using namespace std;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,D;
	cin >> N >> D;
	vector< pair<double,double> > I;
	for(int i =0; i < N; i++) {
		int x,y,r;
		cin >> x >> y >> r;
		double d =sqrt(x*x+y*y);
		int iA =0, iB =1e5;
		while(iB-iA > 1) {
			int j =(iA+iB)/2;
			if(1LL*(j*D+r)*(j*D+r) >= x*x+y*y) iB =j;
			else iA =j;}
		int iC =0, iD =1e5;
		while(iD-iC > 1) {
			int j =(iC+iD)/2;
			if(1LL*(j*D-r)*(j*D-r) > x*x+y*y) iD =j;
			else iC =j;}
		double phi =atan2(y,x);
		for(int i =iB; i <= iC; i++) {
			double delta =acos((i*i*D*D+x*x+y*y-r*r)/2.0/d/i/D);
			I.push_back(make_pair(phi-delta,phi+delta));}
		}
	vector<double> Iz,Ik;
	int akt =0, ans =0;
	for(int i =0; i < I.size(); i++) {
		while(I[i].ff < 0) I[i].ff +=2*M_PI, I[i].ss +=2*M_PI;
		while(I[i].ff > 2*M_PI) I[i].ff -=2*M_PI, I[i].ss -=2*M_PI;
		if(I[i].ss >= 2*M_PI-soclose) akt++;
while(I[i].ss > 2*M_PI-soclose) I[i].ss -=2*M_PI;
		Iz.push_back(I[i].ff);
		Ik.push_back(I[i].ss);}
	sort(Iz.begin(),Iz.end());
	sort(Ik.begin(),Ik.end());
	ans =akt;
	int a =0;
	for(int i =0; i < Iz.size(); i++) {
		while(a < Ik.size() && Ik[a] < Iz[i]-soclose) {
			akt--;
			a++;}
		akt++;
		ans =max(ans,akt);}
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing