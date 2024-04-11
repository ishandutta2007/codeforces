//CF1396A
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
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i);
	if(n==1){
		cout<<1<<' '<<1<<endl<<0<<endl;
		cout<<1<<' '<<1<<endl<<0<<endl;
		cout<<1<<' '<<1<<endl<<-a[1]<<endl;
		return 0;
	}
	cout<<1<<' '<<n<<endl;
	for(i=1;i<=n-1;i=i+1)
		cout<<(LL)-a[i]*n<<' ';
	cout<<0<<' ';
	cout<<endl;
	cout<<1<<' '<<n-1<<endl;
	for(i=1;i<=n-1;i=i+1)
		cout<<(LL)a[i]*(n-1)<<' ';
	cout<<endl;
	cout<<n<<' '<<n<<endl;
	cout<<-a[n]<<' ';
	cout<<endl;
	return 0;
}