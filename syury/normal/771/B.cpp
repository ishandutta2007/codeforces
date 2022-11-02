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
#define ws wejgnjn
#define left fhgfj
#define tm shfhf

int n, k;

string gen(int id){
	char c = 'A' + id%26;
	string ans(1, c);
	if(id >= 26){ans += "a";}
	ret ans;
}

const int MAXN = 51;

string name[MAXN];
bool dif[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d%d", &n, &k);
	F(i, 0, n - k + 1){
		char c = getc(stdin);
		while(!isalpha(c))c = getc(stdin);
		if(c == 'Y')dif[i] = true; else dif[i] = false;
		c = getc(stdin);
		while(isalpha(c))c = getc(stdin);
	}
	int cid = 0;
	if(dif[0])F(i, 0, k)name[i] = gen(cid++);
	else{
		name[0] = gen(cid);
		F(i, 1, k)name[i] = gen(cid++);
	}
	int curr = 1;
	F(j, k, n){
		if(dif[curr++])name[j] = gen(cid++);
		else name[j] = name[j - k + 1];
	}
	F(i, 0, n)printf("%s ", name[i].c_str());
	ret 0;
}