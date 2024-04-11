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

const int MAXN = 1e5 + 2;

int n;
string s;
int bsz[MAXN];
int cnt[2][MAXN];
lint sb[2][MAXN];
lint suff[2][2][MAXN];
lint ps[MAXN];
int sz = 0;
lint a0 = 0ll, a1 = 0ll;

int main(){
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	n = s.length();
	int curr = 0;
	F(i, 0, n){
		if(i != 0 && s[i] != s[i - 1]){bsz[sz++] = curr; curr = 0;}
		curr++;
	}
	bsz[sz++] = curr; curr = 0;
	lint cc = 0ll;
	sb[0][1] = 0ll; sb[1][1] = 1ll;
	F(i, 2, MAXN){
		sb[0][i] = sb[0][i - 1];
		sb[1][i] = sb[1][i - 1];
		sb[0][i] += i/2;
		sb[1][i] += i - i/2;
	}
	F(i, 0, sz){
		a0 += sb[0][bsz[i]];
		a1 += sb[1][bsz[i]];
		cnt[0][i] = bsz[i]/2;
		cnt[1][i] = bsz[i] - cnt[0][i];
		if(cc&1ll){swap(cnt[0][i], cnt[1][i]);}
		cc += bsz[i];
		ps[i] = cc;
	}
	Df(i, sz - 1, -1){
		if(i&1){
			if(i + 2 >= sz){suff[1][0][i] = cnt[0][i]; suff[1][1][i] = cnt[1][i];}
			else{suff[1][0][i] = suff[1][0][i + 2] + cnt[0][i]; suff[1][1][i] = suff[1][1][i + 2] + cnt[1][i];}
		}
		else{
			if(i + 2 >= sz){suff[0][0][i] = cnt[0][i]; suff[0][1][i] = cnt[1][i];}
			else{
				suff[0][0][i] = suff[0][0][i + 2] + cnt[0][i]; suff[0][1][i] = suff[0][1][i + 2] + cnt[1][i];
			}
		}
	}
	F(i, 0, sz){
		lint sum[2] = {0ll, 0ll};
		if(i + 2 < sz){
			sum[0] = suff[i%2][0][i + 2]; sum[1] = suff[i%2][1][i + 2];
		}
		if(ps[i] % 2 != 0){swap(sum[0], sum[1]);}
		int c1 = cnt[1][i], c0 = cnt[0][i];
		if(i != 0 && ps[i - 1] % 2 != 0){swap(c1, c0);}
		a0 += c1 * 1ll * sum[1] + c0 * 1ll * sum[0];
		a1 += c1 * 1ll * sum[0] + c0 * 1ll * sum[1];
	}
	printf("%lld %lld", a0, a1);
	ret 0;
}