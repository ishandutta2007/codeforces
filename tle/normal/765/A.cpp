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
int n;
string a,b;
int main()
{
	cin>>n>>a; int cnt=0;
	while(n--)
	{
		cin>>b;
		int s=b.find('-');
		string p=b.substr(0,s);
		if(p==a) cnt^=1;
		string p2=b.substr(s+2);
		if(p2==a) cnt^=1;
	}
	if(cnt) puts("contest");
	else puts("home");
}