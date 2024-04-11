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

string s;
int pos[26];
char ans[2][13];

int main(){
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	finf(pos);
	int n = s.length();
	int fp = -1, sp = -1;
	F(i, 0, n){
		if(pos[s[i] - 'A'] > 100){pos[s[i] - 'A'] = i; cont;}
		fp = pos[s[i] - 'A']; sp = i;
	}
	if(fp + 1 == sp){printf("Impossible"); ret 0;}
	int pos = (sp - fp) - 1;
	pos /= 2;
	int currh = 0, cp = pos;
	F(i, fp, n){
		if(i == sp)cont;
		ans[currh][cp] = s[i];
		if(currh == 0){cp--; if(cp == -1){cp = 0; currh = 1;} cont;}
		if(currh == 1){cp++; if(cp == 13){cp = 12; currh = 0;}cont;}
	}
	F(i, 0, fp){
		ans[currh][cp] = s[i];
		if(currh == 0){cp--; if(cp == -1){cp = 0; currh = 1;} cont;}
		if(currh == 1){cp++; if(cp == 13){cp = 12; currh = 0;}cont;}

	}
	F(i, 0, 2){
		F(j, 0, 13)putc(ans[i][j], stdout);
		printf("\n");
	}
	ret 0;
}