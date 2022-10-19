#include <bits/stdc++.h>
using namespace std;
string pro(int n)
{
	switch(n)
	{
		case 0:return "0/1";
		case 1:return "1/6";
		case 2:return "1/3";
		case 3:return "1/2";
		case 4:return "2/3";
		case 5:return "5/6";
		case 6:return "1/1";
	}
}
int main()
{
	int y,w;
	cin>>y>>w;
	cout<<pro(7-max(y,w));
	return 0;
}