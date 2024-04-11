//CF 1023A
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
string s,t;
int n,m;
int main()
{
	int i,x;
	cin>>n>>m>>s>>t;
	if(n-1>m){
		cout<<"NO";
		return 0;
	}
	x=-1;
	for(i=0;i<n;i=i+1)
		if(s[i]=='*')
			x=i;
	if(x==-1){
		if(s==t)
			cout<<"YES";
		else
			cout<<"NO";
		return 0;
	}
	for(i=0;i<x;i=i+1)
		if(s[i]!=t[i]){
			cout<<"NO";
			return 0;
		}
	for(i=1;n-i>x;i=i+1)
		if(s[n-i]!=t[m-i]){
			cout<<"NO";
			return 0;
		}
	cout<<"YES";
	return 0;
	return 0;
}