//
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
typedef long long LL;
int main()
{
	int i;
	char a[111],b[111];
	cin>>a>>b;
	cout<<a[0];
	for(i=1;a[i]&&a[i]<b[0];i=i+1)
		cout<<a[i];
	cout<<b[0]<<endl;
	return 0;
}