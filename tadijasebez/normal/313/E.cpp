#include <bits/stdc++.h>
using namespace std;
const int N=100050;
int a[N],b[N];
deque<int> f,s;
int main()
{
	int n,m,i,j,x;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++) scanf("%i",&x),a[x]++;
	for(i=1;i<=n;i++) scanf("%i",&x),b[x]++;
	vector<int> ans;
	for(i=m-1;~i;i--)
	{
		for(j=1;j<=b[m-1-i];j++) f.push_back(m-1-i);
		for(j=1;j<=a[i];j++)
		{
			if(f.size()) ans.push_back((i+f.back())%m),f.pop_back();
			else s.push_back(i);
		}
	}
	while(f.size()) ans.push_back((f.back()+s.front())%m),f.pop_back(),s.pop_front();
	sort(ans.begin(),ans.end());reverse(ans.begin(),ans.end());
	for(int i:ans) printf("%i ",i);
	return 0;
}