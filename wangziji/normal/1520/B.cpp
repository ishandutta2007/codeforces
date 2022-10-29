#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define int long long
using namespace std;
inline int cal(int x)
{
	int rtn=0;
	for(int i=1;i<=10;i++)
	{
		for(int j=1;j<=9;j++)
		{
		int qwq=0;
			for(int k=1;k<=i;k++)
				qwq*=10,qwq+=j;
			if(qwq<=x) ++rtn;
		}
	}
	return rtn;
}
signed main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		cout << cal(n) << "\n";
	}
	return 0;
}