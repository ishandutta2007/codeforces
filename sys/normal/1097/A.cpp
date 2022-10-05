#include <bits/stdc++.h>
using namespace std;
const int Maxn=100;
int ct;
string str[Maxn],t;
int main()
{
	cin>>t;
	ct=5;
	for(int i=1;i<=ct;i++)
		cin>>str[i];
	for(int i=1;i<=ct;i++)
	{
		if(t[0]==str[i][0]||t[1]==str[i][1])
		{
			printf("Yes");
			return 0;
		}
	}
	printf("No");
	return 0;
}