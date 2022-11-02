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
#define tm dhgdg

const int MAXN = 2e5 + 5;
const int MAXM = 1e2 + 2;

string s;
string t[MAXM];
int z[MAXN];
int in[MAXN];
int dpl[MAXN], dpr[MAXN];
int part[MAXN];
char tmp[MAXN];
int tl = 0;
int n, m;
int ans = 0;

void calcz(){
	z[0] = 0;
	int l = 0, r = 0;
	F(i, 1, tl){
		z[i] = 0;
		if(i <= r)z[i] = min(z[i - l], r - i + 1);
		while(i + z[i] < tl && tmp[z[i]] == tmp[i + z[i]])z[i]++;
		if(i + z[i] - 1 > r){l = i; r = i + z[i] - 1;}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	cin >> m;
	n = (int)s.length();
	F(i, 0, m)cin >> t[i];
	F(i, 0, m){
		if((int)t[i].length() == 1){
			cont;
		}
		int len = (int)t[i].length();
		tl = len + 1 + n;
		F(j, 0, len)tmp[j] = t[i][j];
		tmp[len] = '#';
		F(j, 0, n)tmp[len + j + 1] = s[j];
		calcz();
		int prv = 0;
		F(j, 0, n)in[j] = MAXN;
		F(j, 0, n){
			int k = len + 1 + j;
			if(z[k] == 0)cont;
			in[j + z[k] - 1] = min(in[j + z[k] - 1], j);
		}
		Df(j, n - 1, -1)part[j] = (j == n - 1) ? in[j] : min(in[j], part[j + 1]);
		F(j, 0, n){
			dpl[j] = prv;
			int l = part[j];
			if(l <= j)dpl[j] = max(dpl[j], j - l + 1);
			prv = dpl[j];
		}
		reverse(all(t[i]));
		F(j, 0, len)tmp[j] = t[i][j];
		tmp[len] = '#';
		Df(j, n - 1, -1)tmp[len + 1 + n - 1 - j] = s[j];
		calcz();
		prv = 0;
		F(j, 0, n)in[j] = -1;
		Df(j, n - 1, -1){
			int k = len + 1 + n - 1 - j;
			if(z[k] == 0)cont;
			in[j - z[k] + 1] = max(in[j - z[k] + 1], j); 
		}
		F(j, 0, n)part[j] = (j == 0) ? in[j] : max(in[j], part[j - 1]);
		Df(j, n - 1, -1){
			dpr[j] = prv;
			int r = part[j];
			if(r >= j)dpr[j] = max(dpr[j], r - j + 1);
			prv = dpr[j];
		}
		F(j, 0, n - 1){
			if(dpl[j] > 0 && dpr[j + 1] > 0 && dpl[j] + dpr[j + 1] >= len){ans++; brk;}
		}
	}
	printf("%d", ans);
	ret 0;
}