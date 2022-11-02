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
#define tm afhdhn

int n;
vector<int> a, last;

int main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
	scanf("%d", &n);
	a.rs(n); last.rs(n);
	F(i, 0, n)
		scanf("%d", &a[i]);
	int ptr = 0;
	F(i, 0, n){
		if(ptr < i){ptr = i;}
		while(ptr < n - 1 && a[ptr] < a[ptr + 1]){ptr++;}
		last[i] = ptr;	
	}
	int ans = 1;
	F(i, 0, n){
		if(n - i <= ans){brk;}
		ans = max(ans, last[i] - i + 1);
		if(last[i] == n - 1){cont;}
		ans = max(ans, last[i] - i + 2);
		if(last[i] == n - 2){cont;}
		if(a[last[i] + 2] <= a[last[i]] + 1)
			cont;
		ans = max(ans, last[last[i] + 2] - i + 1);
	}
	F(i, 0, n){
		if(n - i <= ans){brk;}
		int p = (last[i] == i) ? 0 : (a[last[i] - 1] + 1);
		if(p < a[last[i] + 1]){ans = max(ans, last[last[i] + 1] - i + 1);}
	}
	printf("%d", ans);
	ret 0;
}