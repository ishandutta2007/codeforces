#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define pb push_back;

struct point{
    int x;
    int y;
};

int main() {
	
	ios::sync_with_stdio(false);
	point a,b,c;
	cin >> a.x >> a.y;
	cin >> b.x >> b.y;
	cin >> c.x >> c.y;
	cout << 3 << endl;
	//if AB
	cout << (b.x-a.x+c.x) << " " << (b.y-a.y+c.y) << endl;
	//if BC
	cout << (c.x-b.x+a.x) << " " << (c.y-b.y+a.y) << endl;
	//if CA
	cout << (a.x-c.x+b.x) << " " << (a.y-c.y+b.y) << endl;
}