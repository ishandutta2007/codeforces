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
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int K;
	char ch[1000];
	scanf(" %d %s",&K,ch);
	string s =(string)ch;
	map<char,int> M;
	for(int i =s.length()-1; i >= 0; i--) M[s[i]] =i;
	if((int)M.size() < K) {printf("NO\n"); return 0;}
	printf("YES\n");
	vector<int> br;
	ALL_THE(M,it) br.push_back(it->ss);
	sort(begin(br),end(br));
	br.resize(K);
	br.push_back(s.length());
	for(int i =0; i < K; i++) printf("%s\n",s.substr(br[i],br[i+1]-br[i]).c_str());
	return 0;}

// look at my code
// my code is amazing