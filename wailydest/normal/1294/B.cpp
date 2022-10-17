#include <iostream>
#include <cstring>
using namespace std;

int main() 
{
	int t, n;
	cin >> t;
	
	int packages[1000][2];
	
	char way[2001];
	
	bool ispossible;
	int currx, curry;
	int nextpack;
	while (t--) {
		strcpy(way, "");
		ispossible = true;
		currx = curry = 0;
		
		cin >> n;
		for (int i = 0; i < n; ++i) 
			cin >> packages[i][0] >> packages[i][1];
		
		while (n && ispossible) {
			nextpack = 0;
			for (int i = 0; i < n; ++i) 
				if (packages[nextpack][0] > packages[i][0]) nextpack = i;
			for (int i = 0; i < n; ++i) 
				if (packages[nextpack][1] > packages[i][1] && packages[nextpack][0] == packages[i][0]) nextpack = i;
			
			if (packages[nextpack][1] >= curry) {
				for (int i = currx; i < packages[nextpack][0]; ++i) strcat(way, "R");
				for (int i = curry; i < packages[nextpack][1]; ++i) strcat(way, "U");
				
				currx = packages[nextpack][0];
				curry = packages[nextpack][1];
				swap(packages[nextpack][0], packages[n - 1][0]);
				swap(packages[nextpack][1], packages[n - 1][1]);
				--n;
			}
			else ispossible = false;
		}
		
		if (ispossible) cout << "YES\n" << way << '\n';
		else cout << "NO\n";
	}
	return 0;
}