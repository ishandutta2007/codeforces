#include <bits/stdc++.h>
#define ll long long
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
using namespace std;
const int MOD=1e9+7,N=5e5+5;
const ll INF=1e18;
int mas[12]={31,28,31,30, 31,30,31,31, 30,31,30,31,};
int m,d,x;
int main(){
	cin>>m>>d;
	m--;
	if (mas[m]==28&&d==1){cout<<4<<endl;return 0;}
	if (mas[m]-(7-d+1)>28){cout<<6<<endl;return 0;}
	cout<<5<<endl;
    return 0;
}