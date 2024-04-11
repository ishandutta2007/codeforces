//CF 843B
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
#include<ctime>
using namespace std;
typedef long long LL;
const int m = 999;
int n,st,x;
pair<int,int> a[1111];
int main()
{
	srand(time(0));
	cin>>n>>st>>x;
	int i,j,h,o,y,z;
	h=-1;
	o=st;
	for(i=1;i<=m;i=i+1){
		j=(rand()+rand()*rand())%n+1;
		cout<<"? "<<j<<endl;
		cin>>y>>z;
		if(y<=x&&y>h){
			h=y;
			o=j;
		}
	}
	while(o!=-1&&h<x){
		cout<<"? "<<o<<endl;
		cin>>h>>o;
	}
	if(h<x){
		cout<<"! -1\n";
		return 0;
	}
	cout<<"! "<<h<<endl;
	return 0;
}