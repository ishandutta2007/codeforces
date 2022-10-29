#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int qwq[200];
int main(int argc, char** argv) {
	string s,t;
	string qaq;
	cin >> qaq >> s;
	string S;
	for(auto t:qaq) qwq[t]=1;
	int q;
	cin >> q;
	while(q--)
	{
		cin >> t;
		if(t.size()<s.size()-1)
		{
			puts("NO");
			continue;
		}
		S=s;
	//	cout << S << "\n" << t << "*\n";
		while(t.size()&&S.size())
		{
			if(t.back()==S.back())
			{
				t.pop_back(),S.pop_back();
				continue;
			}
			if(S.back()=='?'&&qwq[t.back()])
			{
				t.pop_back(),S.pop_back();
				continue;
			}
			break;
		}
	//	cout << S << "\n" << t << "*\n";
		reverse(S.begin(),S.end());
		reverse(t.begin(),t.end());
		while(t.size()&&S.size())
		{
			if(t.back()==S.back())
			{
				t.pop_back(),S.pop_back();
				continue;
			}
			if(S.back()=='?'&&qwq[t.back()])
			{
				t.pop_back(),S.pop_back();
				continue;
			}
			break;
		}
		if(S.back()=='*')
		{
			while(t.size()&&!qwq[t.back()]) t.pop_back();
			S.pop_back(); 
		}
		if(S.size()||t.size())
		{
			puts("NO");
		}else puts("YES");
	}
	return 0;
}