#include <iostream>
#include <vector>
using namespace std;
vector <pair<pair<int,int>,int> > ans;
inline void add(int u,int v,int w)
{
	ans.push_back({{u,v},w});
}
int main(int argc, char** argv) {
	int l,r;
	cin >> l >> r;
	puts("YES");
	cout << 23 << " ";
	for(int i=2;i<=22;i++)
	{
		add(1,i,1);
		int now=1;
		for(int j=2;j<i;j++)
			add(j,i,now),now<<=1;
	}
	if(l==1)
		++l,add(1,23,1);
	for(int i=20;i>=0;i--)
	{
		if(l+(1<<i)<=r+1)
		{
			add(i+2,23,l-1);
			l+=(1<<i);
		}
	}
	cout << ans.size() << "\n";
	for(auto t:ans) cout << t.first.first << " " << t.first.second << " " << t.second << "\n";
	return 0;
}