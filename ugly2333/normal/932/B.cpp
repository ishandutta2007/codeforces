//CF 932B
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
int a[1111111],s[1111111][11];
int calc(int x){
	if(x<10)
		return x;
	int y=1;
	while(x){
		if(x%10)
			y*=x%10;
		x/=10;
	}
	return a[y];
}
int main()
{
	int n=1000000,i,j,k;
	for(i=1;i<=n;i=i+1){
		a[i]=calc(i);
		for(j=1;j<=9;j=j+1)
			s[i][j]=s[i-1][j];
		s[i][a[i]]++;
	}
	cin>>n;
	while(n--){
		cin>>i>>j>>k;
		cout<<s[j][k]-s[i-1][k]<<endl;
	}
	return 0;
}