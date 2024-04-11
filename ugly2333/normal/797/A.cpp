//CF 797A
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
int a[22];
int main()
{
	int n,k,i,x;
	cin>>n>>k;
	x=2;
	i=1;
	while(n!=1&&i<k&&x*x<=n)
	{
		if(n%x==0){
			a[i]=x;
			i++;
			n/=x;
		}
		else
			x=x+1;
	}
	if(i!=k)
		cout<<"-1"<<endl;
	else{
		for(i=1;i<k;i=i+1)
			cout<<a[i]<<' ';
		cout<<n<<endl;
	}
	return 0;
}