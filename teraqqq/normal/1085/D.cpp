#include <iostream>
#include <iomanip>

using namespace std;

const int N = 1e5;

int n, a, b;
double s, m;
int x[N];

void set_x(int v) {
	if(++x[v] == 2)
		--m;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> s; m = n; 
	for(int i = 0; i < n-1; ++i) {
		cin >> a >> b;
		set_x(a-1); set_x(b-1);
	}

	cout << setprecision(9) << 2.0 * s / m;
}