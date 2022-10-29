#include <iostream>
#include <vector>
using namespace std;
vector <int> ans;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		string a;
		cin >> a;
		int n=a.size();
		ans.clear();
		for(int i=0;i<n-4;i++)
		{
			if(a.substr(i,5)=="twone")
			{
				ans.push_back(i+2);
				a[i+2]='*'; 
			}
		}
		for(int i=0;i<n-2;i++)
		{
			if(a.substr(i,3)=="one")
			{
				ans.push_back(i+1);
				a[i+1]='*';
			}
		}
		for(int i=0;i<n-2;i++)
		{
			if(a.substr(i,3)=="two")
			{
				ans.push_back(i+1);
				a[i+1]='*';
			}
		}
		cout << ans.size() << "\n";
		for(auto x:ans) cout << x+1 << " ";
		puts("");
	}
	return 0;
}