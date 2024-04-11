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

const int MAXN = 1e5 + 5;

int n, m;
int a[MAXN];
int nxt[MAXN];
int lai[MAXN];
int cnt[MAXN];
int id[MAXN];

int main(){
	scanf("%d%d", &n, &m);
	int bsz = (int)sqrt(n);
	bsz = max(bsz, 1);
	int curr = 0;
	int cid = 0;
	F(i, 0, n){
		scanf("%d", &a[i]);
		curr++;
		if(curr > bsz){curr = 1; cid++;}
		id[i] = cid;
	}
	Df(i, n - 1, -1){
		int j = i + a[i];
		lai[i] = i;
		if(j >= n){nxt[i] = n; cnt[i] = 1; cont;}
		if(id[j] != id[i]){nxt[i] = j; cnt[i] = 1; cont;}
		cnt[i] = cnt[j] + 1;
		nxt[i] = nxt[j];
		lai[i] = lai[j];
	}
	F(i, 0, m){
		int tp, pos;
		scanf("%d%d", &tp, &pos); pos--;
		if(tp == 1){
			int ans = 0, last;
			while(pos < n){
				last = pos;
				ans += cnt[pos];
				pos = nxt[pos];
			}
			printf("%d %d\n", lai[last] + 1, ans);
		}
		else{
			int len;
			scanf("%d", &len);
			a[pos] = len;
			Df(j, pos, -1){
				if(id[j] != id[pos])brk;
				int k = j + a[j];
				lai[j] = j;
				if(k >= n){nxt[j] = n; cnt[j] = 1; cont;}
				if(id[k] != id[j]){nxt[j] = k; cnt[j] = 1; cont;}
				cnt[j] = cnt[k] + 1;
				nxt[j] = nxt[k];
				lai[j] = lai[k];
			}
		}
	}
	ret 0;
}