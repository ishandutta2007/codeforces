//CF 853D
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
const int N = 300333;
const int inf = 1<<30;
int a[N];
int main()
{
	int n,i,j,x,y,s;
	scanf("%d",&n);
	s=0;
	j=0;
	for(i=1;i<=n;i=i+1){
		scanf("%d",a+i);
		if(a[i]==1000)
			j=i;
		a[i]/=100;
		s+=a[i];
	}
	if(n==1){
		cout<<a[1]*100<<endl;
		return 0;
	}
	x=s/11;
	x*=10;
	y=s-x;
	s*=100;
	if((j<=1&&y%2)||y<a[n]){
		cout<<100+s-x*10<<endl;
		return 0;
	}
	cout<<s-x*10<<endl;
	return 0;
}