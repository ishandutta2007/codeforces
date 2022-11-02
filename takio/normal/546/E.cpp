#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
using namespace std;

const int N = 410;

int mp[N][N],flow[N][N],minflow,pre[N],s,t;

int max_flow()
{
	int cur,u,v,ans=0;
	memset(flow,0,sizeof(flow));
	while(1)
	{
		memset(pre,-1,sizeof(pre));
		queue<int>q;
		minflow=1e9;
		q.push(s);
		while(!q.empty())
		{
			cur=q.front();
			q.pop();
			if(cur==t)
				break;
			for(v=s;v<=t;v++)
			{
				if(pre[v]<0&&mp[cur][v]-flow[cur][v]>0)
				{
					pre[v]=cur;
					minflow=min(minflow,mp[cur][v]-flow[cur][v]);
					q.push(v);
				}
			}
		}
		if(pre[t]==-1)
			break;
		for(v=t;v!=s;v=pre[v])
		{
			u=pre[v];
			flow[u][v]+=minflow;
			flow[v][u]-=minflow;
		}
		ans+=minflow;
	}
	return ans;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, m, sum = 0, sum2 = 0;
    cin >> n >> m;
    int a[110], b[110], u, v;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &a[i]);
        sum += a[i];
    }
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &b[i]);
        sum2 += b[i];
    }
    if (sum != sum2) {
        cout << "NO\n";
        return 0;
    }
    s = 0, t = n * 2 + 1;
    for (int i = 1; i <= n; i++) {
//        cout << s << ' ' << i << ' ' << a[i] <<endl;
//        cout << i + n << ' ' << t << ' ' << b[i] <<endl;
        mp[s][i] = a[i];
        mp[i + n][t] = b[i];
        mp[i][i + n] = 1e8;
    }
    for (int i = 1; i <= m; i++) {
        scanf ("%d%d", &u, &v);
//        cout << u << ' ' << v + n << endl;
//        cout << v << ' ' << u + n << endl;
        mp[u][v + n] = mp[v][u + n] = 1e8;
    }
//    cout << max_flow() << endl;
    if (max_flow() != sum) {
        cout << "NO\n";
        return 0;
    } else {
        cout << "YES\n";
        for (int i = 1; i <= n; i++) {
            for (int j = n + 1; j <= n + n; j++) {
                printf ("%d ", flow[i][j]);
            }
            cout << endl;
        }
    }
}