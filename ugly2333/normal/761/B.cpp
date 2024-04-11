//CF 761A
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
int a[105],b[105];
int main()
{
	int n,l,i,j,f;
	cin>>n>>l;
	for(i=1;i<=n;i=i+1)
		cin>>a[i];
	for(i=1;i<=n;i=i+1)
		cin>>b[i];
	sort(a+1,a+n+1);
	for(i=0;i<l;i=i+1)
	{
		f=1;
		sort(b+1,b+n+1);
		for(j=1;j<=n;j=j+1)
			if(a[j]!=b[j])
				f=0;
		/*cout<<i<<endl;
		for(j=1;j<=n;j=j+1)	
			cout<<a[j]<<' '<<b[j]<<endl;
		cout<<endl;*/
		if(f==1){
			cout<<"YES";
			return 0;
		}
		for(j=1;j<=n;j=j+1)
			b[j]=(b[j]+1)%l;
	}
	cout<<"NO";
	return 0;
}