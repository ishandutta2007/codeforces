#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const int N = 500;
const int K = N << 1;

namespace IO{
	In ll read(){
		ll s = 0,ww = 1;
		char ch = getchar();
		while(ch < '0' || ch > '9'){if(ch == '-')ww = -1;ch = getchar();}
		while('0' <= ch && ch <= '9'){s = 10 * s + ch - '0';ch = getchar();}
		return s * ww;
	}	
	In void write(ll x){
		if(x < 0)putchar('-'),x = -x;
		if(x > 9)write(x / 10);
		putchar('0' + x % 10);
	}
}
using namespace IO;

int n,cnt,curu;
int a[N+5][N+5],w[K+5],fa[K+5];
vector<int> vcn;

In bool cmp(int x,int y){
	return a[x][curu] < a[y][curu];
}
int solve(vector<int> vc){
	if(vc.size() == 1)return vc[0];
	vector<int> cur(0);
	int u = vc[0];curu = u;
	sort(vc.begin(),vc.end(),cmp);
//cout<<"solve:"<<endl;
//for(auto v : vc)cout<<v<<" "<<a[u][v]<<endl;
	int top = u;
	for(rg int i = 1;i < vc.size();i++){
		int v = vc[i];
		if(a[u][v] != a[u][vc[i-1]]){
			if(i != 1){
				int g = solve(cur),expw = a[u][vc[i-1]];
				if(w[g] == expw){
					fa[top] = g;
					top = g;
				}
				else{
					cnt++;
					w[cnt] = expw;
					fa[top] = fa[g] = cnt;
					top = cnt;
				}
				cur.resize(0);
			}
		}
		cur.push_back(v);
	}
			if(vc.size() != 1){
				int g = solve(cur),expw = a[u][vc[vc.size()-1]];
				if(w[g] == expw){
					fa[top] = g;
					top = g;
				}
				else{
					cnt++;
					w[cnt] = expw;
					fa[top] = fa[g] = cnt;
					top = cnt;
				}
				cur.resize(0);
			}
	return top;
}

int main(){
//	freopen("D.in","r",stdin);
//	freopen("D.out","w",stdout);
	n = cnt = read();
	vcn.resize(0);
	for(rg int i = 1;i <= n;i++){
		for(rg int j = 1;j <= n;j++){
			a[i][j] = read();
		}
	}
	for(rg int i = 1;i <= n;i++)w[i] = a[i][i],vcn.push_back(i);
	cnt = solve(vcn);
	write(cnt),putchar('\n');
	for(rg int i = 1;i <= cnt;i++)write(w[i]),putchar(' ');putchar('\n');
	write(cnt),putchar('\n');
	for(rg int i = 1;i < cnt;i++)write(i),putchar(' '),write(fa[i]),putchar('\n');	
	return 0;
}