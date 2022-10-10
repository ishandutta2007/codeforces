#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const long long INF = 1e10;
const int ms = 10;

long long freq[ms][ms];
long long dist[ms][ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	{
		std::string str;
		std::cin >> str;
		n = (int) str.size();
		for(int i = 0; i + 1 < (int) str.size(); i++) {
			freq[str[i]-'0'][str[i+1]-'0']++;
		}
	}
	for(int v1 = 0; v1 < ms; v1++) {
		for(int v2 = 0; v2 < ms; v2++) {
			for(int i = 0; i < ms; i++) {
				for(int j = 0; j < ms; j++) {
					dist[i][j] = INF;
				}
			}
			for(int i = 0; i < ms; i++) {
				dist[i][(i+v1)%ms] = 1;
				dist[i][(i+v2)%ms] = 1;
			}
			for(int k = 0; k < ms; k++) {
				for(int i = 0; i < ms; i++) {
					for(int j = 0; j < ms; j++) {
						dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
					}
				}
			}
			long long ans = 0;
			for(int i = 0; i < ms; i++) {
				for(int j = 0; j < ms; j++) {
					ans += freq[i][j] * dist[i][j];
				}
			}
			if(ans >= INF) ans = -1;
			else ans = ans - n + 1;
			std::cout << ans << (v2 + 1 == ms ? '\n' : ' ');
		}
	}
}