#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	cin>>n;
	switch(n)
	{
		case 2:
		case 3:
		case 4:
		case 5:
		case 12:
		case 30:
		case 31:
		case 35:
		case 43:
		case 46:
		case 52:
		case 64:
		case 86:
			puts("YES");break;
		default:
			puts("NO");break;
	}
}