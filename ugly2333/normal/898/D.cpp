//CF 898D
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
int n,m,k,a[N];
int ans,p[N];
int main()
{
	int i;
	scanf("%d%d%d",&n,&m,&k);
	k--;
	if(!k){
		cout<<n<<endl;
		return 0;
	}
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	ans=0;
	for(i=1;i<=n;i=i+1){
		if(ans<k||p[ans-k+1]+m<=a[i])
			p[++ans]=a[i];
	}
	cout<<n-ans<<endl;
	return 0;
}