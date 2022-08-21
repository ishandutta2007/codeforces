#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef double ld;
#define pb push_back
int app[233];
int main()
{
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(!islower(s[i]))
		{
			puts("NO"); return 0;
		}
		if(!app[s[i]-'a'])
		app[s[i]-'a']=i+1;
	}
	for(int i=1;i<26;i++)
	{
		if(!app[i]) continue;
		if(app[i]<app[i-1]||(app[i]&&!app[i-1]))
		{
			puts("NO"); return 0;
		}
	}
	puts("YES");
}