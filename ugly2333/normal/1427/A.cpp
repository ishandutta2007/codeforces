//CF1427A
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
const int N = 55;
int n,a[N];
int main()
{
	int T,i,s;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		s=0;
		for(i=1;i<=n;i=i+1)
			scanf("%d",a+i),s+=a[i];
		if(s==0){
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		sort(a+1,a+n+1);
		if(s>0)
			reverse(a+1,a+n+1);
		for(i=1;i<=n;i=i+1)
			cout<<a[i]<<' ';
		cout<<endl;
	}
	return 0;
}