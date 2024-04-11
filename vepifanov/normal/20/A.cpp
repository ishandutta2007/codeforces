#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main () {
	string s;
	cin >> s;
	string w = "";
	for (int i = 0; i < s.size (); i++)
		if (i == 0 || s[i] != '/' || s[i - 1] != '/')
			w += s[i];
	if (w.size () > 1)
		while (w[w.size () - 1] == '/') w.erase (w.size () - 1);
	cout << w << endl;
}