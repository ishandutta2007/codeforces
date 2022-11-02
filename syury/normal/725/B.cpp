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
#define y1 adjf
#define tm afhdhn

char id;
lint n;
int ord[6] = {4, 5, 6, 3, 2, 1};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%lld%c", &n, &id);
	lint block = n/4;
	if(n % 4 != 0)block++;
	lint tr = (block - 1) * 16ll;
	if(n % 2 != 0){
		tr += (lint)ord[(id - 'a')];
	}
	else{
		tr += 7 + (lint)ord[(id - 'a')];
	}
	printf("%lld", tr);
	ret 0;
}