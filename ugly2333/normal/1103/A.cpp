//CF1103A
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
	int i,x,y;
	cin>>s;
	n=s.length();
	x=1,y=1;
	for(i=0;i<n;i=i+1){
		if(s[i]=='0'){
			cout<<x<<' '<<1<<endl;
			x^=2;
		}
		else{
			cout<<y<<' '<<2<<endl;
			y=y%4+1;
		}
	}
	return 0;
}