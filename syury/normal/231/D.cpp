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
#define fi0(x) memset(x, 0, sizeof(x))
#define y1 adjf

int a[6];
int sum = 0;
int x, y, z;
int x1, y1, z1;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d%d%d", &x, &y, &z);
	scanf("%d%d%d", &x1, &y1, &z1);
	F(i, 0, 6)
		scanf("%d", &a[i]);
	if(y < 0){sum += a[0];}
	if(y > y1){sum += a[1];}
	if(z < 0){sum += a[2];}
	if(z > z1){sum += a[3];}
	if(x < 0){sum += a[4];}
	if(x > x1){sum += a[5];}
	printf("%d", sum);
	ret 0;
}