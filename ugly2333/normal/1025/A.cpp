//CF 1025A
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
int n,a[33];
string s;
int main()
{
	int i;
	cin>>n>>s;
	if(n==1){
		cout<<"Yes";
		return 0;
	}
	for(i=0;i<n;i=i+1)
		a[s[i]-'a']++;
	for(i=0;i<26;i=i+1){
		if(a[i]>1){
			cout<<"Yes";
			return 0;
		}
	}
	cout<<"No";
	return 0;
}