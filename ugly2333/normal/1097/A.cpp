//CF1097A
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
int main()
{
	int i;
	cin>>s;
	for(i=1;i<=5;i=i+1){
		cin>>t;
		if(s[0]==t[0]||s[1]==t[1]){
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
	return 0;
}