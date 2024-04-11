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

string s;
int fr;

int main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
	cin >> fr >> s;
	if(s[3] > '5'){s[3] = '0';}
	int hrs = stoi(s.substr(0, 2));
	if(fr == 12){
		if(hrs == 0){s[0] = '1';}
		if(hrs > 12){
			if(s[1] == '0'){s[0] = '1';}
			else{s[0] = '0';}
		}
	}
	else{
		if(hrs > 23){s[0] = '0';}
	}
	cout << s;
	ret 0;
}