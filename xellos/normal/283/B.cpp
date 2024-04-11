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
#define chocolate win
// mylittlepony
using namespace std;

void countT(int x, int N, vector<long long> &dy, vector<long long> &V) {
	if(dy[x] > 0) return;
	int a =x+(int)V[x];
	if(a >= N) {dy[x] =V[x]; return;}
	long long b =V[x]+V[a];
	a -=(int)V[a];
	if(a < 0) {dy[x] =b; return;}
	if(a == 0) {dy[x] =-1; return;}
	dy[x] =-1;
	if(dy[a] == -1) return;
	countT(a,N,dy,V);
	if(dy[a] == -1) return;
	dy[x] =b+dy[a];
	return;}
	
int main() {
	int N;
	cin >> N;
	vector<long long> V(N);
	for(int i =1; i < N; i++) scanf(" %I64d",&V[i]);
	vector<long long> dy(N,0);
	
	for(int i =1; i < N; i++) countT(i,N,dy,V);
	
	for(int i =1; i < N; i++) {
		int a =i-V[i];
		if(a < 0) {printf("%I64d\n",i+V[i]); continue;}
		if(a == 0 || dy[a] == -1) {printf("-1\n"); continue;}
		printf("%I64d\n",dy[a]+i+V[i]);}
	return 0;}

// look at my code
// my code is amazing