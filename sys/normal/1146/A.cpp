#include <bits/stdc++.h>
using namespace std;
string str;
int cnt;
int main()
{
	cin>>str;
	int siz=str.size();
	for(int i=0;i<siz;i++)
		if(str[i]=='a') cnt++;
	printf("%d",min(siz,2*cnt-1));
	return 0;
}