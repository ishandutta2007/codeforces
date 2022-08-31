#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <limits>
#include <set>
#include <map>
using namespace std;
int n,zs=0,op=0;
string sb,s;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		int sl=s.length();
		if(s[0]==48) {cout<<0;return 0;}
		bool ok=s[0]=='1';
		for(int j=1;j<sl;j++) ok&=(s[j]=='0');
		if(!ok) sb=s, op=1;
		else zs+=sl-1;
	}
	if(!op) putchar(49); else cout<<sb;
	for(int i=1;i<=zs;i++) putchar(48);
}