#include<bits/stdc++.h>

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
#define ws wejgnjn
#define left fhgfj
#define tm shfhf

const int MAXN = 2e3 + 3;

int a[MAXN];
int ex[MAXN];
int cu[MAXN];
int n;

int main(){
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	fi0(ex); fi0(cu);
	scanf("%d", &n);
	F(i, 0, n)scanf("%d", &a[i]);
	int bd = 0, pos = -1;
	int ans = 0;
	F(i, 0, n){
		F(j, 0, n){
			if(i < j && a[i] > a[j])cu[i]++;
			if(j < i && a[j] > a[i])cu[i]++;
			if(i < j && -a[i] > a[j])ex[i]++;
			if(j < i && a[j] > -a[i])ex[i]++;
		}
		ans += cu[i];
		if(ex[i] - cu[i] < bd){pos = i; bd = ex[i] - cu[i];}
	}
	ans/=2;
	while(pos != -1){
		ans += bd;
		bd = 0;
		int j = pos; pos = -1;
		cu[j] = 0; ex[j] = 0;
		F(i, 0, n){
			if(i < j && a[i] > a[j]){cu[i]--; ex[j]++;}
			if(i < j && a[i] > -a[j]){cu[i]++; cu[j]++;}
			if(i < j && -a[i] > a[j])ex[i]--;
			if(i < j && -a[i] > -a[j])ex[i]++;
			if(j < i && a[j] > a[i]){cu[i]--; ex[j]++;}
			if(j < i && -a[j] > a[i]){cu[j]++; cu[i]++;}
			if(j < i && a[j] > -a[i])ex[i]--;
			if(j < i && -a[j] > -a[i])ex[i]++;
			if(i != j && ex[i] - cu[i] < bd){bd = ex[i] - cu[i]; pos = i;}
		}
		a[j] *= -1;
	}
	printf("%d", ans);
	ret 0;
}