#include <bits/stdc++.h>
using namespace std;
int now,cnt[200005],vis[200005],b[200005],a[200005],qwq[200005];
vector <int> v1,v2;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	srand((unsigned long long)new char);
	while(T--)
	{
		int n,ans=0;
		cin >> n;
		for(int i=1;i<=n;i++) cnt[i]=0,b[i]=0,vis[i]=0;
		v1.clear(),v2.clear();
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
			if(cnt[a[i]]) v1.push_back(i);
			ans+=!cnt[a[i]]++;
		}
		for(int i=1;i<=n;i++)
			if(!cnt[i]) v2.push_back(i);
		cout << ans << "\n";
		if(ans==n)
		{
			for(int i=1;i<=n;i++)
				cout << a[i] << " ";
			cout << "\n";
			continue;
		}
		if(ans<n-1)
		{
			for(int i=1;i<=n;i++) qwq[i]=a[i];
			while(1)
			{
				int flag=0;
				random_shuffle(v1.begin(),v1.end());
				random_shuffle(v2.begin(),v2.end());
				for(int i=0;i<v1.size();i++)
				{
					if(v1[i]==v2[i])
					{
						flag=1;
						break;
					}
				}
				if(!flag) break;
			}
			for(int i=0;i<v1.size();i++) qwq[v1[i]]=v2[i];
			for(int i=1;i<=n;i++)
				cout << qwq[i] << " ";
			cout << "\n";
			continue;
		}
		if(ans==n-1)
		{
			int p=0;
			for(int i=1;i<=n;i++)
				if(!cnt[i]) p=i;
			int flag=0;
			for(int i=1;i<=n;i++)
			{
				if(cnt[a[i]]>1)
				{
					if(i==p)
						cout << a[i] << " ";
					else
					{
						if(!flag) cout << p << " ";
						else cout << a[i] << " ";
						flag=1;
					}
				}
				else cout << a[i] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}