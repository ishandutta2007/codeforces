#include <stdio.h>
#include <map>
#include <cstring>
#include <iostream>
using namespace std;
map<string,int> mapa;
string s;
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=0;i<n;i++)
	{
		cin >> s;
		if(mapa[s]>0) printf("YES\n");
		else printf("NO\n");
		mapa[s]++;
	}
	return 0;
}