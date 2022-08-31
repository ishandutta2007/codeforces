//CF 901A
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
const int N = 222222;
int n,a[N],m,ans1[N],ans2[N];
int main()
{
	int i,j,f;
	scanf("%d",&n);
	m=0,f=0;
	for(i=0;i<=n;i=i+1){
		scanf("%d",a+i);
		for(j=1;j<=a[i];j=j+1){
			ans1[m+j]=m;
			ans2[m+j]=m;
		}
		if(i&&!f&&a[i-1]>1&&a[i]>1){
			ans2[m+1]=m-1;
			f=1;
		}
		m+=a[i];
	}
	if(f){
		cout<<"ambiguous\n";
		for(i=1;i<=m;i=i+1)
			cout<<ans1[i]<<' ';
		cout<<endl;
		for(i=1;i<=m;i=i+1)
			cout<<ans2[i]<<' ';
		cout<<endl;
	}
	else
		cout<<"perfect\n";
	return 0;
}