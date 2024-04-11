#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
int p[300005],vis[300005];
stack <int> s;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,mn=1;
		cin >> n;
		for(int i=1;i<=n+1;i++)
			vis[i]=0;
		while(!s.empty()) s.pop();
		for(int i=1;i<=n;i++)
		{
			int x;
			cin >> x;
			s.push(x);
		}
		int flag=0;
		while(s.size()>1)
		{
			if(s.top()==mn)
			{
				flag=1;
				break;
			}
			int t=s.top();
			while(s.top()!=mn)
			{
				vis[s.top()]=1;
				s.pop();
			}
			if(s.size()==1) break;
			vis[s.top()]=1;
			s.pop();
			vis[t]=0;
			s.push(t);
			while(vis[mn]) ++mn;
		}
		if(flag) puts("NO");
		else puts("YES");
	}
	return 0;
}