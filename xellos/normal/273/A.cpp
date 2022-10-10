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
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 10e-7
// mylittlepony
using namespace std;

struct fin {
	vector<long long> T;
	
	fin(int N) {
		T.resize(N+1,0);}
	
	int lastone(int x) {return x&(x^(x-1));}
	
	void put(int pos, long long val) {
		for(int i =pos+1; i < T.size(); i +=lastone(i)) T[i] =max(T[i],val);
		return;}
	
	long long get(int pos) {
		long long ret =0;
		for(int i =pos+1; i > 0; i -=lastone(i)) ret =max(ret,T[i]);
		return ret;} 
	};
	
int main() {
	int N,b;
	cin >> N;
	long long a;
	stack< pair<int,long long> > S;
	vector<long long> I(N);
	for(int i =0; i < N; i++) {
		cin >> a;
		I[i] =a;}
	for(int i =N-1; i >= 0; i--) S.push(make_pair(i,I[i]));
	
	int M;
	cin >> M;
	for(int i =0; i < M; i++) {
		cin >> b >> a;
		long long c =0;
		while(!S.empty()) {
			if(S.top().first >= b) break;
			c =max(c,S.top().second);
			S.pop();}
		cout << c << endl;
		S.push(make_pair(0,c+a));}
	return 0;}

// look at my code
// my code is amazing