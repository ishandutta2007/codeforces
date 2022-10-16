#include<bits/stdc++.h>
using namespace std;
int k,n,a[200005],f[200005];
vector<int>ind,g;
int main()
{
	cin>>n;
	for(k=1;k<=n;k++)
	{
		cin>>a[k];
		f[a[k]]=1;
		if(a[k]==0) ind.push_back(k);
	}
	
	for(k=1;k<=n;k++)
	{
		if(f[k]==0){
			g.push_back(k);
		}
	}
	
	for(k=0;k<ind.size()-1;k++)
	{
		if(g[k]==ind[k] || g[k+1]==ind[k+1]) 
		{
			swap(g[k],g[k+1]);
		}
		a[ind[k]]=g[k];
	}
	a[ind[ind.size()-1]]=g[g.size()-1];
	for(k=1;k<=n;k++) cout<<a[k]<<" ";
}