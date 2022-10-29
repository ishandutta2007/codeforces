#include <bits/stdc++.h>
#define int long long
using namespace std;
vector <int> v;
int f[5005];
signed main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n,k,x;
		cin >> n >> k >> x;
		v.clear();
		for(int i=1;i<=n;i++)
		{
			char c;
			cin >> c;
			if(c=='a') v.push_back(-1);
			else
			{
				if(v.empty()||v.back()==-1) v.push_back(k);
				else v.back()+=k;
			}
		}
		f[v.size()]=1;
		for(int i=(int)v.size()-1;i>=0;i--)
		{
			if(v[i]==-1)
			{
				f[i]=f[i+1];
				continue;
			}
			f[i]=f[i+1]*(v[i]+1);
			if((double)f[i+1]*(v[i]+1)>2e18) f[i]=2e18;
		}
		for(int i=0;i<v.size();i++)
		{
			if(v[i]==-1)
			{
				cout << 'a';
				continue;
			}
			while(x>f[i+1])
			{
				cout << 'b';
				x-=f[i+1];
			}
		}
		cout << "\n";
	}
	return 0;
}