#include<bits/stdc++.h>
using namespace std;
long m,n,ta,tb,k,A[200001],B[200001],i,j,b,r=-1,bou;
main()
{
	for(cin>>n>>m>>ta>>tb>>k;i<n;i++)cin>>A[i],A[i]+=ta;
	for(i=0;i<m;i++)cin>>B[i];
	if(n<=k||m<=k)return cout<<-1,0;
	for(i=0;i<=k;i++)
	{
		b=A[i];
		if(B[m-(k-i)-1]<b)return cout<<-1,0;
		bou=lower_bound(B,B+m,b)-B;
		r=max(r,B[bou+k-i]+tb);
	} 
	cout<<r; 
}