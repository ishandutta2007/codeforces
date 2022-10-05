#include <bits/stdc++.h>
using namespace std;
char s[256];
int main()
{
	gets(s);
	string type="none";
	for(int i=0;i<256;)
	{
		if(s[i]=='.')
		{
			if(type!="none")	cout<<" ";
			i=i+3;
			cout<<"...";
			type="dot";
		}
		else if(s[i]==',')
		{
			if(type=="comma")	
			{
				cout<<" ";
			}
			cout<<",";
			i++;
			type="comma";
		}
		else if(isdigit(s[i]))
		{
			if(type=="number"||type=="comma")	cout<<" ";
			for(;;)
			{
				if(!isdigit(s[i]))	break;
				cout<<s[i];
				i++; 
			}
			type="number";
		}
		else	i++;
	}
	return 0;
}