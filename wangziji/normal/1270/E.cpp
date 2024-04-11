#include <iostream>
#include <vector>
using namespace std;
vector <int> ans;
int x[100005],y[100005];
int main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> x[i] >> y[i];
	while(1)
	{
		ans.clear();
		for(int i=1;i<=n;i++)
			if((x[i]+y[i])&1)
				ans.push_back(i);
		if(ans.size()==n||ans.size()==0)
		{
			ans.clear();
			for(int i=1;i<=n;i++)
			{
				if(x[i]&1)
					ans.push_back(i);
			}
		}
		if(ans.size()==0||ans.size()==n)
		{
			for(int i=1;i<=n;i++)
			{
				if(x[i]&1) --x[i];
				if(y[i]&1) --y[i];
				x[i]/=2,y[i]/=2;
			}
			continue;
		}
		cout << ans.size() << endl;
		for(int i=0;i<ans.size();i++)
			cout << ans[i] << " ";
		return 0;
	}
	return 0;
}