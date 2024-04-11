//CF 855A
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
char c[111][111];
bool ok(int x,int y){
	int i;
	for(i=0;i<101;i=i+1)
		if(c[x][i]!=c[y][i])
			return 0;
	return 1;
}
int main()
{
	int n,i,j;
	cin>>n;
	for(i=1;i<=n;i=i+1){
		cin>>c[i];
		for(j=1;j<i;j=j+1)
			if(ok(i,j)){
				cout<<"YES\n";
				break;
			}
		if(j==i)
			cout<<"NO\n";
	}
	return 0;
}