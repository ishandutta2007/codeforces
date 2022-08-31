//CF 930B
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
typedef double DB;
int a[33][5555][33];
string s;
int main()
{
	int n,i,j,l,x,y,ans=0;
	cin>>s;
	n=s.length();
	s=s+s;
	for(l=1;l<n;l=l+1){
		for(i=0;i<n;i=i+1){
			x=s[i]-'a',y=s[i+l]-'a';
			a[x][l][y]++;
		}
	}
	for(j=0;j<26;j=j+1){
		x=0;
		for(l=1;l<n;l=l+1){
			y=0;
			for(i=0;i<26;i=i+1)
				y+=(a[j][l][i]==1);
			x=max(x,y);
		}
		ans+=x;
	}
	printf("%.9lf",(DB)ans/n);
	return 0;
}