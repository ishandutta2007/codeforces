#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() 
{
	int n;
	cin >> n;
	
	string str;
	
	cin >> str;
	
	char colors[3] = {'B', 'G', 'R'};
	
	int permutation[6] = {0};
	
	int num = -1;
	do {
		++num;
		for (int i = 0; i < n; ++i) if (str[i] != colors[i % 3]) ++permutation[num];
	} while (next_permutation(colors, colors + 3));
	
	int max_per = n, ind = 0;
	for (int i = 0; i < 6; ++i) {
		if (max_per > permutation[i]) {
			max_per = permutation[i];
			ind = i;
		}
	}
	
	cout << permutation[ind] << '\n';
	
	while (ind) {
		next_permutation(colors, colors + 3);
		--ind;
	}
	
	for (int i = 0; i < n; ++i) cout << colors[i % 3];
	cout << '\n';
	
	return 0;
}