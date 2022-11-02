#include<bits/stdc++.h>

using namespace std;
typedef long long lint;
typedef long double ldb;
typedef unsigned long long uli;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
#define pb push_back
#define rs resize
#define mk make_pair
#define asg assign
#define all(x) x.begin(),x.end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define era erase
#define fi0(x) memset(x, 0, sizeof(x))
#define y1 adjf

int n;
int p[60];
lint tot = 0ll;
lint cnt[5];
int cost[5];

int main(){
	scanf("%d", &n);
	F(i, 0, n)
		scanf("%d", &p[i]);
	F(i, 0, 5)
		scanf("%d", &cost[i]);
	fi0(cnt);
	F(i, 0, n){
		tot += p[i];
		Df(j, 4, -1){
			lint d = tot/cost[j];
			cnt[j] += d;
			tot %= cost[j];
		}
	}
	F(i, 0, 5)
		printf("%lld ", cnt[i]);
	printf("\n%lld", tot);
	ret 0;
}