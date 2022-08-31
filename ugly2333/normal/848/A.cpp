//CF 848A
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
const int N = 1111;
const int n = 1005;
const int inf = 1<<30;
int f[N];
int main()
{
	int i,j,k,l;
	cin>>k;
	f[1]=0;
	for(i=2;i<=n;i=i+1){
		f[i]=inf;
		for(j=1;j<=i/2;j=j+1)
			f[i]=min(f[i],f[j]+f[i-j]+j*(i-j));
		//cout<<i<<' '<<f[i]<<endl;
	}
	if(!k){
		cout<<"a\n";
		return 0;
	}
	for(j=1;k&&j<=26;j=j+1){
		for(i=n;i>=2;i=i-1)
			if(f[i]<=k){
				break;
			}
		l=i;
		k-=f[i];
		for(i=1;i<=l;i=i+1)
			cout<<(char)(j+96);
	}
	return 0;
}