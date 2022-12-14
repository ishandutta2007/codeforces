#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	string a,b,c;
	cin >> a >> b >> c;
	vector<char> ab,cc;
	for(int i=0;i<a.size();i++)
	{
		ab.push_back(a[i]);
	}
	for(int j=0;j<b.size();j++) ab.push_back(b[j]);
	for(int k=0;k<c.size();k++) cc.push_back(c[k]);
	sort(ab.begin(),ab.end());
	sort(cc.begin(),cc.end());
	if(ab==cc) printf("YES\n");
	else printf("NO\n");
	return 0;
}