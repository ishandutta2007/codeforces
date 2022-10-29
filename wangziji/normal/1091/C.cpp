#include <iostream>
#include <queue>
#define int long long
using namespace std;
priority_queue <int,vector <int>,greater<int> > q;
int n;
inline int cal(int x)
{
	int t=n/x;
	--t;
	t=t*(t+1)/2;
	return t*x+n/x;
}
signed main(int argc, char** argv) {
	cin >> n;
	for(int i=1;i*i<=n;i++)
	{
		if(n%i) continue;
		q.push(cal(i));
		if(i*i!=n)
		{
			q.push(cal(n/i));
		}
	}
	while(!q.empty())
	{
		cout << q.top() << " ";
		q.pop();
	}
	return 0;
}