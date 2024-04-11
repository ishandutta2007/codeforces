#include <bits/stdc++.h>
using namespace std;
const int N=100050;
deque<int> q;
int a[N];
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	sort(a+1,a+1+n);
	q.push_back(a[n]);
	for(i=n-1;i>=1;i--)
	{
		if(q.front()>q.back()) q.push_front(a[i]);
		else q.push_back(a[i]);
	}
	for(int i=0;i<n;i++) printf("%i ",q[i]);
	return 0;
}