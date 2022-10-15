#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
#include<vector>
#include<map>
#include<list>
#include<set>
#include<cstring>
#include<ctime>
#include<cmath>
#include<limits>
#include<iterator>
#include<functional>
#include<unordered_map>
#include<stack>
#include<bitset>

#define all(v) v.begin(), v.end()
#define setv(ar, val) memset(ar, val, sizeof(ar));
#define ll long long int
#define ull unsigned long long int
#define PI 3.1415926535897932384626433832795
#pragma comment(linker, "/STACK:536870912")
#pragma warning(disable:4996)
using namespace std;

const int N = 25;
int a[N];

bool check() {
	int c = -1;
	for (int i = 1; i <= 24; i++) {
		if (i % 4 == 1)
			c = a[i];
		if (c != a[i])
			return false;
	}
	return true;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	for (int i = 1; i <= 24; i++)
		scanf("%d", &a[i]);

	for (int i = 0; i < 4; i++) {
		swap(a[2], a[6]);
		swap(a[4], a[8]);

		swap(a[2], a[10]);
		swap(a[4], a[12]);
		
		swap(a[4], a[21]);
		swap(a[2], a[23]);

		if (check() && (i == 0 || i == 2)) {
			printf("YES");
			return 0;
		}
	}

	for (int i = 0; i < 4; i++) {
		swap(a[1], a[5]);
		swap(a[3], a[7]);

		swap(a[1], a[9]);
		swap(a[3], a[11]);

		swap(a[3], a[22]);
		swap(a[1], a[24]);

		if (check() && (i == 0 || i == 2)) {
			printf("YES");
			return 0;
		}
	}

	for (int i = 0; i < 4; i++) {
		swap(a[13], a[5]);
		swap(a[14], a[6]);

		swap(a[13], a[17]);
		swap(a[14], a[18]);

		swap(a[13], a[21]);
		swap(a[14], a[22]);

		if (check() && (i == 0 || i == 2)) {
			printf("YES");
			return 0;
		}
	}

	for (int i = 0; i < 4; i++) {
		swap(a[15], a[7]);
		swap(a[16], a[8]);

		swap(a[15], a[19]);
		swap(a[16], a[20]);

		swap(a[15], a[23]);
		swap(a[16], a[24]);

		if (check() && (i == 0 || i == 2)) {
			printf("YES");
			return 0;
		}
	}

	for (int i = 0; i < 4; i++) {
		swap(a[3], a[17]);
		swap(a[4], a[19]);

		swap(a[3], a[10]);
		swap(a[4], a[9]);

		swap(a[3], a[16]);
		swap(a[4], a[14]);

		if (check() && (i == 0 || i == 2)) {
			printf("YES");
			return 0;
		}
	}

	for (int i = 0; i < 4; i++) {
		swap(a[1], a[18]);
		swap(a[2], a[20]);

		swap(a[1], a[12]);
		swap(a[2], a[11]);

		swap(a[1], a[15]);
		swap(a[2], a[13]);

		if (check() && (i == 0 || i == 2)) {
			printf("YES");
			return 0;
		}
	}

	printf("NO");

	return 0;

}