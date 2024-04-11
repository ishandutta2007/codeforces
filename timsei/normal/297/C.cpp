#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

#define Pair pair <int,int> 

int s[N] , a[N] , b[N] , n , m;

Pair X[N];

int main(void) {
    scanf("%d" , &n);
    for(int i = 0;i < n;++ i) scanf("%d" , &s[i]) , X[i] = make_pair(s[i] , i);
    sort(X , X + n);
    int tot = 0;
    int TTT = (n / 3) + !!(n % 3);
    if(TTT * 2 > n) TTT --;
    for(int i = 0;i < TTT;++ i) {
	a[X[i].second] = tot ++;
	b[X[i].second] = s[X[i].second] - a[X[i].second];
    }
    for(int i = TTT;i < 2 * TTT;++ i) {
	int cur = X[i].second;
	b[cur] = tot ++;
	a[cur] = s[cur] - b[cur];
    }
    tot = 0;
    for(int i = 2 * TTT;i < n;++ i) {
	int cur = X[i].second;
	b[cur] = (n - 1) - i;
	a[cur] = s[cur] - b[cur];
    }
    puts("YES");
    for(int i = 0;i < n;++ i) {
	cout << a[i] <<" ";
    }
    puts("");
    for(int i = 0;i < n;++ i) cout << b[i] << " ";
}