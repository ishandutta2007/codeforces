#include<bits/stdc++.h>

using namespace std;

int n,m,a[200],b[200],h[200][200];

int main()
{
	ios_base::sync_with_stdio(false);
	srand(time(0));
	cin>>n>>m;
	for (int i=0;i<n;++i) cin>>a[i];
	for (int i=0;i<m;++i) cin>>b[i];
	for (int i=0;i<n;++i) for (int j=0;j<m;++j) h[i][j]=rand();
	for (int i=0;i<n;++i)
	{
		int xo=0;
		for (int j=0;j<m;++j) xo^=h[i][j];
		h[i][0]^=xo^a[i];
	}
	for (int i=0;i<m;++i)
	{
		int xo=0;
		for (int j=0;j<n;++j) xo^=h[j][i];
		h[0][i]^=xo^b[i];
	}
	for (int i=0;i<n;++i)
	{
		int xo=0;
		for (int j=0;j<m;++j) xo^=h[i][j];
		if (xo!=a[i]) cout<<"NO\n",exit(0);
	}
	cout<<"YES\n";
	for (int i=0;i<n;++i) for (int j=0;j<m;++j) cout<<h[i][j]<<" \n"[j==m-1];
}