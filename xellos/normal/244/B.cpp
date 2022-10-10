// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <tr1/unordered_set>
#include <tr1/unordered_map>
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
using namespace std::tr1;
	
int res(int x, int y, int N, int c) { // c-ciferne
	int a =1, ans =0;
	for(int i =0; i < c; i++) a *=2;
	if(x == y) {
		int b =0;
		for(int i =0; i < c; i++) b =10*b+x;
		if(b <= N && b > 0) return 1;
		else return 0;}
	for(int i =1; i < a-1; i++) {
		int b =i, d =0;
		for(int j =0; j < c; j++) {
			d *=10;
			if(b%2 == 0) d +=x;
			else d +=y;
			b /=2;
			if(d == 0) break;}
		if(d <= N && d > 0) ans++;}
	return ans;}

int main() {
	int N;
	scanf(" %d",&N);
	
	int ans =0;
	for(int i =0; i < 10; i++) for(int j =i; j < 10; j++) for(int c =1; c < 10; c++) ans +=res(i,j,N,c);
	if(N == 1000000000) ans++;
	printf("%d\n",ans);
	return 0;}
        
// look at my code
// my code is amazing