//CF 798A
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
char c[100];
int main()
{
	int i,j,n,s;
	cin>>c;
	n=strlen(c);
	s=0;
	for(i=0,j=n-1;i<j;i=i+1,j=j-1)
		if(c[i]!=c[j])
			s++;
	if(s==1||(s==0&&n%2==1))
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}