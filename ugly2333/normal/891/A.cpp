//CF 891A
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
const int N = 2222;
int a[N];
int gcd(int x,int y){
	if(x<y)
		swap(x,y);
	int r;
	r=x%y;
	while(r){
		x=y;
		y=r;
		r=x%y;
	}
	 return y;
}
int main()
{
	int n,i,j,x,ans;
	cin>>n;
	x=0;
	for(i=1;i<=n;i=i+1){
		cin>>a[i];
		if(a[i]==1)
			x++;
	}
	if(x){
		cout<<n-x<<endl;
		return 0;
	}
	ans=n+1;
	for(i=1;i<=n;i=i+1){
		x=a[i];
		j=i;
		while(x>1&&j<n){
			j++;
			x=gcd(x,a[j]);
		}
		if(x==1)
			ans=min(ans,j-i);
	}
	if(ans==n+1)
		ans=-1;
	else
		ans+=n-1;
	cout<<ans<<endl;
	return 0;
}
//2 1 1