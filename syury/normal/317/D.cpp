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

int n;
const int MAXS = 1e5;
const int MP = 30;
char gr[MP] = {1
,2
,1
,4
,3
,2
,1
,5
,6
,2
,1
,8
,7
,5
,9
,8
,7
,3
,4
,7
,4
,2
,1
,10
,9
,3
,6
,11
,12
,14};
bool good[MAXS];

int main(){
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	fi0(good);
	scanf("%d", &n);
	int cha = 0;
	int oc = 0;
	for(int i = 2; i * i <= n; i++){
		if(good[i])cont;
		lint crr = i;
		int pw = 0;
		while(crr * crr <= n){
			good[crr] = true;
			crr *= i;
			pw++;
		}
		crr /= i;
		pw *= 2;
		if(crr * crr * i <= n)pw++;
		cha += pw;
		oc ^= gr[pw - 1];
	}
	cha = n - cha;
	cha = cha&1;
	cha ^= oc;
	if(cha)printf("Vasya");
	else printf("Petya");
	ret 0;
}