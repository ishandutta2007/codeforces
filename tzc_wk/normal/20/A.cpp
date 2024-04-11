#include <string>
#include <iostream>
using namespace std;
string s;
int main()
{
	cin>>s;
	int j=s.length()-1;
	if(s[s.length()-1]=='/')
	{
		j=s.length()-1;
		while(s[j]=='/')
		{
			j--;
		}
	}
	if(j==-1)
	{
		cout<<"/"<<endl;
		return 0;
	}
	for(int i=0;i<=j;i++)
	{
		if(isalpha(s[i]))
		{
			cout<<s[i];
		}
		else if(s[i]=='/')
		{
			cout<<"/";
			while(s[i]=='/')
			{
				i++;
			}
			i--;
		}
	}
	cout<<endl;
	return 0;
}