// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#define patkan 9
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define uint unsigned int
#define ff first
#define ss second
#define abs(x) ((x < 0)?(-x):x)
// mylittlepony
using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	int N,M;
	cin >> N >> M;
	string s;
	vector<int> strO;
	vector<int> strD;
	for(int i =0; i < N; i++) {
		int a;
		cin >> s >> a;
		if(s == "DEF") strD.push_back(a);
		else strO.push_back(a);}
	sort(strD.begin(),strD.end());
	sort(strO.begin(),strO.end());
	vector<int> C(M);
	for(int i =0; i < M; i++) cin >> C[i];
	sort(C.begin(),C.end());
	
	int ansA =0;
	multiset<int> Sa;
	ALL_THE(C,it) Sa.insert(*it);
	ALL_THE(strD,it) {
		auto jt =Sa.upper_bound(*it);
		if(jt == Sa.end()) {ansA =-OVER9000; break;}
		Sa.erase(jt);}
	ALL_THE(strO,it) {
		auto jt =Sa.lower_bound(*it);
		if(jt == Sa.end()) {ansA =-OVER9000; break;}
		ansA +=*jt-*it;
		Sa.erase(jt);}
	ALL_THE(Sa,it) ansA +=*it;

	int ansB =0;
	multiset<int> Sb;
	ALL_THE(C,it) Sb.insert(*it);
	ALL_THE(strO,it) {
		if(Sb.empty()) break;
		auto jt =Sb.end(); jt--;
		if(*jt < *it) break;
		ansB +=*jt-*it;
		Sb.erase(jt);}

	cout << max(ansA,ansB) << "\n";
	return 0;}
        
// look at my code
// my code is amazing