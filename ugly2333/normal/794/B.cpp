//CF 794B
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
int main()
{
	int n,h,i;
	cin>>n>>h;
	for(i=1;i<n;i=i+1)
		printf("%.9f ",sqrt((double)h*h/n*i));
	cout<<endl;
	return 0;
}