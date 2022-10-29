#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		string a,b;
		cin >> a >> b;
		int ans=0;
		int w=0;
		for(int i=b.size()-1;i>=0;i--)
		{
			if(b[i]=='1')
			{
				break;
			}
			++w;
		}
		for(int i=a.size()-w-1;i>=0;i--)
		{
			if(a[i]=='1')
			{
				break;
			}
			++ans;
		}
		cout << ans << "\n";
	}
	return 0;
}