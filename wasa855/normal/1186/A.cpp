#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	int ans=0;
	while(isdigit(ch))
	{
		ans=ans*10+ch-48;
		ch=getchar();
	}
	return ans;
}
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	if(m<n||k<n) cout<<"No\n";
	else cout<<"Yes\n";
	return 0;
}