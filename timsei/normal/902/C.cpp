#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+ 5;

int fa[N] , n , m , h , H[N];

#define issame(x , y) ((x == 1 || y == 1))

int main(void){
    scanf("%d" , &h); ++ h;
    bool per = 1;
    for(int i = 1;i < h;++ i) {
	cin >> H[i]; n += H[i];
    }
    cin >> H[h];
    n += H[h];
    for(int i = 1;i < h;++ i) {
	per &= issame(H[i] , H[i + 1]);
    }
    if(per) {
	puts("perfect"); return 0;
    }
    puts("ambiguous");
    for(int i = 1;i <= h;++ i) {
	int last = fa[i - 1]; fa[i] = fa[i - 1];
	for(int j = 1;j <= H[i];++ j) {
	    ++ fa[i]; cout << last << " ";
	}
    }
    puts("");
    for(int i = 1;i <= h;++ i) {
	int last = fa[i - 1]; fa[i] = fa[i - 1];
	if(H[i - 1] > 1 && H[i] > 1) -- last;
	for(int j = 1;j <= H[i];++ j) {
	    ++ fa[i]; cout << last <<" ";
	    if(last != fa[i - 1]) ++ last;
	}
    }
}