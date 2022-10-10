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
using namespace std;
// mylittledoge

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	int N;
	cin >> N;

	vector<bool> isP(100000+tisic,true);
	vector<int> P;
	vector< vector<int> > D(100000+tisic);
	isP[1] =false;
	for(int i =2; i <= 100000; i++) if(isP[i]) {
		D[i].push_back(i);
		for(int j =2; j <= 100000/i; j++) {
			isP[i*j] =false;
			D[i*j].push_back(i);}
		P.push_back(i);}
	for(int i =0; i <= 100000; i++) reverse(begin(D[i]),end(D[i]));

	vector<bool> used(N+tisic,false);
	vector<int> ako(N+tisic,-1);
	vector< pair<int,int> > ans;
	for(int i =2; i <= N/2; i++) if(isP[i]) {
		ans.push_back(make_pair(i,2*i));
		ako[i] =2*i;
		ako[2*i] =i;
		used[i] =used[2*i] =true;}
	vector<int> fail;
	for(int i =N; i > 1; i--) if(!used[i]) {
		bool ok =false;
		ALL_THE(D[i],it) if(!ok) 
			for(int j =i-*it; j > 0; j -=*it) if(!used[j]) {
				used[j] =true;
				ako[i] =j;
				ako[j] =i;
				ans.push_back(make_pair(i,j));
				ok =true;
				break;}
		if(!ok && (2*i <= N || !isP[i])) fail.push_back(i);}

	if(fail.size() == 2) { // 8,9
		ALL_THE(ans,it) if(it->ff == 3 && it->ss == 6) {
			ans.erase(it);
			break;}
		ans.push_back(make_pair(8,6));
		ans.push_back(make_pair(9,3));}

	cout << ans.size() << "\n";
	ALL_THE(ans,it) cout << it->ff << " " << it->ss << "\n";
	return 0;}

// look at my code
// my code is amazing