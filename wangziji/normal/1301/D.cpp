#include <iostream>
#include <vector>
using namespace std;
vector <pair<int,char> > v;
vector <pair<int,char> > ans;
int main(int argc, char** argv) {
	int n,m,k;
	cin >> n >> m >> k;
	if(k>4*n*m-2*n-2*m)
	{
		puts("NO");
		return 0;
	}
	for(int i=1;i<n;i++)
		v.push_back({m-1,'R'}),v.push_back({m-1,'L'}),v.push_back({1,'D'});
	v.push_back({m-1,'R'});
	for(int i=1;i<m;i++)
		v.push_back({n-1,'U'}),v.push_back({n-1,'D'}),v.push_back({1,'L'});
	v.push_back({n-1,'U'});
	puts("YES");
	for(auto i:v)
	{
		//cout << i.first << " " << i.second << "\n";
		if(!i.first) continue; 
		if(i.first>=k)
		{
			ans.push_back({k,i.second});
			break;
		}
		ans.push_back(i);
		k-=i.first;
	}
	cout << ans.size() << "\n";
	for(auto x:ans) cout << x.first << " " << x.second << "\n";
	return 0;
}