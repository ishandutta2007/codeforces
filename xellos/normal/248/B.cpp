// iostream is too mainstream
#include <cstdio>
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

vector<int> num;

bool div() {
	int x =0;
	for(int i =0; i < num.size(); i++) x =(x*10+num[i])%210;
	if(x == 0) return true;
	return false;}

int main() {
	int N;
	scanf(" %d",&N);
	if(N <= 2) {
		printf("-1\n");
		return 0;}
	num.push_back(1);
	for(int i =0; i < N-1; i++) num.push_back(0);
	
	for(int i =1; i <= 210; i++) {
		int j =i;
		for(int k =0; k < 3; k++) {
			num[N-1-k] =j%10;
			j /=10;}
		if(div()) {
			for(int k =0; k < N; k++) printf("%d",num[k]);
			printf("\n");
			return 0;}
	}
	printf("-1\n");
	return 0;}

// look at my code
// my code is amazing