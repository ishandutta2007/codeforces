//CF1010B
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 111;
int qu(int x){
	cout<<x<<endl;
	cin>>x;
	if(!x)
		exit(0);
	return x;
}
int n,a[N];
int main()
{
	int i,j=0,l=1,r;
	cin>>r>>n;
	for(i=1;i<=n;i=i+1)
		a[i]=qu(1);
	while(l<=r){
		if(j>=n)
			j=0;
		i=l+r>>1;
		if(qu(i)==a[++j])
			l=i+1;
		else
			r=i-1;
	}
	return 0;
}