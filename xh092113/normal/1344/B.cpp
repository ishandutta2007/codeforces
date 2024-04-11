#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const int N = 1000;

typedef pair<int,int> pii;

namespace IO{
	In ll read(){
		ll s = 0,ww = 1;
		char ch = getchar();
		while(ch < '0' || ch > '9'){if(ch == '-')ww = -1;ch = getchar();}
		while('0' <= ch && ch <= '9'){s = 10 * s + ch - '0';ch = getchar();}
		return s * ww;
	}
	In void write(ll x){
		if(x < 0)x = -x,putchar('-');
		if(x > 9)write(x / 10);
		putchar('0' + x % 10);
	}
}
using namespace IO;

bool b[N+5][N+5],vis[N+5][N+5];
char s[N+5];
int n,m;
int mx[4] = {1,0,-1,0};
int my[4] = {0,1,0,-1};
queue<pii>q;

In bool check(int i,int j){
	return 1 <= i && i <= n && 1 <= j && j <= m && b[i][j] && !vis[i][j];
}

bool t13;

void bfs(int si,int sj){
	vis[si][sj] = 1;
	q.push(make_pair(si,sj));
	while(!q.empty()){
		pii u = q.front();
//if(t13)cout<<"first="<<u.first<<" second="<<u.second<<endl;
		q.pop();
		for(rg int i = 0;i < 4;i++){
			int x = u.first + mx[i];
			int y = u.second + my[i];
			if(check(x,y)){
				vis[x][y] = 1;
				q.push(make_pair(x,y));
			}
		}
	}
}

int main(){
//	freopen("B.in","r",stdin);
//	freopen("B.out","W",stdout);
	n = read(),m = read();
	for(rg int i = 1;i <= n;i++){
		scanf("%s",s + 1);
		for(rg int j = 1;j <= m;j++)if(s[j] == '.')b[i][j] = 0;
		else b[i][j] = 1;
	}
/*for(rg int i = 1;i <= n;i++){
	for(rg int j = 1;j <= m;j++)cout<<b[i][j]<<" ";cout<<endl;
}*/
/*t13 = 1;
if(n != 1000 || m != 1000)t13 = 0;
for(rg int j = 1;j <= 10;j++)if(b[1][j])t13 = 0;
int sks = 0;
for(rg int j = 1;j <= 50;j++)if(b[1][j])sks++;
if(sks != 1)t13 = 0;
*/
	bool bo = 1;
	int nr = 0,nc = 0;
	for(rg int i = 1;i <= n;i++){
		int d = 0;
		for(rg int j = 1;j <= m;j++)if(b[i][j] && !b[i][j-1])d++;
		if(d >= 2)bo = 0;
		if(d == 0)nr++;
	}
//if(t13)cout <<"bo="<<bo<< " " << 1 << endl;
	for(rg int j = 1;j <= m;j++){
		int d = 0;
		for(rg int i = 1;i <= n;i++)if(b[i][j] && !b[i-1][j])d++;
		if(d >= 2)bo = 0;
		if(d == 0)nc++;
	}
//if(t13)cout<<"nr="<<nr<<" nc="<<nc<<endl;
//if(t13)cout<<"bo="<<bo<<" 2"<<endl;
	if(nr && !nc)bo = 0;
//if(t13)cout<<"bo="<<bo<<" 3"<<endl;
	if(nc && !nr)bo = 0;
//if(t13)cout<<"bo="<<bo<<" 4"<<endl;
	if(!bo)puts("-1");
	else{
		int ans = 0;
		for(rg int i = 1;i <= n;i++)
			for(rg int j = 1;j <= m;j++)if(b[i][j] && !vis[i][j]){
//if(t13)cout<<"i="<<i<<" j="<<j<<endl;
				ans++;
				bfs(i,j);
			}
		write(ans),putchar('\n');
	}
	return 0;
}