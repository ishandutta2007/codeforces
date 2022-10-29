#include <iostream>
#include <queue>
using namespace std;
queue <int> q;
queue <int> q2;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		string a;
		cin >> a;
		int n=a.size();
		for(int i=0;i<n;i++)
		{
			a[i]-='0';
			if(a[i]&1)
				q.push(a[i]);
			else
				q2.push(a[i]);
		}
		while(!(q.empty()&&q2.empty()))
		{
			if(!q2.empty()&&(q.empty()||q.front()>q2.front()))
			{
				cout << q2.front();
				q2.pop();
			}
			else
			{
				cout << q.front();
				q.pop();
			}
		}
		cout << "\n";
	}
	return 0;
}