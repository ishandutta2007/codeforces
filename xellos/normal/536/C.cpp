#include <bits/stdc++.h>
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
#define OVER9000 1234567890
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
#define dbl long double
#define pi 3.14159265359
using namespace std;
// mylittledoge

bool vs(pair<int,int> A, pair<int,int> B, pair<int,int> O) {
	pair<dbl,dbl> a,b,o;
	a =make_pair(1.0/A.ff,1.0/A.ss);
	b =make_pair(1.0/B.ff,1.0/B.ss);
	o =make_pair(1.0/O.ff,1.0/O.ss);
//	cout << (o.ff-a.ff) << " " << (b.ss-o.ss) << " " << (a.ss-o.ss) << " " << (o.ff-b.ff) << "\n";
	return (1LL*(O.ss-A.ss)*(B.ff-O.ff)*1LL*A.ff*B.ss-1LL*(A.ff-O.ff)*(O.ss-B.ss)*1LL*B.ff*A.ss > soclose);}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
/*	existuju R,S: R*r-1[i]+S*s-1[i] <= R*r-1[j]+S*s-1[j]
R/2+S/2 <= R/3+S, S/3+R
S >= R/3, S/3 <= R <= 3S
	nikto nie je rychlejsi v oboch
	s[i] > s[j], r[i] < r[j]
	S*(s[i]-s[j]) <= R*(r[j]-r[i])
	S/R <= (r-1[j]-r-1[i])/(s-1[i]-s-1[j])
	s[i] < s[j], r[i] > r[j]
	S*(s[j]-s[i]) >= R*(r[i]-r[j])
	S/R >= (r-1[i]-r-1[j])/(s-1[j]-s-1[i])
*/	int N;
	cin >> N;
	map< pair<int,int>, vector<int> > M;
	vector< pair<int,int> > RS;
	for(int i =0; i < N; i++) {
		int r,s;
		cin >> r >> s;
		auto it =M.find(make_pair(r,s));
		if(it != M.end()) it->ss.push_back(i+1);
		else {
			M[make_pair(r,s)] =vector<int>(1,i+1);
			RS.push_back(make_pair(r,s));}
		}
	N =RS.size();
	sort(begin(RS),end(RS));

	// zahod pomalsich v oboch
	stack< pair<int,int> > S;
	for(int i =0; i < N; i++) {
		while(!S.empty() && S.top().ff <= RS[i].ss) S.pop();
		S.push(make_pair(RS[i].ss,i));}
	vector< pair<int,int> > V;
	while(!S.empty()) {V.push_back(RS[S.top().ss]); S.pop();}
	N =V.size();

//	convex hull
	vector<int> H(1,0);
	for(int i =1; i < N; i++) {
		while(H.size() > 1 && vs(V[H[H.size()-1]],V[H[H.size()-2]],V[i])) H.pop_back();
		H.push_back(i);}

	vector<int> ans;
	for(int i =0; i < H.size(); i++) 
		ALL_THE(M[V[H[i]]],it) ans.push_back(*it);

	sort(begin(ans),end(ans));
	for(int i =0; i < ans.size(); i++) cout << ans[i] << ((i == ans.size()-1)?"\n":" ");
	return 0;}

// look at my code
// my code is amazing