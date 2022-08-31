//Cf 1023C
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
const int N = 222222;
string s;
int n,k,a[N],b[N];
vector<int> v;
int main()
{
	int i,x;
	cin>>n>>k>>s;
	for(i=0;i<n;i=i+1)
		if(s[i]=='(')
			v.push_back(i);
		else
			x=*v.rbegin(),a[i]=x,a[x]=i,v.pop_back();
	for(i=0;i<n&&n>k;i=i+1)
		if(a[i]>i)
			b[i]=1,b[a[i]]=1,k+=2;
	for(i=0;i<n;i=i+1)
		if(!b[i])
			cout<<s[i];
	return 0;
}