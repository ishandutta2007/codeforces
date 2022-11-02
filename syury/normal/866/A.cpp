#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ldb;

#define sqr(x) ((x) * (x))
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define fin(name) freopen(name, "r", stdin)
#define fout(name) freopen(name, "w", stdout)
#define I(x, a) for(auto x : a)
#define F(i, l, r) for(auto i = l; i != r; i++)
#define DF(i, l, r) for(auto i = l; i != r; i--)
#define clean(a) memset((a),0,sizeof (a))
#define sync ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) x.begin(),x.end()
#define ret return
#define cont continue
#define brk break
#define ins insert

int a;

signed main(){
	scanf("%d", &a);
	if(a == 1){printf("1 1\n1"); ret 0;}
	int n = 2 * (a - 1);
	printf("%d 2\n", n);
	printf("1 2");
    return 0;
}