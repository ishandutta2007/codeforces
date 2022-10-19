#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

char s[N] , t[N];
int q , n , m , x , y , ty , l , r;

bitset <N> B[26] , now;

int main(void) {
    scanf("%s" , s + 1); n = strlen(s + 1);
    for(int i = 1;i <= n;++ i) B[s[i] - 'a'][i] = 1;
    for(scanf("%d" , &q);q --;) {
	scanf("%d" , &ty);
	if(ty == 1) {
	    scanf("%d%s" , &x , t + 1);
	    B[s[x] - 'a'][x] = 0; B[t[1] - 'a'][x] = 1;
	    s[x] = t[1];
	}
	else {
	    scanf("%d%d%s" , &l , &r , t + 1);
	    m = strlen(t + 1);
	    if(r - l + 1 < m) {
		puts("0"); continue;
	    }
	    now.reset(); now = ~now;
	    for(int i = 1;i <= m;++ i) {
		now &= (B[t[i] - 'a'] >> (i - 1));
	    }
	    printf("%d\n" , (int)(now >> (l)).count() - (int)(now >> (r - m + 2)).count());
	}
    }
}