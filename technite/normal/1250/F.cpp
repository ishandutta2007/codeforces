#include<iostream>
#include<string>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s,a="h",b="e",c="i",d="d";
	cin>>s;
	int i,f,j;
	f=s.find(a,0);
	
	if(f!=string::npos)
	{
		j=f;
		f=s.find(b,j);
		if(f!=string::npos)
		{
			j=f;
			f=s.find(c,j);
			if(f!=string::npos)
			{
				j=f;
				f=s.find(d,j);
				if(f!=string::npos)
				{
					j=f;
					f=s.find(c,j);
					if(f!=string::npos)
					{
						printf("YES\n");
					}
					else
					{
						printf("NO\n");
					}
				}
				else
					{
						printf("NO\n");
					}
			}
			else
					{
						printf("NO\n");
					}
		}
		else
					{
						printf("NO\n");
					}


	}
	else
					{
						printf("NO\n");
					}
return 0;
}