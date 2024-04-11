#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline

const int N = 200;

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

int n,m,k;
vector<char>v;

int main(){
//	freopen("C.in","r",stdin);
	n = read(),m = read(),k = read();
	int x,y;
	for(rg int i = 1;i <= 2 * k;i++)cin >> x >> y;
//cout<<n<<" "<<m<<endl;
	for(rg int i = 1;i < m;i++)v.push_back('L');
	for(rg int i = 1;i < n;i++)v.push_back('U');
	for(rg int i = 1;i <= n;i++){
		if(i % 2 == 1)
			for(rg int j = 1;j < m;j++)v.push_back('R');
			else 
			for(rg int j = 1;j < m;j++)v.push_back('L');
		v.push_back('D');
	}
	cout<<v.size()<<endl;
	for(rg int i = 0;i < v.size();i++)putchar(v[i]);
	putchar('\n');
	return 0;
}