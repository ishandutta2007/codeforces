#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define set0(x) memset(x,0,sizeof(x))
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
int n,a,b;
int ask(int x){
	cout<<"? "<<x<<endl;
	cin>>a;
	cout<<"? "<<x+n/2<<endl;
	cin>>b;
	return a-b;
}
int main() {
	cin>>n;
	int c = ask(1);
	if(c%2){
		cout<<"! -1"<<endl;
		return 0;
	}
	if(c == 0){
		cout<<"! 1"<<endl;
		return 0;
	}
	int l = 1,r = n/2;
	while(l+1<r){
		int mi = (l+r)/2,ca = ask(mi);
		if(ca*c>0){
			l = mi;
		}else{
			r = mi;
		}
	}
	cout<<"! "<<r<<endl;
	return 0;
}