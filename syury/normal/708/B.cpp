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
#define y1 adjf

void fail(){
	printf("Impossible");
	exit(0);
}

const int MAXN = 1000001;

int a, b, c, d;
int x, y;
lint tmp;
int fr = 0, bk = 0;
int eshift = 0;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d%d%d%d", &a, &b, &c, &d);
	lint cnt = 0;
	x = 1;
	tmp = d;
	while(x < MAXN && cnt < tmp){
		cnt += x;
		x++;
	}
	//printf("%d\n", x);
	if(x >= MAXN || cnt != tmp){
		fail();
	}
	cnt = 0;
	y = 1;
	tmp = a;
	while(y < MAXN && cnt < tmp){
		cnt += y;
		y++;
	}
	if(y >= MAXN || cnt != tmp){
		fail();
	}
	if(x == 1 || y == 1){
	    if(x == 1 && y == 1){
	        if(b + c == 1){
	            if(b == 1){printf("01");}
	            else{printf("10");}
	        }
	        if(b + c == 0){printf("0");}
	        if(b + c > 1){fail();}
	        ret 0;
	    }
	    if(b + c == 0){
	        if(x > 1){F(i, 0, x){putc('1', stdout);}}
	        else{F(i, 0, y){putc('0', stdout);}}
	        ret 0;
	    }
	}
//	printf("%d %d\n", x, y);
	if(x + y >= MAXN){
		fail();
	}
	lint f = x * 1ll * y;
	lint s = 0;
	if((lint)b + (lint)c != f){
		fail();
	}
	tmp = b;
	fr = x; bk = 0;
	while(s < tmp){
		lint nv = s + y;
		if(nv <= tmp){
			fr--; bk++;
			s = nv;
			cont;
		}
		lint delta = tmp - s;
		eshift = (int)delta;
		fr--;
		s = tmp;
		brk;
	}
	F(i, 0, fr){
		putc('1', stdout);
	}
	F(i, 0, y){
		eshift--;
		putc('0', stdout);
		if(eshift == 0){putc('1', stdout);}
	}
	F(i, 0, bk){
		putc('1', stdout);
	}
	ret 0;
}