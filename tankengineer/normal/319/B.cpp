#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 100005;

int n, a[N], prec[N], next[N], tokill[N];
vector<int> v, q;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
	  scanf("%d", &a[i]);
	  prec[i] = i - 1;
	  next[i] = i + 1;
	  tokill[i] = 0;
	}
	prec[1] = 0;
	next[n] = 0;
	for (int i = 1; i < n; ++i) {
	  if (a[i] > a[next[i]]) {
	    tokill[next[i]] = 1;
	    v.push_back(next[i]);
		}
	}
	int cnt = 0;
	while (v.size()) {
		++cnt;
		q.clear();
		while (v.size()) {
		  int tmp = v[v.size() - 1];
		  v.pop_back();
		  int froe = prec[tmp], nect = next[tmp];
		  if (nect == 0) {
		    next[froe] = 0;
			} else {
			  next[froe] = nect;
			  prec[nect] = froe;
			  if (tokill[froe] != cnt && tokill[nect] != cnt && a[froe] > a[nect]) {
			    q.push_back(nect);
			    tokill[nect] = cnt + 1;
				}
			}
		}
		v = q;
		//for (int i = 1; i; i = next[i]) printf("%d\n", a[i]);
	}
	cout << cnt << endl;
	return 0;
}