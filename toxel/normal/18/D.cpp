#include<bits/stdc++.h>

const int N = 2010;
const int M = 5010;
typedef std::pair <int, int> pii;

int sit[N];
pii event[M];
char s[N];

struct BigInt{
	static const int N = 810;
	
	int len;
	int a[N];
	
	BigInt ():len(0){memset(a, 0, sizeof(a));}
	
	int &operator [](int sit){return a[sit];}
	
	void write(){
		if (!len){
			putchar('0');
		}
		for (int i = len - 1; i >= 0; -- i){
			putchar('0' + a[i]);
		}
	}
	
	BigInt operator +(const BigInt &b)const{
		BigInt ret;
		ret.len = std::max(len, b.len) + 1;
		for (int i = 0; i < ret.len; ++ i){
			ret.a[i] += a[i] + b.a[i];
			if (ret.a[i] >= 10){
				ret.a[i] -= 10;
				++ ret.a[i + 1];
			}
		}
		for ( ; ret.len && !ret.a[ret.len - 1]; -- ret.len);
		return ret;
	}
};

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i){
		int x;
		scanf("%s%d", s, &x);
		event[i] = {x, s[0] == 'w' ? 1 : 0};
		if (s[0] == 's'){
			sit[x] = i;
		}
	}
	std::vector <int> ans;
	std::vector <pii> disable;
	for (int i = N - 1; i >= 0; -- i){
		if (!sit[i]) continue;
		for (int j = sit[i] - 1; j; -- j){
			if (event[j].first == i && event[j].second){
				bool flag = true;
				for (auto u : disable){
					if (!(sit[i] > u.second && j > u.second || sit[i] < u.first && j < u.first)){
						flag = false;
						break;
					}
				}
				if (flag){
					ans.push_back(i);
					disable.push_back({j, sit[i]});
				}
				break;
			}
		}
	}
	std::reverse(ans.begin(), ans.end());
	BigInt ret, power;
	power[0] = power.len = 1;
	int now = 0;
	for (auto u : ans){
		while (now < u){
			++ now;
			power = power + power;
		}
		ret = ret + power;
	}
	ret.write();
	putchar('\n');
	return 0;
}