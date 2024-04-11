#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline

const int N = 2e5;

typedef pair<int,int>pii;

namespace IO{
	In int read(){
		int s = 0,ww = 1;
		char ch = getchar();
		while(ch < '0' || ch > '9'){if(ch == '-')ww = -1;ch = getchar();}
		while('0' <= ch && ch <= '9'){s = 10 * s + ch - '0';ch = getchar();}
		return s * ww;
	}
	In void write(int x){
		if(x < 0)putchar('-'),x = -x;
		if(x > 9)write(x / 10);
		putchar('0' + x % 10);
	}
}
using namespace IO;

int n;

struct BIT{
	int b[N+5];
	void init(){
		memset(b,0,sizeof(int) * (n+1));
	}
	In int lowbit(int x){
		return x & -x;
	}
	void upd(int x,int dx){
		for(rg int i = x;i <= n;i += lowbit(i))b[i] += dx;
	}
	int query(int x){
		int rt = 0;
		for(rg int i = x;i;i -= lowbit(i))rt += b[i];
		return rt;
	}
	void ud(int x,int dx){
		int s = query(x) - query(x - 1);
		if(!s)upd(x,dx);
	}
}B;

int a[N+5];
set<int>s1,s2;
vector<int>v;

int main(){
//	freopen("B.in","r",stdin);
//	freopen("B.out","w",stdout);
	int t = read();
	while(t--){
		v.resize(0);
		n = read();
		for(rg int i = 1;i <= n;i++)a[i] = read();
		s1.clear();
		s2.clear();
		B.init();
		for(rg int i = 1;i <= n;i++){
			B.ud(a[i],1);
			if(B.query(i) == i)s1.insert(i);
		}
		B.init();
		for(rg int i = n;i >= 1;i--){
			B.ud(a[i],1);
			if(B.query(n-i+1) == n - i + 1)s2.insert(i);
		}
		for(auto x : s1){
			if(s2.count(x+1))v.push_back(x);
		}
		write(v.size()),putchar('\n');
		for(auto x : v)write(x),putchar(' '),write(n - x),putchar('\n');
	}
	return  0;	
}