#include <bits/stdc++.h>
using namespace std;

const int N = 8e5 + 5;

int n , ty , a , top , q;
double A[N] , S[N] , x , sum;

int main(void) {
    cin.tie(0);
    top = 1;
    for(scanf("%d" , &q);q--;) {
	scanf("%d" , &ty);
	if(ty == 1) {
	    scanf("%d%lf" , &a , &x);
	    sum += a * x;
	    S[a] += x;
	}
	else if(ty == 2) {
	    scanf("%lf" , &x); sum += x; A[++ top] = x; S[top] = 0;
	}
	else if(ty == 3) {
	    S[-- top] += S[top + 1]; sum -= S[top + 1] + A[top + 1];
	}
	printf("%.20lf\n" , sum / top);
    }
}