#include <cstdio>
#include <map>

const int N = 500000;
int q, map[N], size, val[N], a[N];
std::map<int, int> cur;

int create(int i) 
{
	if (cur.count(i)) return cur[i];
	map[size] = -1;
	val[size] = i;
	cur[i] = size++;
	return size - 1;
}

int find(int i) 
{
	if (map[i] == -1) return i;
	return map[i] = find(map[i]);
}

int main() 
{
	scanf("%d", &q);
	int amt = 0;
	while (q--) {
		int type, x;
		scanf("%d%d", &type, &x);
		if (type == 1) a[amt++] = create(x);
		else {
			int y;
			scanf("%d", &y);
			if (x != y && cur.count(x)) {
				map[cur[x]] = create(y);
				cur.erase(x);
			}
		}
	}
	for (int i = 0; i < amt; ++i) printf("%d ", val[find(a[i])]);
	printf("\n");
	return 0;
}