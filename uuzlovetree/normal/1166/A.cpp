#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define maxn 105

using namespace std;

int n;
string s[maxn];
int c[30];
int ans;
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)cin>>s[i],c[s[i][0]-'a']++;
	for(int i=0;i<26;++i)
	{
		int x=c[i]/2;
		int y=c[i]-x;
		ans+=x*(x-1)/2+y*(y-1)/2;
	}
	cout<<ans<<endl;
	return 0; 
}