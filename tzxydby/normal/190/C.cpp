#include<bits/stdc++.h>
using namespace std;
string s,z;
int t;
void f()
{
	if(cin>>s)
	{
		z+=s;
		if(s=="pair")
		{
			z+="<";
			f();
			z+=",";
			f();
			z+=">";
		}
	}
	else
		t=1;
}
int main()
{
	cin>>s;
	f();
	if(t||cin>>s)
		puts("Error occurred");
	else
		puts(z.c_str());
	return 0;
}
//