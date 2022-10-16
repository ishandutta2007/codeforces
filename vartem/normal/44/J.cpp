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


void dbg(vector <char> a){
	for (size_t i=0;i<a.size();i++){
		printf("%c",a[i]);
	}
	printf("\n");
}

void dbg(vector <vector <char> > a){
	for (size_t i=0;i<a.size();i++){
		dbg(a[i]);
	}
	cout << endl << "-------------" << endl;
}

void dbg(vector <string> a){
	for (size_t i=0;i<a.size();i++){
		printf("%s\n",a[i].data());
	}
}

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
int n, m;
vector <vector <char> > v;
vector <vector <char> > r;




bool add(int i, int j, bool h) {
	bool a[15];
	memset(a, 0, sizeof(a));
	if (h) {
		for (int x = i - 1; x <= i + 1; x++) {
			for (int y = j - 1; y <= j + 3; y++) {
				if (r[x][y] != '.')
					a[r[x][y] - 'a'] = true;
			}
		}
	} else {
		for (int x = i - 1; x <= i + 3; x++) {
			for (int y = j - 1; y <= j + 1; y++) {
				if (r[x][y] != '.')
					a[r[x][y] - 'a'] = true;
			}
		}
	}
	char c;
	for (int x = 0; x < 15; x++) {
		if (!a[x]) {
			c = x + 'a';
			break;
		}
	}
	if (c > 'd') {
		return false;
	}
	if (h) {
		v[i][j] = '.';
		v[i][j + 1] = '.';
		v[i][j + 2] = '.';
		r[i][j] = c;
		r[i][j + 1] = c;
		r[i][j + 2] = c;
	} else {
		v[i][j] = '.';
		v[i + 1][j] = '.';
		v[i + 2][j] = '.';
		r[i][j] = c;
		r[i + 1][j] = c;
		r[i + 2][j] = c;
	}
	return true;
}


int main(){
	//openf("J", "r");
	scanf("%d %d\n", &n, &m);
	v.resize(n + 20, vector <char> (m + 20, '.'));
	r = v;
	int kb = 0, kw = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%c", &v[i + 10][j + 10]);
			if (v[i + 10][j + 10] == 'w') kw++;
			if (v[i + 10][j + 10] == 'b') kb++;
		}
		scanf("\n");
	}
	//dbg(v);

	if ((kw + kb) % 3 != 0) {
		cout << "NO";
		return 0;
	} else {
		int t = (kb + kw) / 3;
		if (kb != t) {
			cout << "NO";
			return 0;
		}
	}

	for (int i = 10; i < n + 10; i++) {

		for (int j = 10; j < m + 10; j++) {

			if (v[i][j] == '.') continue;
			if (v[i][j] == 'b') {
				cout << "NO";
				return 0;
			}
			if (v[i][j + 1] == 'b' && v[i][j + 2] == 'w') {
				if (!add(i, j, true)) {
					cout << "NO";
					return 0;
				}
			} else {
				if (v[i + 1][j] == 'b' && v[i + 2][j] == 'w') {
					if (!add(i, j, false)){
						cout << "NO";
						return 0;
					}
				}
			}
			//dbg(r);
		}
	}
	cout << "YES" << endl;
	for (int i = 10; i < n + 10; i++) {
		for (int j = 10; j < m + 10; j++) {
			printf("%c", r[i][j]);
		}
		cout << endl;
	}
	return 0;
}