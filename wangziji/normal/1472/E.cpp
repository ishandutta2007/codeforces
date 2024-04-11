#include <iostream>
#include <algorithm>
using namespace std;
pair <int,int> a[200005];
int A[200005];
struct qwq
{
	pair<int,int> x;
	int id;
}b[200005];
inline bool cmp(qwq x,qwq y)
{
	return x.x.first<y.x.first;
}
int main(int argc, char** argv) {
	int T;
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i].first >> a[i].second;
			if(a[i].first>a[i].second) swap(a[i].first,a[i].second);
			b[i].x=a[i],b[i].id=i;
		}
		sort(b+1,b+n+1,cmp);
		int now=1,mn=2e9,ans=0;
		for(int i=1;i<=n;i++)
		{
			while(b[now].x.first!=b[i].x.first)
			{
				if(b[now].x.second<mn) mn=b[now].x.second,ans=b[now].id;
				now++;
			}
			if(b[i].x.second>mn)
			{
				A[b[i].id]=ans;
			}else A[b[i].id]=-1;
		}
		for(int i=1;i<=n;i++) cout << A[i] << " ";
		puts("");
	}
	return 0;
}