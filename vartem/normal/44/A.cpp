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
	string s;
	int n;
	scanf("%d\n", &n);
	for (int i=0; i<n; i++) {
		getline(cin ,s);
		//cout << s << endl;
		t.insert(s);
	}
	cout << t.size();
	return 0;
}