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
#define OVER9000 1234567890LL
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
using namespace std;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector< vector<int> > Y(100000+tisic);
	vector<int> Cl;
	vector< vector<int> > Yl(100000+tisic);
	vector< vector< pair<int,int> > > Q(100000+tisic);
	vector< vector< pair<int,int> > > Ql(100000+tisic);
	for(int i =0; i < N; i++) {
		int x,y;
		cin >> x >> y;
		Y[y].push_back(x);}

	for(int i =0; i <= 100000; i++) if(Y[i].size() <= 300)
		for(int j =0; j < Y[i].size(); j++) for(int k =j+1; k < Y[i].size(); k++) {
			int d =abs(Y[i][j]-Y[i][k]);
			if(i-d >= 0) Q[i-d].push_back(make_pair(Y[i][j],Y[i][k]));
			if(i+d <= 100000) Ql[i+d].push_back(make_pair(Y[i][j],Y[i][k]));}
		else {
			Cl.push_back(i);
			Yl[i] =Y[i];}

	long long ans =0;
	vector<int> P(100000+tisic,0);
	for(int i =0; i <= 100000; i++) {
		ALL_THE(Y[i],it) P[*it]++;
		ALL_THE(Q[i],it)
			if(P[it->ff] > 0 && P[it->ss] > 0) ans++;
		if(Y[i].size() > 300)
			ALL_THE(Ql[i],it) if(P[it->ff] > 0 && P[it->ss] > 0) ans++;
		ALL_THE(Y[i],it) P[*it]--;}

	vector< vector< pair<int,int> > > Cc(100000+tisic);

	for(int i =0; i < Cl.size(); i++) for(int j =i+1; j < Cl.size(); j++) {
		ALL_THE(Y[Cl[i]],it) P[*it]++;
		int d =Cl[j]-Cl[i];
		ALL_THE(Y[Cl[i]],it) if(*it-d >= 0 && P[*it-d] > 0)
			Cc[Cl[j]].push_back(make_pair(*it,*it-d));
		ALL_THE(Y[Cl[i]],it) P[*it]--;
		}

	for(int i =0; i <= 100000; i++) {
		ALL_THE(Y[i],it) P[*it]++;
		ALL_THE(Cc[i],it) if(P[it->ff] > 0 && P[it->ss] > 0) ans++;
		ALL_THE(Y[i],it) P[*it]--;}

	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing