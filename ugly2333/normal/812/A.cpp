// CF 812A
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
int a[4][4];
int main()
{
	int i,j,f;
	for(i=0;i<4;i=i+1)
		for(j=0;j<4;j=j+1)
			cin>>a[i][j];
	f=0;
	if(a[0][3]){
		if(a[0][0]||a[0][1]||a[0][2]||a[3][2]||a[2][1]||a[1][0])
			f=1;
	}
	if(a[1][3]){
		if(a[1][0]||a[1][1]||a[1][2]||a[0][2]||a[3][1]||a[2][0])
			f=1;
	}
	if(a[2][3]){
		if(a[2][0]||a[2][1]||a[2][2]||a[1][2]||a[0][1]||a[3][0])
			f=1;
	}
	if(a[3][3]){
		if(a[3][0]||a[3][1]||a[3][2]||a[2][2]||a[1][1]||a[0][0])
			f=1;
	}
	if(f)
		cout<<"YES\n";
	else
		cout<<"NO"<<endl;
	return 0;
}