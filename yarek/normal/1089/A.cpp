#include <bits/stdc++.h>
using namespace std;

const int N = 200;

#define sz(x) (int)(x).size()

struct st{
	int pa, pb, sa, sb;
	st() {}
	st(int _pa, int _pb) : pa(_pa), pb(_pb) {
		assert(abs(pa - pb) >= 2);
		if(pa > pb)
			sa = 1, sb = 0;
		else
			sa = 0, sb = 1;
	}
};

vector < st > vec[2];

bool vis[N + 1][N + 1][4][4];
st from[N + 1][N + 1][4][4];

void Go(int x, int y, int a, int b)
{
	vis[x][y][a][b] = true;
	if(a == 3 || b == 3) return;
	int p = 0;
	if(a == 2 && b == 2) p = 1;
	for(auto v: vec[p])
	{
		int kx = x + v.pa, ky = y + v.pb, ka = a + v.sa, kb = b + v.sb;
		if(kx > N) return;
		if(ky > N) continue;
		if(!vis[kx][ky][ka][kb])
		{
			from[kx][ky][ka][kb] = v;
			Go(kx, ky, ka, kb);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	for(int i = 0; i <= N; i++)
	{
		for(int j = 0; j <= N; j++)
		{
			if(max(i, j) < 25) continue;
			if(max(i, j) > 25 && abs(i - j) != 2)
				continue;
			if(abs(i - j) < 2) continue;
			vec[0].push_back(st(i, j));
		}
	}
	for(int i = 0; i <= N; i++)
	{
		for(int j = 0; j <= N; j++)
		{
			if(max(i, j) < 15) continue;
			if(max(i, j) > 15 && abs(i - j) != 2)
				continue;
			if(abs(i - j) < 2) continue;
			vec[1].push_back(st(i, j));
		}
	}
	
	Go(0, 0, 0, 0);
	
	int m; cin >> m;
	while(m--)
	{
		int x, y, a = -100, b = 0;
		cin >> x >> y;
		for(int i = 0; i <= 3; i++)
		{
			for(int j = 0; j <= 3; j++)
			{
				if(max(i, j) != 3) continue;
				if(!vis[x][y][i][j]) continue;
				if(i - j > a - b)
				{
					a = i;
					b = j;
				}
			}
		}
		if(a == -100) 
		{
			cout << "Impossible\n";
			continue;
		}
		
		cout << a << ":" << b << "\n";
		vector < pair < int, int > > sta;
		while(a > 0 || b > 0)
		{
			st s = from[x][y][a][b];
			sta.push_back({s.pa, s.pb});
			x -= s.pa;
			y -= s.pb;
			a -= s.sa;
			b -= s.sb;
		}
		while(!sta.empty())
		{
			cout << sta.back().first << ":" << sta.back().second << " ";
			sta.pop_back();
		}
		cout << "\n";
	}

	return 0;
}