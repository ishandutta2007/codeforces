#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,m,q,a[N];
string s[N];
int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>s[i],s[i]=" "+s[i];
	for(int i=2;i<=n;i++)
		for(int j=2;j<=m;j++)
			if(s[i-1][j]=='X'&&s[i][j-1]=='X')
				a[j]++;
	for(int i=2;i<=m;i++)
		a[i]+=a[i-1];
	cin>>q;
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		cout<<(a[l]==a[r]?"YES":"NO")<<endl;
	}
	return 0;
}