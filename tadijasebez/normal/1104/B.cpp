#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,i;
	string s;
	stack<char> st;
	cin>>s;n=s.size();
	int ans=0;
	for(i=0;i<n;i++)
	{
		if(st.size() && st.top()==s[i]) st.pop(),ans^=1;
		else st.push(s[i]);
	}
	printf("%s\n",ans?"Yes":"No");
	return 0;
}