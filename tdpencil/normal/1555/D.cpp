#include <bits/stdc++.h>
using namespace std;
const int mxN=2e5,M=1e9+7;
#define long long ll
#define push_back pb
// a1 + a3 + a5 ... = a2 + a4 + a6 ...
// you can remove an element from either side
// make them both equal
// removing ith elements turns
// a1 + a3 + a5 + ... a8 + a10 = a2 + 
// if you remove two elements, then the sum o the numbers must be 

int n, m,l,r;
string s;
// have a query [l, r] for each 
// sort by l
// then to find proper r
// find number of numbers in query 
// that match up

int p[6][mxN];
string alpha = "abc";
void build() {
    int c=0;
    do {
        for(int i=0;i<n;i++) {
        	if(s[i] != alpha[i%3]) p[c][i]=1;
		}
	
		partial_sum(p[c], p[c]+n, p[c]);
		++c;
    } while(next_permutation(alpha.begin(), alpha.end()));
}

int qry(int *p) {
	return l?p[r]-p[l-1]:p[r];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	cin >> s;
	
	build();
	
	while(m--) {
		cin >> l >> r;
		--l, --r;
		
		cout << min({qry(p[0]), qry(p[1]), qry(p[2]), qry(p[3]), qry(p[4]), qry(p[5])}) << "\n";
	}
    	
}