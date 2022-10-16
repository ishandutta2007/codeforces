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

int main(){
//	openf("A", "r");
	int n;
	cin >> n;
	vector <int> v(n);
	for (int i = 0; i < n; i++)
		scanf("%d ", &v[i]);
	
	sort(v.begin(), v.end());

	vector <int> p , o, z;

	for (int i = 0; i < n; i++) {
		if (v[i] == 0) z.push_back(0);
		if (v[i] > 0) p.push_back(v[i]);
		if (v[i] < 0) o.push_back(v[i]);
	}

	if (p.size() > 0) {
		for (int i = 0; i < p.size(); i++) cout << p[i] << " ";
		for (int i = 0; i < o.size()/2; i++) cout << o[2 * i] << " " << o[2 * i + 1] << " ";
	} else {
		if (o.size() >= 2) {
			for (int i = 0; i < o.size()/2; i++)
				cout << o[2 * i] << " " << o[2 * i + 1] << " ";
		} else {
			if (z.size() > 0)
				cout << "0";
			else
				cout << o[o.size() - 1];
		}
	}
	return 0;
}