//CF 887C
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
int a[111];
bool f(int w,int x,int y,int z){
	return a[w]==a[x]&&a[x]==a[y]&&a[y]==a[z];
}
int main()
{
	int n,i,c;
	n=24;
	for(i=1;i<=n;i=i+1)
		cin>>a[i];
	c=0;
	if(f(1,2,3,4)&&f(9,10,11,12)&&f(5,6,19,20)&&f(13,14,7,8)&&f(17,18,23,24))
		c++;
	if(f(1,2,3,4)&&f(9,10,11,12)&&f(5,6,15,16)&&f(13,14,23,24)&&f(17,18,7,8))
		c++;
	if(f(5,6,7,8)&&f(21,22,23,24)&&f(3,4,18,20)&&f(17,19,11,12)&&f(9,10,13,15))
		c++;
	if(f(5,6,7,8)&&f(21,22,23,24)&&f(3,4,13,15)&&f(17,19,1,2)&&f(9,10,18,20))
		c++;
	if(f(13,14,15,16)&&f(17,18,19,20)&&f(1,3,6,8)&&f(5,7,10,12)&&f(9,11,21,23))
		c++;
	if(f(13,14,15,16)&&f(17,18,19,20)&&f(1,3,21,23)&&f(5,7,2,4)&&f(9,11,6,8))
		c++;
	if(c)
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}