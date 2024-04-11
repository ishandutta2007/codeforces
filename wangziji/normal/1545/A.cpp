#include <bits/stdc++.h>
using namespace std;
int b[100005];
int cnt[100005][2];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=1;i<=n;i++)
		{
			cin >> b[i];
			if(i&1) ++cnt[b[i]][1];
			else ++cnt[b[i]][0];
		}
		sort(b+1,b+n+1);
		int flag=1;
		for(int i=1;i<=n;i++)
		{
			if(--cnt[b[i]][i&1]<0) flag=0;
		}
		if(flag) puts("YES");
		else cout << "NO\n";
		memset(cnt,0,sizeof cnt);
	}
	return 0;
}