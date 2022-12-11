#include<bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int a[3],ans;
	cin>>a[0]>>a[1]>>a[2];
	sort(a,a+3);
	ans=a[0]+a[1]-1-a[2];
	if(ans>=0) cout<<0;
	else cout<<-ans;
	return 0;
}