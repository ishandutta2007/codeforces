#include <bits/stdc++.h>
#define int long long
using namespace std;
string s[1000005];
int qwq[1000005];
signed main(int argc, char** argv) {
	ios::sync_with_stdio(false);cin.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> s[i];
		s[i]=' '+s[i];
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<m;j++)
		{
			if(s[i][j]=='X'&&s[i-1][j+1]=='X')
				qwq[j]=1;
		}
	}
	for(int j=1;j<=m;j++) qwq[j]+=qwq[j-1];
	int q;
	cin >> q;
	while(q--)
	{
		int l,r;
		cin >> l >> r;
		if(qwq[r-1]-qwq[l-1]) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}