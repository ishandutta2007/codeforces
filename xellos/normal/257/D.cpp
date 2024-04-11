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
	scanf(" %d",&N);
	vector<int> V(N);
	for(int i =0; i < N; i++) scanf(" %d",&V[i]);
	vector<int> ans(N,0);
	vector<bool> rot(N,false); // rotate signs
	ans[N-1] =V[N-1];
	for(int i =N-2; i >= 0; i--) {
		if(ans[i+1] <= 0) ans[i] =V[i]+ans[i+1];
		else {
			rot[i] =true;
			ans[i] =V[i]-ans[i+1];}}
			
	int x =(int)(ans[0] < 0);
	string s;
	for(int i =0; i < N; i++) {
		if(x%2 == 0) s +='+';
		else s +='-';
		x +=(int)rot[i];}
	printf("%s\n",s.c_str());
	return 0;}

// look at my code
// my code is amazing