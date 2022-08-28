//CF 889A
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
int a[N],f[N];
int main()
{
	int n,i,x,ans;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i);
	ans=0;
	for(i=n;i>=1;i=i-1){
		if(!f[i]){
			ans++;
			x=i;
			while(x){
				f[x]=1;
				x=a[x];
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}