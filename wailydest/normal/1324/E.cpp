#include <iostream>
using namespace std;

bool belong(int x, int l, int r) 
{
	return x >= l && x <= r ? 1 : 0;
}

int main() 
{
	int n, h, l, r;
	cin >> n >> h >> l >> r;
	
	int current_max[2000];
	
	current_max[0] = 0;
	for (int i = 1; i < h; ++i) current_max[i] = -1;
	
	int current;
	
	while (n--) {
		int next_max[2000];
		for (int i = 0; i < h; ++i) next_max[i] = -1;
		
		cin >> current;
		for (int i = 0; i < h; ++i) {
			if (current_max[i] != -1) next_max[(i + current) % h] = current_max[i] + belong((i + current) % h, l, r);
		}
		for (int i = 0; i < h; ++i) {
			if (current_max[i] != -1) next_max[(i + current - 1) % h] = max(next_max[(i + current - 1) % h], current_max[i] + belong((i + current - 1) % h, l, r));
		}
		
		for (int i = 0; i < h; ++i) {
			current_max[i] = next_max[i];
		}
	}
	
	current = current_max[0];
	for (int i = 1; i < h; ++i) if (current < current_max[i]) current = current_max[i];
	
	cout << current << '\n';
	
	return 0;
}