//CF 791C
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
void print(int x)
{
	if(x<=25)
		cout<<char(65+x);
	else
		cout<<char(65+x-25)<<'a';
	cout<<' ';
}
int a[100];
int main()
{
	int n,k,i;
	char c[10];
	
	cin>>n>>k;
	a[0]=0;
	for(i=1;i<=k-1;i=i+1){
		print(i);
		a[i]=i;
	}
	for(i=k;i<=n;i=i+1)
	{
		cin>>c;
		if(c[0]=='Y'){
			print(i);
			a[i]=i;
		}
		else{
			print(a[i-k+1]);
			a[i]=a[i-k+1];
		}
	}
	return 0;
}