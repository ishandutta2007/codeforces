// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <tr1/unordered_map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#define dibs reserve
#define OVER9000 234567890
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
// so much chocolate
#define ff first
#define ss second
#define uint unsigned int
#define sent(x,y) (x >= 0 && y >= 0 && x < R && y < C)
// mylittlepony
using namespace std;

long long gcd(long long a, long long b) {
	if(a > b) swap(a,b);
	if(a == 0) return b;
	return gcd(b%a,a);}

int main() {
	cin.sync_with_stdio(0);
	int N;
	cin >> N;
	long long ansA =0, ansB =N;
	vector<long long> D(N,0);
	for(int i =0; i < N; i++) {
		cin >> D[i];
		ansA +=D[i];}
	sort(D.begin(),D.end());
//	for(int i =0; i < N; i++) for(int j =i+1; j < N; j++) ansA +=(N-2)*2*(D[j]-D[i]);
	for(int i =1; i < N; i++) ansA +=2*(long long)D[i]*(long long)i;
	for(int i =0; i < N-1; i++) ansA -=2*(long long)D[i]*(long long)(N-1-i);
	long long d =gcd(ansA,ansB);
	cout << ansA/d << " " << ansB/d << "\n";
    return 0;}
        
// look at my code
// my code is amazing