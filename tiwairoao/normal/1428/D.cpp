#include <bits/stdc++.h>

const int N = 100000;

std::vector<std::pair<int, int> >ans;
void add(int x, int y) {return ans.push_back(std::make_pair(x, y));}
void print() {
	printf("%d\n", (int)ans.size());
	for(auto p : ans) printf("%d %d\n", p.second, p.first);
}

int a[N + 5], b[N + 5], n;

int main() {
	scanf("%d", &n); for(int i=1;i<=n;i++) scanf("%d", &a[i]);
	
	int cnt = n; std::queue<int>q1, q2;
	for(int i=n;i>=1;i--) if( a[i] ) {
		if( a[i] == 1 ) add(i, cnt), b[i] = (cnt--), q1.push(i);
		else if( a[i] == 2 ) {
			if( q1.empty() ) {puts("-1"); return 0;}
			else {
				int x = q1.front(); q1.pop();
				add(i, b[i] = b[x]), q2.push(i);
			}
		} else {
			if( q2.empty() ) {
				if( q1.empty() ) {puts("-1"); return 0;}
				else {
					int x = q1.front(); q1.pop();
					add(x, cnt), add(i, cnt), cnt--, q2.push(i);
				}
			} else {
				int x = q2.front(); q2.pop();
				add(x, cnt), add(i, cnt), cnt--, q2.push(i);	
			}
		}
	}
	print();
}