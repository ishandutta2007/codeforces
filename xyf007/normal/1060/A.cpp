#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main()
{
	scanf("%d",&n);
	cin>>s;
	int sum=0;
	for(int i=0;i<n;i++)
	  if(s[i]=='8')
	    sum++;
	printf("%d",min(sum,n/11));
	return 0;
}