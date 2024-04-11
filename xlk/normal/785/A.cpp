#include <bits/stdc++.h>
using namespace std;
string s;
int n;
int main() {
	cin >> n;
	int z = 0;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "Tetrahedron") {
			z += 4;
		}
		if (s == "Cube") {
			z += 6;
		}
		if (s == "Octahedron") {
			z += 8;
		}
		if (s == "Dodecahedron") {
			z += 12;
		}
		if (s == "Icosahedron") {
			z += 20;
		}
	}
	cout << z << endl;
	return 0;
}