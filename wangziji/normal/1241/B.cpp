#include <iostream>
#include <cstring>
using namespace std;
int x[200],v[200];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	string a,b;
	while(T--)
	{
		cin >> a >> b;
		if(a==b)
		{
			puts("YES");
			continue;
		}
		memset(x,0,sizeof x);
		memset(v,0,sizeof v);
		for(int i=0;i<a.size();i++)
			++x[a[i]];
		int f=0;
		for(int i=0;i<b.size();i++)
		{
			if(x[b[i]])
			{
				f=1;
				puts("YES");
				break;
			}
		}
		if(!f)
			puts("NO");
	}
	return 0;
}