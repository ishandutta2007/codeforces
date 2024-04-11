#include <bits/stdc++.h>
using namespace std;
const int N=100050;
char s[N];
int main()
{
	vector<char> v;
	int n,i;
	scanf("%i",&n);
	scanf("%s",s+1);
	for(i=1;i<=n;i++) v.push_back(s[i]);
	sort(v.begin(),v.end());
	for(char t:v) printf("%c",t);
	return 0;
}