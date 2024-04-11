#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n];
	int p1=0,p2=0,p3=0,p4=0,p5=0,p6=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==4) p1++;
		if(a[i]==8&&p2<p1) p2++;
		if(a[i]==15&&p3<p2) p3++;
		if(a[i]==16&&p4<p3) p4++;
		if(a[i]==23&&p5<p4) p5++;
		if(a[i]==42&&p6<p5) p6++;
	}
	int ans=0;
	ans=n-p6*6;
	cout<<ans<<endl;
}