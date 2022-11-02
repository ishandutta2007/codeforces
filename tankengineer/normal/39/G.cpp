#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

const int MOD = 32768;
int ans, v, f[MOD + 5], num, p, l;
string s[105], tmp;

int exp();

int getnum() {
  if (tmp[l] == 'n') {
	  ++l;
	  return v;
	}
	if (tmp[l] == 'f') {
	  l += 2;
	  int ret = f[exp()];
	  l++;
	  return ret;
	}
	int ret = 0;
	while (tmp[l] >= '0' && tmp[l] <= '9') ret = ret * 10 + (tmp[l++] - '0');
	return ret;
}

int sl() {
  int ret = getnum();
  while (tmp[l] == '*' || tmp[l] == '/') {
	  char tp = tmp[l++];
	  int t1 = getnum();
	  //cout <<ret<<t1 <<tp<<endl;
	  if (tp == '*') {
			//cout<<"WA"<<endl;
			ret = (int)(((long long)ret * t1) % MOD);
			} else {
			ret = (ret / t1) % MOD;
		}
	}
	return ret;
}

int exp() {
	int ret = sl();
	while (tmp[l] == '+' || tmp[l] == '-') {
	  char tp = tmp[l++];
	  int t1 = sl();
	  if (tp == '+') ret = (ret + t1) % MOD; else ret = (ret + MOD - t1) % MOD;
	}
	return ret;
}

bool iexp() {
  int p1, p2, tp;
  p1 = exp();
  switch(tmp[l]) {
	  case '=' : {
			tp = 0;
			l += 2;
			break;
		}
		case '<' : {
			tp = -1;
			++l;
			break;
		}
		case '>' : {
		  tp = 1;
		  ++l;
		  break;
		}
	}
	p2 = exp();
	//printf("%d %d %d\n", p1, tp, p2);
	if (tp == 0) return p1 == p2;
	if (tp == -1) return p1 < p2;
	if (tp == 1) return p1 > p2;
	return false;
}

int getans() {
  for (int i = 0; i < num; ++i) {
	  tmp = s[i];
	  if (tmp[0] == 'i') {
		  l = 3;
		  if (iexp()) {
				l += 7;
				return exp();
			}
		} else {
			l = 6;
			return exp();
		}
	}
	return -1;
}

int main() {
  char ch;
  scanf("%d", &ans);
  cin >> ch;
  while (ch != '{') cin >> ch;
  num = 0;
  while (true) {
		cin >> ch;
		if (ch == '}') break;
		if (ch == ';') ++num; else s[num] += ch;
	}
	
	int anst = -1;
	for (int i = 0; i <= 32767; ++i) {
		v = i;
	  f[i] = getans();
	  if (f[i] == ans) anst = i;
	}
	printf("%d\n", anst);
	return 0;
}