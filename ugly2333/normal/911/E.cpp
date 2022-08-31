//CF 911E
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
int n,k,a[N],f[N];
int sz,st[N];
int main()
{
	int i,x,y;
	scanf("%d%d",&n,&k);
	x=1,y=n;
	for(i=1;i<=n;i=i+1){
		if(i<=k)
			scanf("%d",a+i);
		else{
			if(sz)
				a[i]=st[sz]-1;
			else
				a[i]=y;//,cout<<a[i]<<endl;
		}
		f[a[i]]=1;
		if(sz&&st[sz]<a[i]){
			cout<<-1<<endl;
			return 0;
		}
		st[++sz]=a[i];
		while(f[x]){
			x++;
		}
		while(f[y]){
			y--;
		}
		while(sz&&st[sz]<=x){
			sz--;
		}
	}
	for(i=1;i<=n;i=i+1)
		cout<<a[i]<<' ';
	return 0;
}