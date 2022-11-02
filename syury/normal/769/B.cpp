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
#define y1 adjf
#define tm dhgdg

const int MAXN = 1e2 + 4;

int n;
int a[MAXN];
pair<int, int> buf[MAXN * MAXN + 69];
int kek[MAXN * MAXN + 69];
int bsz = 0, ksz = 0;

void fail(){
	printf("-1");
	exit(0);
}

void push(int x){
	kek[ksz++] = x;
}

int pop(){
	if(ksz == 0)ret -1;
	int ans = kek[ksz - 1];
	ksz--;
	ret ans;
}

void tell(int i){
	int prv = pop();
	if(prv == -1)fail();
	buf[bsz++] = mk(prv + 1, i + 1);
	F(j, 0, a[i])push(i);
}

int main(){
	scanf("%d", &n);
	F(i, 0, n)scanf("%d", &a[i]);
	if(a[0] == 0)fail();
	F(i, 0, a[0])push(0);
	F(i, 1, n){
		if(a[i] == 0)cont;
		tell(i);
	}
	F(i, 1, n){
		if(a[i] == 0)tell(i);
	}
	printf("%d\n", bsz);
	F(i, 0, bsz)printf("%d %d\n", buf[i].X, buf[i].Y);
	ret 0;
}