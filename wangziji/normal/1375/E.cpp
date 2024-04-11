#include <iostream>
#include <vector>
using namespace std;
int a[1005],vis[1005];
vector <pair<int,int> > v;
vector <int> t,x,y;
inline int gao(vector <int> s)
{
	for(int i=s.size()-1;i>=1;i--)
		v.push_back({s[0],s[i]});
}
int main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=1;i<=n;i++)
	{
		int mn=2e9;
		for(int j=1;j<=n;j++)
			if(!vis[j]) mn=min(mn,a[j]);
		x.clear(),y.clear();
		for(int j=1;j<=n;j++)
		{
			if(a[j]==mn) x.push_back(j),vis[j]=1;
			else if(vis[j]) y.push_back(j);
		}
		for(auto X:x)
		{
			t.clear();
			t.push_back(X);
			for(auto Y:y)
				if(Y>X) t.push_back(Y);
			gao(t);
		}
	}
	cout << v.size() << "\n";
	for(auto x:v) cout << x.first << " " << x.second << "\n";
	return 0;
}