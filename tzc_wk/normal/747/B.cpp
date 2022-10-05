#include <iostream>
#include <string>
using namespace std;
int a,c,t,g;
int min(){return min(min(a,c),min(g,t));}
int main()
{
	int n;
	string s;
	cin>>n;
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='A')a++;
		else if(s[i]=='C')c++;
		else if(s[i]=='G')g++;
		else if(s[i]=='T')t++;
	}
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='?')
		{
			if(a==min()){s[i]='A';a++;}
			else if(c==min()){s[i]='C';c++;}
			else if(g==min()){s[i]='G';g++;}
			else{s[i]='T';t++;}
		}
	}
	if(a==c&&c==g&&g==t)
		cout<<s;
	else
		cout<<"===";
	return 0;
}//