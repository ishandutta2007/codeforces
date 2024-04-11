#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
    string s;int n;
    scanf("%i",&n);
    cin>>s;
    string t;
    int j=1;
    for(int i=0;i<s.size();i+=j,j++)
	{
		printf("%c",s[i]);
	}
	return 0;
}