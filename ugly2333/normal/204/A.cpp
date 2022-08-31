//CF 204A
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
bool ok(LL x)
{
	int t;
	t=x%10;
	while(x>=10){
		x/=(LL)10;
	}
	return (t==x);
}
int main()
{
	LL l,r,ans,i;
	cin>>l>>r;
	ans=0;
	while(l<=r&&ok(l)){
		l++;
		ans++;
	}
	while(l<=r&&ok(r)){
		r--;
		ans++;
	}
	if((LL)r-l<=100){
		for(i=l;i<=r;i=i+1)
			if(ok(i))
				ans++;
		cout<<ans<<endl;
		return 0;
	}
	while(l%10!=0){
		if(ok(l))
			ans++;
		l++;
	}
	while(r%10!=9){
		if(ok(r))
			ans++;
		r--;
	}
	ans+=(LL)(r-l+1)/10;
	cout<<ans<<endl;
	return 0;
}