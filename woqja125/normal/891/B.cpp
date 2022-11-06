#include<cstdio>
#include<algorithm>
using namespace std;
pair<int, int> in[100];
int r[100];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &in[i].first);
		in[i].second = i;
	}
	sort(in, in + n);
	for (int i = 0; i < n; i++) {
		r[in[i].second] = in[(i+1)%n].first;
	}
	for (int i = 0; i < n; i++)printf("%d ", r[i]);
}