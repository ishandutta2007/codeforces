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
int a[1000005];
int main()
{
	int k,i,j;
	long long n,ans;
	cin>>n>>k;
	j=0;
	for(i=1;(long long)i*i<=n;i=i+1)
	{
		if(n%i==0){
			j=j+1;
			a[j]=i;
		}
	}
	if(k<=j){
		cout<<a[k]<<endl;
	}
	else{
		if((long long)a[j]*a[j]==n){
			if(k>=2*j)
				cout<<-1<<endl;
			else
				cout<<(long long)n/((long long)a[2*j-k]);
		}
		else{
			if(k>2*j)
				cout<<-1<<endl;
			else
				cout<<(long long)n/((long long)a[2*j-k+1]);
		}
	}
	return 0;
}