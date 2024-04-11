//CF1081E
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
int n;
LL a[N];
int main()
{
	int i,j,k,x,y,t,o;
	scanf("%d",&n);
	for(i=2;i<=n;i=i+2)
		scanf("%d",&x),a[i]=x;
	k=0;
	for(i=2;i<=n;i=i+2){
		t=1e9;
		for(j=1;j*j<=a[i];j=j+1){
			if(a[i]%j||((a[i]/j)^j)&1)
				continue;
			x=(a[i]/j+j)/2;
			y=(a[i]/j-j)/2;
			if(k<y&&x<t)
				t=x,o=y;
		}
		if(t>=1e9){
			cout<<"No";
			return 0;
		}
		a[i-1]=(LL)o*o-(LL)k*k;
		k=t;
	}
	cout<<"Yes\n";
	for(i=1;i<=n;i=i+1)
		cout<<a[i]<<' ';
	return 0;
}