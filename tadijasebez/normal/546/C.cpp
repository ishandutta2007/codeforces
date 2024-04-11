#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<int> id,f,s;
	int n,x;
	scanf("%i",&n);
	scanf("%i",&x);f.resize(x);for(int &i:f) scanf("%i",&i),id.push_back(i);
	scanf("%i",&x);s.resize(x);for(int &i:s) scanf("%i",&i),id.push_back(i);
	sort(id.begin(),id.end());id.resize(unique(id.begin(),id.end())-id.begin());
	for(int &i:f) i=lower_bound(id.begin(),id.end(),i)-id.begin();
	for(int &i:s) i=lower_bound(id.begin(),id.end(),i)-id.begin();
	string a,b;
	for(int i:f) a=(char)('0'+i)+a;
	for(int i:s) b=(char)('0'+i)+b;
	set<pair<string,string> > st;
	while(a.size() && b.size() && !st.count({a,b}))
	{
		st.insert({a,b});
		char o=a.back(),p=b.back();
		a=a.substr(0,a.size()-1);
		b=b.substr(0,b.size()-1);
		if(o>p) a=o+(p+a);
		else b=p+(o+b);
	}
	if(a.size() && b.size()) return 0*printf("-1\n");
	printf("%i %i\n",st.size(),a.empty()?2:1);
	return 0;
}