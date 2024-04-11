#include<iostream>
#include<algorithm>
using namespace std;
string a,s;
int main()
{
	cin>>a>>s;
	sort(s.rbegin(),s.rend());
	for(int i=0,j=0;i<a.size();i++)
		if(j<s.size()&&s[j]>a[i])
			a[i]=s[j++];
	cout<<a<<endl;
}