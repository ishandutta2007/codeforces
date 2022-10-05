#include <bits/stdc++.h>
using namespace std;
int n,a[1005],b[1005],ans1,ans2;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i],ans1|=a[i];
	for(int i=1;i<=n;i++)	cin>>b[i],ans2|=b[i];
	cout<<ans1+ans2<<endl;
}