#include<stdio.h>
#include<iostream>
using namespace std;
string s,z;
int t;
void F()
{
	if(cin>>s)
	{
		z+=s;
		if(s=="pair")
			z+="<",F(),z+=",",F(),z+=">";
	}
	else
		t=1;
}
int main()
{
	cin>>s;
	F();
	if(t||cin>>s)
		puts("Error occurred");
	else
		puts(z.c_str());
	return 0;
}