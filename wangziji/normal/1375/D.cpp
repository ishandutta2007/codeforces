#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int a[1005],vis[1005],n;
inline int mex()
{
	memset(vis,0,sizeof vis);
	for(int i=1;i<=n;i++)
		vis[a[i]]=1;
	for(int i=0;i<=n;i++)
		if(!vis[i]) return i;
}
vector <int> v;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		v.clear();
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		while(mex()<n) v.push_back(mex()+1),a[mex()+1]=mex();
		for(int i=1;i<=n;i++)
		{
			if(a[i]==i-1) continue;
			if(mex()==i-1)
			{
				v.push_back(i);
				a[i]=mex();
				continue;
			}
			for(int j=i+1;j<=n;j++)
				if(a[j]==i-1) a[j]=mex(),v.push_back(j);
			v.push_back(i);
			a[i]=mex();
		}
		if(v.size()>n+n) return v.size()-n-n;
		cout << v.size() << "\n";
		for(auto x:v) cout << x << " ";
		puts("");
	}
	return 0;
}