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
#define tm afhdhn

int a[4];

void fail(){
	printf("-1"); exit(0);
}

string s;

int main(){
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	F(i, 0, 4)scanf("%d", &a[i]);
	if(abs(a[2] - a[3]) >= 2){printf("-1"); ret 0;}
	if(a[2] > a[3]){
		if(a[1] < a[2])fail();
		if(a[0] < a[3] + 1)fail();
		F(i, 0, a[0] - a[3])printf("4");
		a[0] = a[3];
		int b7 = a[2];
		int _c = 1;
		while(a[0] + a[1] > 0){
			if(_c){
				b7--; printf("7"); a[1]--;
				if(b7 == 0)
					while(a[1] > 0){printf("7"); a[1]--;}
			}
			else{
				printf("4"); a[0]--;
			}
			_c = 1 - _c;
		}
		ret 0;
	}
	else if (a[2] < a[3]){
		if(a[0] < a[3])fail();
		if(a[1] < a[2] + 1)fail();
		int _c = 1;
		printf("7");
		a[1]--;
		F(i, 0, a[0] - (a[3] - 1))printf("4");
		a[0] = (a[3] - 1);
		int b7 = a[2];
		while(a[0] + a[1] > 0){
			if(_c){
				b7--; printf("7"); a[1]--;
				if(b7 == 0)while(a[1] > 0){printf("7"); a[1]--;}
			}
			else{
				printf("4"); a[0]--;
			}
			_c = 1 - _c;
		}
		ret 0;
	}
	if(a[1] < a[2] || a[0] < a[3] + 1){
			if(a[0] < a[3])fail();
		if(a[1] < a[2] + 1)fail();
		int _c = 1;
		printf("7");
		a[1]--;
		F(i, 0, a[0] - (a[3] - 1))printf("4");
		a[0] = (a[3] - 1);
		int b7 = a[2];
		while(a[0] + a[1] > 0){
			if(_c){
				b7--; printf("7"); a[1]--;
				if(b7 == 0)while(a[1] > 0){printf("7"); a[1]--;}
			}
			else{
				printf("4"); a[0]--;
			}
			_c = 1 - _c;
		}

	}
	else{	F(i, 0, a[0] - a[3])printf("4");
		a[0] = a[3];
		int b7 = a[2];
		int _c = 1;
		while(a[0] + a[1] > 0){
			if(_c){
				b7--; printf("7"); a[1]--;
				if(b7 == 0)
					while(a[1] > 0){printf("7"); a[1]--;}
			}
			else{
				printf("4"); a[0]--;
			}
			_c = 1 - _c;
		}
	}
	ret 0;
}