#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

int n, start, X; 
int tot; 

void ask(int i, int &value, int &next) {
	printf( "? %d\n", i ); 
	tot++; 
	//if (tot > 1900) while(1); 
	fflush(stdout); 
	scanf( "%d%d", &value, &next ); 
	//value = i; 
	//if (i == n) next = -1; 
	//else next = i+1; 
	//cout<<tot<<endl; 
}

int main() {
	//srand(time(0)); 
	mt19937 myrand(time(0)); 
	scanf( "%d%d%d", &n, &start, &X ); 
	int besti = start, best; 
	int value, next; 
	ask(start,value,next); 
	if (value >= X) {
		printf("! %d\n", value); 
		fflush(stdout); 
		return 0; 
	}
	best = value; 
	for (int i = 1; i <= 1500; ++i) {
		int x = myrand() % n+1; 
		ask(x, value, next); 
		if (value > best && value < X) {
			besti = x; 
			best = value; 
		}
	}
	int x = besti; 
	while (1) {
		ask(x,value,next); 
		if (value >= X) {
			printf("! %d\n", value); 
			fflush(stdout); 
			return 0; 
		}
		if (next == -1) {
			puts( "! -1" ); 
			fflush(stdout); 
			return 0; 
		}
		x = next; 
	}
}