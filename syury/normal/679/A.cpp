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

void ask(int x){
	printf("%d\n", x);
	fflush(stdout);
}

bool get(){
	string tmp;
	cin >> tmp;
	if(tmp == "yes")
		ret true;
	ret false;
}

set<int> divs;

bool has(int x){
	ret divs.find(x) != divs.end();
}

int p[11] = {11, 	13, 	17, 	19, 	23, 	29, 	31, 	37, 41, 	43, 	47};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	F(i, 2, 9){
		ask(i);
		bool isd = get();
		if(isd){divs.ins(i);}
	}
	int sz = divs.size();
	if(sz == 0){printf("prime\n"); fflush(stdout);ret 0;}
	if(sz > 1){printf("composite\n"); fflush(stdout);ret 0;}
	if(has(4) || has(6) || has(8) || has(9)){printf("composite\n");fflush(stdout);}
	int base = *(divs.begin());
	ask(base * base);
	if(get()){printf("composite\n"); fflush(stdout); ret 0;}
	F(i, 0, 11){
		ask(p[i]);
		if(get()){printf("composite\n"); fflush(stdout); ret 0;}
	}
	printf("prime\n");
	fflush(stdout);
	ret 0;
}