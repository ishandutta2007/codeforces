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

int main() {
	int N;
	cin >> N;
	vector< pair<int,int> > A(2*N);
	for(int i =0; i < 2*N; i++) {
		cin >> A[i].first;
		A[i].second =i%N;}
	sort(A.begin(),A.end());
	long long M;
	cin >> M;
	
	vector<long long> poc(2*N+1,1);
	vector<int> pow2(2*N+1,0);
	for(int i =2; i <= 2*N; i++) {
		long long a =(long long)i;
		int p =0;
		while(a%2 == 0) {
			a /=2;
			p++;}
		poc[i] =(poc[i-1]*a)%M;
		pow2[i] =pow2[i-1]+p;
		if(poc[i] < 0) poc[i] +=M;}

	long long ans =1, p =0;
	int a =1, b =0;
	for(int i =1; i < 2*N; i++) {
		if(A[i] == A[i-1]) b++;
		if(A[i].first == A[i-1].first) a++;
		else {
			ans =(ans*poc[a])%M;
			if(ans < 0) ans +=M;
			p +=pow2[a];
			a =1;}}
	ans =(ans*poc[a])%M;
	p +=pow2[a];
	p -=b;
	if(ans < 0) ans +=M;
	for(int i =0; i < p; i++) {
		ans =(2*ans)%M;
		if(ans < 0) ans +=M;}
	cout << ans << endl;
		
	return 0;}

// look at my code
// my code is amazing