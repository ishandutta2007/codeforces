//CF 995B
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
const int N = 222;
int n,a[N];
int ans;
int main()
{
	int i,j;
	cin>>n;
	n=n+n;
	for(i=1;i<=n;i=i+1)
		cin>>a[i];
	for(i=1;i<=n;i=i+2){
		for(j=i+1;j<=n;j=j+1)
			if(a[j]==a[i])
				break;
		while(j>i+1){
			swap(a[j],a[j-1]);
			j--;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}