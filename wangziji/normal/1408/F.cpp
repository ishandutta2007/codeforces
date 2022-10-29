#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> v[15005];
vector <pair<int,int> > ans;
inline void merge(int x,int y)
{
//	cout << x << " " << y << " " << v[x].size() << " " << v[y].size() << "\n";
	if(v[x].size()!=v[y].size()) return ;
	for(int i=0;i<v[x].size();i++)
		ans.push_back({v[x][i],v[y][i]});
	for(auto t:v[y]) v[x].push_back(t);
	v[y].clear();
}
inline void gao(int x,int y)//x,y->x-y,2y
{
	int qwq=v[y].size();
	for(int i=0;i<qwq;i++)
		ans.push_back({v[x][i],v[y][i]}),v[y].push_back(v[x][i]);
	vector <int> t;
	for(int i=qwq;i<v[x].size();i++) t.push_back(v[x][i]);
	swap(v[x],t);
}
inline bool cmp(vector <int> x,vector <int> y)
{
	return x.size()>y.size();
}
int main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		v[i].push_back(i);
	for(int i=0;i<=20;i++)
	{
		for(int j=1;j<=n-(1<<i);j+=(1<<i+1))
		{
			merge(j,j+(1<<i));
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(v[i].size()) v[++cnt]=v[i];
	sort(v+1,v+cnt+1,cmp);
	for(int i=cnt;i>=3;i--)
	{
		while(v[i].size()!=v[i-1].size())
			gao(1,i);
		merge(i-1,i);
	}
	cout << ans.size() << "\n";
	for(auto x:ans) cout << x.first << " " << x.second << "\n"; 
	return 0;
}