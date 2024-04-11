#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

int m; 
int a[300000], b[300000]; 
int no[300000], rk[300000]; 

bool cmp(int x, int y) {
	return b[x] > b[y]; 
}

int main() {
	scanf( "%d", &m ); 
	for (int i = 1; i <= m; ++i) scanf( "%d", &a[i] ); 
	for (int i = 1; i <= m; ++i) scanf( "%d", &b[i] ); 
	for (int i = 1; i <= m; ++i) no[i] = i; 
	sort(a+1, a+m+1); 
	sort(no+1,no+m+1,cmp); 
	for (int i = 1; i <= m; ++i) rk[no[i]] = i; 
	for (int i = 1; i <= m; ++i) printf( "%d ", a[rk[i]] ); 
	puts( "" ); 
	return 0;
}