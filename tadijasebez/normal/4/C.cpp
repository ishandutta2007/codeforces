#include <stdio.h>
#include <map>
#include <iostream>
#include <cstring>
using namespace std;
map<string,int> cnt;
int main()
{
	int n;
	string s;
	scanf("%i",&n);
	while(n --> 0)
	{
		cin >> s;
		cnt[s]++;
		if(cnt[s]==1) printf("OK\n");
		else cout << s << cnt[s]-1 << "\n";
	}
	return 0;
}