//CF 1025C
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
string s;
int n;
int main()
{
	int i,j,t;
	cin>>s;
	n=s.length();
	s=s+s;
	j=1;
	t=1;
	for(i=1;i<n+n;i=i+1){
		if(s[i]!=s[i-1])
			j++;
		else
			j=1;
		t=max(t,j);
	}
	cout<<min(t,n);
	return 0;
}