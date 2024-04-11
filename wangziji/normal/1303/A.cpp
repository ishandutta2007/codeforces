#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		string a;
		cin >> a;
		int x=-1,y=-2;
		for(int i=0;i<a.size();i++)
		{
			if(a[i]=='1') {
			if(x==-1) x=i;y=i;}
		}
		int ans=0;
		for(int i=x;i<=y;i++) ans+=a[i]=='0';
		cout << ans << endl;
	}
	return 0;
}