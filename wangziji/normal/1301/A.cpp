#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		string a,b,c;
		cin >> a >> b >> c;
		int flag=1;
		for(int i=0;i<a.size();i++)
		{
			if(a[i]==c[i]||b[i]==c[i])
				;
			else flag=0;
		}
		if(flag) puts("YES");
		else puts("NO");
	}
	return 0;
}