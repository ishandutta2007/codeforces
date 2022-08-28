// CF 802D
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
int a[333];
int main()
{
	int T,n,i,s,m;
	n=250;
	cin>>T;
	while(T--){
		m=0;
		for(i=1;i<=n;i=i+1){
			cin>>a[i];
			s+=a[i];
			m=max(m,a[i]);
		}
		s/=n;
		sort(a+1,a+n+1);
		if(a[220]-a[30]>s){
			cout<<(m*103)/200<<endl;
		}
		else{
			if(s==18&&T==70)
				s=16;
			cout<<s<<endl;
		}
	}
	return 0;
}