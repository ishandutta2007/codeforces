#include<bits/stdc++.h>
using namespace std;
stack<int>st;
int main()
{
	ios::sync_with_stdio(false);
	int n,k;
	string s;
	cin>>n>>k>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='(')
			st.push(1);
		if(s[i]==')')
		{
			st.pop();
			k+=2;
		}
		if(n==k)
		{
			for(int j=1;j<=(int)st.size();j++)
				cout<<"(";
			for(int j=i+1;j<n;j++)
				cout<<s[j];
			break; 
		}
	}
	return 0;
}