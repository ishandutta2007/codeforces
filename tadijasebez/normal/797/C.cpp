#include <bits/stdc++.h>
using namespace std;
int main()
{
	stack<char> q;
	string s,ans;
	vector<int> last(26,-1);
	cin>>s;
	for(int i=0;i<s.size();i++) last[s[i]-'a']=i;
	int j=0;
	for(int i=0;i<s.size();i++)
	{
		while(last[j]<i) j++;
		while(q.size() && q.top()<=j+'a') ans+=q.top(),q.pop();
		if(s[i]==j+'a') ans+=s[i];
		else q.push(s[i]);
	}
	while(q.size()) ans+=q.top(),q.pop();
	cout<<ans<<"\n";
	return 0;
}