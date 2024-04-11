#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const int T = 400;
const int N = 2e5;

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
};
using namespace IO;

int n,D,a[N+5],num[N+5],front[2*N+5];
vector<int> pos[N+5];

In void chkmax(int &x,int y){if(y > x)x = y;}
vector<int> vc;
int solve1(int x){
	memset(front,-1,sizeof(front));
	front[N] = 0;
	int sum = 0,rt = 0;
	vc.resize(0);
	for(rg int i = 1;i <= n;i++)if(a[i] == D || a[i] == x)vc.push_back(i);
	int t = vc.size();vc.push_back(n + 1);
	for(rg int i = 0;i < t;i++){
		if(a[vc[i]] == D)sum++;else sum--;
		if(front[sum+N] == -1)front[sum+N] = vc[i];
		else chkmax(rt,vc[i+1] - 1 - front[sum+N]);
	}
//cerr<<"solve1: x="<<x<<" rt="<<rt<<endl;
	return rt;
}

int nx[N+5],L[N+5],R[N+5],numL[N+5],numR[N+5];
In void move(int &l,int &r){
	if(r > n)return;
	l = r + 1;
	if(l == n + 1)r = n + 1;
	else r = nx[l] - 1;
}
int solve2(int A){
	int rt = 0;
	for(rg int i = 1;i <= N;i++){
		if(pos[i].size() <= A)L[i] = R[i] = n + 1;
		else L[i] = pos[i][A-1],R[i] = pos[i][A] - 1;
	}
//cout<<"L[] & R[]:"<<endl;
//for(rg int i = 1;i <= n;i++)cout<<L[i]<<" "<<R[i]<<endl;
	int minL = n + 1,minR = n + 1;
	memset(numL,0,sizeof(numL));
	memset(numR,0,sizeof(numR));
	for(rg int i = 1;i <= N;i++)if(i != D){
		minL = min(minL,L[i]);
		minR = min(minR,R[i]);
		if(L[i] <= n)numL[L[i]]++;
		if(R[i] <= n)numR[R[i]]++;
	}
	for(rg int l = 1;l <= n && L[D] <= n;l++){
		if(l != 1){
			int x = a[l-1];
			if(x == D){move(L[x],R[x]);if(L[x] == n + 1)break;}
			else{
				if(L[x] != n + 1){
					numL[L[x]]--;
					numR[R[x]]--;
					move(L[x],R[x]);
					if(L[x] <= n)numL[L[x]]++;
					if(R[x] <= n)numR[R[x]]++;
				}
				while(!numL[minL] && minL <= n)minL++;
				while(!numR[minR] && minR <= n)minR++;
			}	
		}
//cerr<<"l="<<l<<endl;
//for(rg int i = 1;i <= n;i++)cerr<<"i="<<i<<" L="<<L[i]<<" R="<<R[i]<<endl;
//cout<<"rt:::::::::"<<rt<<endl;
//cout<<"minL="<<minL<<" minR="<<minR<<endl;
		if(minR >= L[D] && minL <= R[D])chkmax(rt,min(minR,R[D]) - l + 1);
	}
//cerr<<"solve2: A="<<A<<" rt="<<rt<<endl;
	return rt;
}

int main(){
//	freopen("CF1447F2.in","r",stdin);
//	freopen("CF1447F2.out","w",stdout);
	n = read();
//cout<<n<<endl;
	for(rg int i = 1;i <= n;i++){
		a[i] = read();
		num[a[i]]++;
		if(pos[a[i]].size())nx[pos[a[i]][pos[a[i]].size()-1]] = i;
		pos[a[i]].push_back(i);
	}
	for(rg int i = 1;i <= N;i++){
		if(pos[i].size())nx[pos[i][pos[i].size()-1]] = n + 1;
		pos[i].push_back(n + 1);
	}
//for(rg int i = 1;i <= n;i++)cerr<<nx[i]<<" ";cerr<<endl;	
	int ans = 0;
	for(rg int i = 1;i <= N;i++)if(num[i] > num[D])D = i;
	for(rg int i = 1;i <= n;i++)if(i != D && num[i] > T)chkmax(ans,solve1(i));
	for(rg int i = 1;i <= T;i++)chkmax(ans,solve2(i));
// here need changing
	write(ans),putchar('\n');
	return 0;
}