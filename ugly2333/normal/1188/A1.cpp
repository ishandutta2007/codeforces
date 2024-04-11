//CF1188A1
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
const int N = 111111;
int n,a[N];
int main()
{
	int i,x,y;
	scanf("%d",&n);
	for(i=1;i<n;i=i+1){
		scanf("%d%d",&x,&y);
		a[x]++,a[y]++;
	}
	for(i=1;i<=n;i=i+1)
		if(a[i]==2){
			cout<<"NO";
			return 0;
		}
	cout<<"YES";
	return 0;
}