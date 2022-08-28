//CF 839B
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
int a[111];
int main()
{
	int n,k,i,x,s4,s2,s1;
	cin>>n>>k;
	s4=n;
	s2=2*n;
	s1=0;
	for(i=1;i<=k;i=i+1)
		cin>>a[i];
	for(i=1;i<=k;i=i+1){
		if(s4&&a[i]>=4){
			x=min(s4,a[i]/4);
			s4-=x;
			a[i]-=4*x;
		}
	}
	if(s4){
		s2+=s4;
		s1+=s4;
		s4=0;
	}
	for(i=1;i<=k;i=i+1){
		if(s2&&a[i]>=2){
			x=min(s2,a[i]/2);
			s2-=x;
			a[i]-=2*x;
		}
	}
	if(s2){
		s1+=s2;
		s2=0;
	}
	for(i=1;i<=k;i=i+1){
		if(s1&&a[i]>=1){
			x=min(s1,a[i]/1);
			s1-=x;
			a[i]-=1*x;
		}
	}
	for(i=1;i<=k;i=i+1)
		if(a[i]){
			cout<<"NO\n";
			return 0;
		}
	cout<<"YES\n";
	return 0;
}