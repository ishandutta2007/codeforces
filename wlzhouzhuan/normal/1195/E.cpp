#include<bits/stdc++.h>
using namespace std;

#define MAXN 3005

#define fs first
#define itt iterator
#define sd second
#define int long long 

int n,m,A,B;
long long a[MAXN][MAXN],c[MAXN][MAXN];
int g;
int ans;

struct dl
{
    deque<int>q,b;
    void ru(int x,int y) {
        while(!q.empty() && x < q.back())
        {
            q.pop_back();
            b.pop_back();
        }
        q.push_back(x);
        b.push_back(y);
    }
    void chu(int x) {
        while(!q.empty() && x >= b.front()) 
        {
            b.pop_front();
            q.pop_front(); 
        }
    }
    void qing() {
        while(!q.empty())
        {
            q.pop_front();
            b.pop_front(); 
        }
    }
}q;


signed main() {
	cin >> n >> m >> A >> B;
	int x,y,z,g;
	cin >> g >> x >> y >> z;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++){
			a[i][j] = g;
			g = (g*x+y)%z;
	}
	for(int i = 1; i <= n ; i ++)
	{
		q.qing(); 
		for(int j = 1; j <= m; j ++) {
			q.ru(a[i][j],j);
			q.chu(j-B);
			if(j >= B)
			{ 
				c[i][j] = q.q.front();
				//cout<<i<<" "<<j<<" "<<c[i][j]<<"\n";
			} 
		} 
	} 
	
	for(int j = B; j <= m; j ++)
	{
		q.qing();
		for(int i = 1; i <= n; i ++) {
			q.ru(c[i][j],i);
			q.chu(i-A);
			if(i >= A)
				ans += q.q.front();
		}
	}
	printf("%lld\n", ans);
	return 0;
 }