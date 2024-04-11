#include<bits/stdc++.h>

const int N = 100010;

std::pair <std::pair<int, int>, int> p[N];
std::priority_queue <std::pair <int, int>> pq;
int n;
bool vis[N];

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &p[i].first.first);
	}
	for (int i = 0; i < n; ++ i){
		scanf("%d", &p[i].first.second);
		p[i].second = i + 1;
	}
	std::sort(p, p + n);
	pq.push({p[n - 1].first.second, p[n - 1].second});
	for (int i = n - 2; i >= 0; i -= 2){
		vis[pq.top().second] = true;
		pq.pop();
		if (i <= 0){
			break;
		}
		pq.push({p[i].first.second, p[i].second});
		pq.push({p[i - 1].first.second, p[i - 1].second});
	}
	vis[pq.top().second] = true;
	printf("%d\n", n / 2 + 1);
	for (int i = 1; i <= n; ++ i){
		if (vis[i]){
			printf("%d ", i);
		}
	}
	return printf("\n"), 0;
}