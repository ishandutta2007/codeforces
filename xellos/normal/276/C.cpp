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
// mylittlepony
using namespace std;
using namespace std::tr1;

int main() {
	int N,Q,a,b;
	scanf(" %d %d",&N,&Q);
	vector<long long> V(N);
	for(int i =0; i < N; i++) scanf(" %I64d",&V[i]);
	sort(V.begin(),V.end());
	
	vector<int> d(N,0);
	for(int i =0; i < Q; i++) {
		scanf(" %d %d",&a,&b);
		d[--a]++;
		if(b < N) d[b]--;}
	vector<long long> s(N);
	s[0] =d[0];
	for(int i =1; i < N; i++) s[i] =s[i-1]+d[i];
	sort(s.begin(),s.end());
	long long ans =0;
	for(int i =0; i < N; i++) ans +=s[i]*V[i];
	printf("%I64d\n",ans);
    return 0;}
        
// look at my code
// my code is amazing