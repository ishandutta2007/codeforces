#include <bits/stdc++.h>
 
using namespace std;
 
#define FOE(i, s, t) for (int i = s; i <= t; i++)
#define FOR(i, s, t) for (int i = s; i < t; i++)
#define FOD(i, s, t) for (int i = s; i >= t; i--)
#define K 400001
#define LL long long
#define mp make_pair
#define pb push_back
#define M 1000000007
#define pow qjwopjqpw
 
int n;
 

void print(int x, int y) {
	printf("%c%d", (char)(x + 'a' - 1), y);	
}

vector<pair<int, int> > v;
 
int main() {
	scanf("%d", &n);
	
	n++;
	
	FOE(i, 1, 8) {
		if (i % 2) {
			v.pb({i, 1});
			FOD(j, 8, 2) v.pb({i, j});
		} else if (i != 8) {
			v.pb({i, 2});
			FOD(j, 8, 3) v.pb({i, j});
			v.pb({i, 1});
		} else {
			v.pb({i, 2});
			v.pb({i, 1});
			FOE(j, 3, 8) v.pb({i, j});	
		}
	}
	
	if (n != 64) {
		if (n <= 57) {
			int cy = v[n - 3].second;
			
			if (cy != 8) {
				FOE(i, 1, n - 2) {
					print(v[i - 1].first, v[i - 1].second);
					printf(" ");
					
					cy = v[i - 1].second;
				}
				print(8, cy);
				printf(" ");
				print(8, 8);
			} else {
				FOE(i, 1, n - 3) {
					print(v[i - 1].first, v[i - 1].second);
					printf(" ");
					
					cy = v[i - 1].second;
				}
				print(8, cy);
				printf(" ");
				print(8, (cy == 1 ? 2 : 1));
				printf(" ");
				print(8, 8);
			}
			
		} else {
			
			FOE(i, 1, n - 1) {
				print(v[i - 1].first, v[i - 1].second);
				printf(" ");
			}
			
			print(8, 8);
		}
	} else {
		FOE(i, 1, n) {
			print(v[i - 1].first, v[i - 1].second);
			
			if (i != n) printf(" ");
		}
	}
	puts("");
}