//CF 845B
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
int a[11];
int main()
{
	int n,i,j,s,x,y,ans;
	char ch[11];
	cin>>ch;
	for(i=1;i<=6;i=i+1){
		a[i]=ch[i-1]-'0';
	}
	x=a[1]+a[2]+a[3];
	y=a[4]+a[5]+a[6];
	if(x>y){
		swap(a[1],a[4]);
		swap(a[2],a[5]);
		swap(a[3],a[6]);
		swap(x,y);
	}
	ans=0;
	while(x<y){
		ans++;
		sort(a+1,a+4);
		sort(a+4,a+7);
		if(9-a[1]>=a[6]-0)
			a[1]=9;
		else
			a[6]=0;
		x=a[1]+a[2]+a[3];
		y=a[4]+a[5]+a[6];
	}
	cout<<ans<<endl;
	return 0;
}