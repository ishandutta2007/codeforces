//CF 830A
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
int n,k,p,a[1111],b[2222];
pair<int,int> s[2222];
int ab(int x){
	if(x>0)
		return x;
	return -x;
}
bool ok(int m)
{
	int i,t,j;
	j=0;
	for(i=1;i<=k;i=i+1){
		t=m-ab(p-b[i]);
		if(t>=0){
			j++;
			s[j]=make_pair(b[i]-t,b[i]+t);
		}
	}
	sort(s+1,s+j+1);
	i=1;
	for(t=1;t<=j&&i<=n;t=t+1){
		if(s[t].first<=a[i]&&a[i]<=s[t].second)
			i++;
	}
	//cout<<m<<' '<<i<<n<<endl;
	return (i>n);
}
int main()
{
	int i,l,r,m;
	cin>>n>>k>>p;
	for(i=1;i<=n;i=i+1)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(i=1;i<=k;i=i+1)
		cin>>b[i];
	l=0;
	r=2000*1000*1000+1000;
	while(l<r){
		m=((LL)l+r)/2;
		if(ok(m))
			r=m;
		else
			l=m+1;
	}
	cout<<l<<endl;
	return 0;
}