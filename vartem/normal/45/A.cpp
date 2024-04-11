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

set <string> t;
int main(){
	//openf("A", "r");
	vector <string> v;
	string t;
	int k;
	cin >> t >> k;
	v.pb("January");
	v.pb("February");
	v.pb("March");
	v.pb("April");
	v.pb("May");
	v.pb("June");
	v.pb("July");
	v.pb("August");
	v.pb("September");
	v.pb("October");
	v.pb("November");
	v.pb("December");
	int n;
	for (int i = 0 ; i < 12; i++)
		if (v[i] == t) n = i;
	cout << v[(n + k) % 12];
	return 0;
}