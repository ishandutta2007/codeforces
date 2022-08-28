//CF 903B
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
int ans,f[111111];
int main()
{
	int h1,a1,h2,a2,c1,i;
	cin>>h1>>a1>>c1>>h2>>a2;
	while(h2>0){
		if(h2<=a1){
			f[++ans]=1;
			break;
		}
		if(a2<h1){
			f[++ans]=1;
			h2-=a1;
		}
		else{
			f[++ans]=2;
			h1+=c1;
		}
		h1-=a2;
	}
	cout<<ans<<endl;
	for(i=1;i<=ans;i=i+1){
		if(f[i]==1)
			cout<<"STRIKE\n";
		else
			cout<<"HEAL\n";
	}
	return 0;
}