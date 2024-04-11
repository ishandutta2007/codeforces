#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
	string s;
	cin>>s;
	int n=s.size();
	int a=0;
	for(int i=0;i<n;i++) a+=s[i]=='a';
	printf("%i\n",min(n,a*2-1));
	return 0;
}