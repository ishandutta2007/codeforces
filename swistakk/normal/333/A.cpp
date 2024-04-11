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

int main()
{
	// nie zapomnij o ll
	ios_base::sync_with_stdio(0);
	uint n;
	uint res = 0;
	cin>>n;
	bool first = false;
	uint pot = 1;
	uint startn = n;
	while(n)
	{
		if ((n % 3)&& (!first))
		{
			first = true;
			res = startn / (3 * pot) + 1;
			break;
		}
		//else
		//{res += n % 3;}
		pot *= 3;
		n /= 3;
	}
	cout<<res<<endl;
	
	// nie zapomnij o ll
	return 0;
}