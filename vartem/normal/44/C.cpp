#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <sstream>
#include <fstream>
#include <map>
#include <algorithm>
#include <limits>
#include <climits>
#define sqr(a) ((a)*(a))
#define pb push_back
#define fs first
#define sd second
#define debug(a) cout<<#a<<" = "<<a<<endl;
#define all(a) a.begin(),a.end()
#define forn(i,n) for(int i=0;i<n;i++)
#define int64 long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;

typedef vector<int> vint;
typedef vector<vector<int> > vvint;

const double EPS=1E-10;


void openf(const string &fname, string mode=""){
	string fin=fname+".in";
	string fout=fname+".out";
	if (mode.size()==1 && mode[0]=='r') freopen(fin.data(), "r", stdin);
	if (mode.size()==1 && mode[0]=='w') freopen(fout.data(), "w", stdout);
	if (mode.size()==2 ) {
		freopen(fin.data(), "r", stdin);
		freopen(fout.data(), "w", stdout);
	}
}

int main(){
	//openf("A", "r");
	int n, m;
	cin >> n >> m;
	vector <int> v(n, 0);
	for (int i=0; i<m; i++){
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		for (int j=a; j<=b; j++) v[j]++;
	}
	for (int i=0; i<n; i++) {
		if (v[i]!=1) {
			cout << i+1 << " " << v[i];
			return 0;
		}
	}
	cout << "OK";
	return 0;
}