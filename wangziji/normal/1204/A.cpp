#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	string a;
	cin >> a;
	int ans=(a.size()+1)/2;
	if(a.size()&1)
	{
		--ans;
		for(int i=1;i<a.size();i++)
		{
			if(a[i]=='1')
			{
				++ans;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}