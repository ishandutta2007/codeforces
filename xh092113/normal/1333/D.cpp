#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const int N = 3000;

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

int minn,maxn;
int n,k;
char s[N+5];
bool dir[N+5];
bool temp[N+5];
vector<int>v;
vector<int>w[N*N+5];
vector<int>ans[N*N+5];

int main(){
//	freopen("D.in","r",stdin);
//	freopen("D.out","w",stdout);
	n = read(),k = read();
	scanf("%s",s + 1);
	for(rg int i = 1;i <= n;i++)dir[i] = s[i] == 'R' ? 1 : 0;
	memcpy(temp,dir,sizeof(temp));
	for(rg int i = n;i >= 1;i--){
		if(dir[i] == 0)continue;
		v.push_back(i);
		maxn += n - v.size() + 1 - i;
	}
	for(rg int i = 1;;i++){
//cout<<i<<endl;
		w[i].resize(0);
		for(rg int j = 1;j < n;j++)if(temp[j] && !temp[j+1])w[i].push_back(j);
		if(!w[i].size()){
			minn = i - 1;
			break;
		}
		for(auto j : w[i])swap(temp[j],temp[j+1]);
	}
//cout<<"minn="<<minn<<" maxn="<<maxn<<endl;
	if(k < minn || k > maxn){
		puts("-1");
		return 0;
	}
	
	int cur = minn;
	int t = 0;
	for(rg int i = 1;i <= minn;i++){
		int low = cur,high = cur + w[i].size() - 1;
//cout<<"i="<<i<<" low="<<low<<" high="<<high<<endl;
		if(high < k){
			for(rg int j = 0;j < w[i].size();j++){
				t++;
				ans[t].push_back(w[i][j]);
			}
			cur = high;
		}
		else{
			for(rg int j = 0;j < k - low;j++){
				t++;
				ans[t].push_back(w[i][j]);
			}
			t++;
			for(rg int j = k - low;j < w[i].size();j++)ans[t].push_back(w[i][j]);
			for(rg int j = i + 1;j <= minn;j++){
				t++;
				for(auto l : w[j])ans[t].push_back(l);
			}
			break;
		}
	}
	for(rg int i = 1;i <= t;i++){
		write(ans[i].size()),putchar(' ');
	 	for(auto j : ans[i])write(j),putchar(' ');
	 	putchar('\n');
	}
	/*
	vector<int>t,pret;
	t.resize(0);
	pret.resize(0);
	int cur = maxn;
	for(rg int i = 1;v[0] + i <= n;i++)pret.push_back(i);
	for(rg int i = 1;i < v.size();i++){
		int now = 0;
		
	}*/
	return 0;	
}