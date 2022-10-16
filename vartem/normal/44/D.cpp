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


void dbg(vector <int> a){
	for (size_t i=0;i<a.size();i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}

void dbg(vector <vector <int> > a){
	for (size_t i=0;i<a.size();i++){
		dbg(a[i]);
	}
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

vector <long double> x, y, z;
vector <long double> ds;

inline long double dst(int i) {
	return sqrt(x[i]*x[i] + y[i]*y[i] + z[i]*z[i]);
}

inline long double C(int i, int j) {
	long double dx = x[i] - x[j], dy = y[i] - y[j], dz = z[i] - z[j];
	return sqrt(dx*dx + dy*dy + dz*dz);
}


int main(){
//	openf("A", "r");
	int n;
	cin >> n;
	n--;

	x.resize(n);
	y = x;
	z = x;

	long double fx, fy, fz;
	cin >> fx >> fy >> fz;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i] >> z[i];
		//scanf("%Lf %Lf %Lf\n", &x[i], &y[i], &z[i]);
		x[i] -= fx;
		y[i] -= fy;
		z[i] -= fz;
	}
	
	ds.resize(n);
	for (int i = 0; i < n; i++) ds[i] = dst(i);

	long double m = 10000000000000.0;
	long double a, b, c, t;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (i == j) continue;
			a = ds[i];
			b = ds[j];
			if (a > b) swap(a, b);
			c = C(i, j);
			t = (c - (b - a))/2.0 + b;
			m = min(m, t);
		}
	}
	cout.precision(10);
	cout << fixed << m;
	return 0;
}