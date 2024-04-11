#include<bits/stdc++.h>
using namespace std;
int n,i=0,j=0;
int main()
{
	char str[1005];
	cin>>n>>str;
	while(str[i]=='.')
	i++;
	while(n>0 && str[n-1]=='.')
	str[n--]='L';
	while(str[j]!='L')
	j++;
	cout<<i+1<<" "<<j;
}