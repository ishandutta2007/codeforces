#include <iostream>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

map <string, int> repostLength;

int main()
{
	int n;
	scanf("%d", &n);
	repostLength["polycarp"] = 1;

	int ans = 1;
	for (int i = 0; i < n; i++)
	{
		string name1, name2;
		string rep;
		cin >> name1 >> rep >> name2;
		for (char &c : name1) c = tolower(c);
		for (char &c : name2) c = tolower(c);
		repostLength[name1] = repostLength[name2] + 1;
		ans = max(ans, repostLength[name1]);
	}
	printf("%d", ans);

	return 0;
}