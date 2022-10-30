#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

struct pt{
	ll x, y;
	pt(){}
	pt(ll _x, ll _y):x(_x),y(_y){}
	pt operator - (const pt & a){return pt(x - a.x, y - a.y);}
	ll cross(pt a){return x * a.y - y * a.x;}
};

const int MAXN = 1e6 + 6;

int n, m;
int ans[MAXN];
pt p[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++)cin >> p[i].x >> p[i].y;
	for(int i = 1; i <= n; i++)ans[i] = 1;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < m; j++){
			if(p[j].y == p[i].y)continue;
			int cnt = 0;
			pt v = p[j] - p[i];
			for(int k = 0; k < m; k++){
				if(v.cross(p[k] - p[i]) == 0)cnt++;
			}
			ll q = -p[i].y * v.x;
			if(q%v.y != 0)continue;
			ll x = q/v.y + p[i].x;
			if(x >= 1 && x <= n)ans[x] = max(ans[x], cnt);
		}
	}
	ll tot = 0;
	for(int i = 1; i <= n; i++)tot += ans[i];
	cout << tot;
	return 0;
}