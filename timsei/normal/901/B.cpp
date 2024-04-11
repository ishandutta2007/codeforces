#include <bits/stdc++.h>
using namespace std;

const int N = 155;

struct Vec {
    vector <double> wh;
    bool none(void) {
	return wh.size() == 0;
    }
    friend Vec operator % (Vec xxx , Vec yyy) {
	for(int i = (int) xxx.wh.size() - 1;i >= (int)yyy.wh.size() - 1;-- i) {
	    double ma = xxx.wh[i] / yyy.wh[yyy.wh.size() - 1];
	    for(int j = (int)yyy.wh.size() - 1;j >= 0;-- j) {
		xxx.wh[i - ((int)yyy.wh.size() - 1 - j)] -= yyy.wh[j] * ma;
	    }
       }
	while(xxx.wh.size() && fabs(xxx.wh.back()) <= 1e-7) xxx.wh.pop_back();
	return xxx;
    }
}a , b;

int calc(Vec x , Vec y) {
    int tot = 0;
    while(1) {
	x = x % y;
	++ tot;
	swap(x , y);
	if(y.none()) return tot;
    }
}

int g[N], f[N];

int main(void) {
    int s; cin >> s;
    while(1) {
	a.wh.resize(s + 1);
	b.wh.resize(s);
	for(int i = 0;i < s;++ i) {
	    a.wh[i] = rand() & 1; g[i] = a.wh[i] + 1e-9;
	}
	for(int i = 0;i < s - 1;++ i) {
	    b.wh[i] = rand() & 1; f[i] = b.wh[i] + 1e-9;
	}
	a.wh[a.wh.size() - 1] = b.wh[b.wh.size() - 1] = 1;
	g[s] = f[s - 1] = 1;
	if(calc(a , b) == s) {
	    cout << s << endl;
	    for(int i = 0;i <= s;++ i) cout << g[i] <<" ";
	    puts("");
	    cout << s - 1 << endl;
	    for(int i = 0;i < s;++ i) cout << f[i] <<" ";
	    return 0;
	}
    }
}