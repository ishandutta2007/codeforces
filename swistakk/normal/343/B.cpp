#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#define uint long long int
#define MP make_pair
#define PB push_back

using namespace std;

const int N = 1005 * 1005;

vector<char> pluss;
char cab[N];
int main()
{
	// nie zapomnij o ll
	ios_base::sync_with_stdio(0);
	scanf("%s", cab);
	
	for (int i = 0; cab[i]; i++) {
		if (pluss.empty()) {
			pluss.PB(cab[i]);
			continue;
		}
		if (cab[i] == pluss.back()) {
			pluss.pop_back();
		}
		else
		{
			pluss.push_back(cab[i]);
		}
	}
	if (pluss.empty()) {
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}
	
	// nie zapomnij o ll
	return 0;
}