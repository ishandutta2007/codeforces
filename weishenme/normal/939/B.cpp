#include<bits/stdc++.h>
using namespace std;
__int64 ans3,ans2,n,x;
int k,ans1;
int main()
{
	cin>>n>>k>>x;
	ans1=1,ans2=n/x,ans3=n%x;
	for (int i=2;i<=k;i++)
	 {
	 	cin>>x;
	 	if (n%x<ans3)
	 	 {
	 	 	ans3=n%x;
	 	 	ans2=n/x;
	 	 	ans1=i;
	 	 }
	 } 
	cout<<ans1;
	putchar(' ');
	cout<<ans2;
}