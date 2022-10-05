#include<bits/stdc++.h>

const int N = 100010;

inline int sig(int x){return (x > 0) - (x < 0);}

struct P{
	int x, y;
	
	P (){}
	
	P (int x, int y):x(x), y(y){}
	
	bool operator < (const P &p)const &{
		if (x == p.x && y == p.y) return false;
		if (!y){
			return x > 0 ? true : p.y < 0;
		}
		if (!p.y){
			return p.x > 0 ? false : y >= 0;
		}
		if (sig(y) != sig(p.y)) return y > p.y;
		return x * p.y - y * p.x > 0;
	}
};

std::pair <P, int> p[N];

inline double sqr(double x){return x * x;}

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1, x, y; i <= n; ++ i){
		scanf("%d%d", &x, &y);
		p[i] = {P (x, y), i};
	}
	std::sort(p + 1, p + n + 1);
	std::pair <int, int> min1 = {1, 0}, min2 = {1, 0};
	int sit1 = 0, sit2 = 0, sit3 = 0;
	for (int i = 1; i <= n; ++ i){
		P p1 = p[i].first, p2 = p[i % n + 1].first;
		int dot = p1.x * p2.x + p1.y * p2.y, det = p1.x * p2.y - p2.x * p1.y;
		std::pair <int, int> p = {std::abs(det), dot};
		if (dot < 0){
			p = {-p.first, -p.second};
			if (1ll * min1.first * p.second > 1ll * p.first * min1.second){
				min1 = p;
				sit1 = i;
			}
		}
		else if (dot > 0){
			if (1ll * min2.first * p.second > 1ll * p.first * min2.second){
				min2 = p;
				sit2 = i;
			}
		}
		else{
			sit3 = i;
		}
	}
	if (sit2){
		return printf("%d %d\n", p[sit2 % n + 1].second, p[sit2].second), 0;
	}
	else if (sit3){
		return printf("%d %d\n", p[sit3 % n + 1].second, p[sit3].second), 0;
	}
	else{
		return printf("%d %d\n", p[sit1 % n + 1].second, p[sit1].second), 0;
	}
}