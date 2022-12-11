#include <iostream>
#include <string>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	string ans[] = {"Washington", "Adams", "Jefferson", "Madison", "Monroe", "Adams", "Jackson", 
		"Van Buren", "Harrison", "Tyler", "Polk", "Taylor", "Fillmore", "Pierce", "Buchanan", 
		"Lincoln", "Johnson", "Grant", "Hayes", "Garfield", "Arthur", "Cleveland", "Harrison", 
		"Cleveland", "McKinley", "Roosevelt", "Taft", "Wilson", "Harding", "Coolidge", 
		"Hoover", "Roosevelt", "Truman", "Eisenhower", "Kennedy", "Johnson", "Nixon", "Ford", 
		"Carter", "Reagan"};
	int n;
	cin >> n;
	cout << ans[n - 1];

	return 0;
}