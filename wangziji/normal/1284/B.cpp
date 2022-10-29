#include <iostream>
#include <queue>
#define int long long
using namespace std;
int a[100005],l[100005],r[100005];
priority_queue <int,vector <int>,greater<int> > q,q2;
signed main(int argc, char** argv) {
	int n,cnt=0,CNT=0;
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		int m;
		cin >> m;
		l[i]=1e9,r[i]=-100;
		for(int j=1;j<=m;j++)
		{
			int x;
			cin >> x;
			if(x>l[i])
				a[i]=1;
			l[i]=min(l[i],x);
			r[i]=max(r[i],x);
		}
		if(!a[i])
			q.push(l[i]),q2.push(r[i]),CNT+=l[i]!=r[i];
		cnt+=a[i];
	}
	//cout << cnt << " " << CNT << endl;
	int ans=cnt*n*2-cnt*cnt,now=-100;
	cnt=0;
	q.push(1e9);
	while(!q2.empty())
	{
		int x=q2.top();
		q2.pop();
		while(x>now)
		{
			if(!q.empty())
				now=q.top(),q.pop(),++cnt;
			else break;
		}
		//cout << x << " " << now << endl;
		ans+=cnt-1;
	}
	cout << ans;
	return 0;
}