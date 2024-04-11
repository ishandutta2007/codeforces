#include <bits/stdc++.h>
using namespace std;
bool def(string s,string t)
{
	if(s=="rock"&&t=="scissors")	return true;
	else if(s=="scissors"&&t=="paper")	return true;
	else if(s=="paper"&&t=="rock")	return true;
}
char winner(string s,string t,string q)
{
	if(t==q&&def(s,t))	return 'F';
	if(s==q&&def(t,q))	return 'M';
	if(s==t&&def(q,s))	return 'S';
	return '?';
}
string ges[3];
int main()
{
	for(int i=0;i<3;i++)
	{
		cin>>ges[i];
	}
	cout<<winner(ges[0],ges[1],ges[2]);
	return 0;
}