#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define s second
#define f first

typedef pair<pair<int, int>, string> container;
typedef long long int int64;
typedef unsigned long long int  uint64;

const int MAX = 1e4;

bool visited[MAX][MAX];
int d, s;

string bfs(){
	queue <container> q;
	container init;
	
	init.f.f = 0, init.f.s = 0, init.s = "";
	visited[0][0] = true;
	
	q.push(init);

	while (!q.empty()){
		container tmp = q.front();
		int mod = tmp.f.f;
		int sum = tmp.f.s;
		string num = tmp.s; 
		q.pop();

		if (mod == 0 && sum == s)
			return num;
		if (sum > s)
			continue;

		for (int i = 0; i <= 9; i++){
			int nxt_mod = (10*mod + i)%d;
			int nxt_sum = sum + i;
			if (visited[nxt_mod][nxt_sum] == false){
				visited[nxt_mod][nxt_sum] = true;
				container nxt;
				nxt.f.f = nxt_mod;
				nxt.f.s = nxt_sum;
				nxt.s = num + to_string(i);
				q.push(nxt);
			}
		}
	}
	return "-1";
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> d >> s;

	cout << bfs() << endl;

	return 0;
}