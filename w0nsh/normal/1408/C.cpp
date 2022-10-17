#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

typedef long double K;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

    int t;
    std::cin >> t;
    std::cout << std::setprecision(12) << std::fixed;
    while(t--){
        int n, l;
        std::cin >> n >> l;
        VI A(n+2);
        FOR(i, n) std::cin >> A[i+1];
        A[n+1] = l;

        int i1 = 0;
        int i2 = n+1;
        K p1 = 0;
        K p2 = l;
        int s1 = 1;
        int s2 = 1;
        K time = 0;
        while(i1+1 < i2){
            K d1 = A[i1+1]-p1;
            K t1 = d1/s1;
            K d2 = p2-A[i2-1];
            K t2 = d2/s2;

            if(t1 < t2){
                i1++;
                p1 = A[i1];
                s1++;

                p2 -= t1*s2;
                time += t1;
            }else{
                i2--;
                p2 = A[i2];
                s2++;

                p1 += t2*s1;
                time += t2;
            }
        }

        K left = 0;
        K right = 1000000005;
        FOR(_, 100){
            K mid = (left+right)/2;
            if(p1 + mid*s1 <= p2 - mid*s2){
                left = mid;
            }else{
                right = mid;
            }
        }

        std::cout << time + left << "\n";
    }

	return 0;
}