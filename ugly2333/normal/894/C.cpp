//CF 894C
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
int n,m,a[4444];
int main()
{
	int i,p,x;
	cin>>n>>p;
	m=0;
	a[++m]=p;
	for(i=2;i<=n;i=i+1){
		cin>>x;
		if(x%p){
			cout<<-1<<endl;
			return 0;
		}
		a[++m]=x;
		a[++m]=p;
	}
	cout<<m<<endl;
	for(i=1;i<=m;i=i+1)
		cout<<a[i]<<' ';
	cout<<endl;
	return 0;
}