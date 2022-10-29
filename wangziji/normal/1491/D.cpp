#include <iostream>
#include <vector>
using namespace std;
vector <int> a,b;
signed main() {
	int T;
	cin >> T;
	while(T--)
	{
		int x,y;
		cin >> x >> y;
		a.clear(),b.clear();
		for(int i=0;i<=30;i++) if(x&(1<<i)) a.push_back(i);
		for(int i=0;i<=30;i++) if(y&(1<<i)) b.push_back(i);
		if(a.size()<b.size()||a.back()>b.back())
		{
			puts("NO");
			continue;
		}
		while(a.size()&&b.size()&&a.back()==b.back()) a.pop_back(),b.pop_back();
		if(!a.size()&&!b.size())
		{
			puts("YES");
			continue;
		}
		if(!a.size()||!b.size())
		{
			puts("NO");
			continue;
		}
		if(a.size()&&b.size()&&a.back()>b.back())
		{
			puts("NO");
			continue;
		}
		b.pop_back();
		while(a.size()>b.size()) a.pop_back();
		int flag=1;
		while(!a.empty())
		{
			if(a.back()>b.back()) flag=0;
			a.pop_back(),b.pop_back();
		}
		if(flag) puts("YES");
		else puts("NO");
	}
	return 0;
}