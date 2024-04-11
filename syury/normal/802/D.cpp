#include<bits/stdc++.h>

//#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx") 

using namespace std;
typedef long long lint;
typedef long double ldb;
typedef unsigned long long uli;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
#define I(i, a) for(auto i : a)
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
#define finf(x) memset(x, 127, sizeof(x))
#define acpy(y, x) memcpy(y, x, sizeof(y))
#define y1 adjf
#define tm dhgdg

int v;
int e[255];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	scanf("%d", &v);
	F(g, 0, v){
		ldb ex = 0.0;
		F(i, 0, 250)scanf("%d", &e[i]);
		F(i, 0, 250)ex += e[i];
		ex /= 250;
		ldb variance = 0.0;
		F(i, 0, 250)variance += (e[i] - ex) * (e[i] - ex);
		variance /= 250;
		ldb vu = ((2 * ex + 1) * (2 * ex + 1) - 1)/12;
		ldb vp = ex;
		if(fabs(variance - vu) < fabs(variance - vp))printf("uniform\n"); else printf("poisson\n");
	}
	ret 0;
}