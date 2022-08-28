//CF 830C
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
int n;
LL a[111],k;
bool ok(LL h)
{
	int i;
	LL r;
	r=0;
	for(i=1;i<=n;i=i+1){
		if(a[i]%h)
			r+=(LL)h-a[i]%h;
	}
	return (r<=k);
}
int main()
{
	int i,q;
	LL s;
	cin>>n>>k;
	s=k;
	for(i=1;i<=n;i=i+1){
		cin>>a[i];
		s+=a[i];
	}
	q=1+(int)sqrt((double)s);
	for(i=1;i<=q;i=i+1){
		if(ok(s/(LL)i)){
			cout<<s/(LL)i<<endl;
			return 0;
		}
	}
	for(i=q;i>=1;i=i-1){
		if(ok(i)){
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<0<<endl;
	return 0;
}