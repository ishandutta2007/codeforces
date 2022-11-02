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
#define y1 adjf
#define ws wejgnjn
#define left fhgfj

int x, y, n;
int a;

bool can(int cnt){
	lint ystr = y * 1ll * cnt / x;
	if(y * 1ll * cnt % x == 0)ystr--;
	if(ystr + cnt <= (lint)a)ret true;
	ret false;
}

int bins(){
	int l = 0, r = a;
	while(r - l > 1){
		int mid = (l + r) >> 1;
		if(can(mid))l = mid;
		else r = mid - 1;
	}
	if(can(r))ret r;
	ret l;
}

int main(){
	scanf("%d%d%d", &n, &x, &y);
	F(i, 0, n){
		scanf("%d", &a);
		int cntf = bins();
		//if(cntf != 0 && cntf * 1ll * y % x == 0){printf("Both\n"); cont;}
		//if(cntf * 1ll * y < (a - cntf) * 1ll * x){printf("Vova\n");}else{printf("Vanya\n");}
		lint ycnt = cntf * 1ll * y / x;
		if(ycnt + cntf < a){printf("Vova\n"); cont;}
		if(cntf != 0 && cntf * 1ll * y % x == 0){printf("Both\n"); cont;}
		printf("Vanya\n");
	}
	ret 0;
}