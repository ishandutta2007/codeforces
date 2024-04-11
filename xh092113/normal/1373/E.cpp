#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

namespace IO{
	In ll read(){
		int s = 0,ww = 1;
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

ll t,n,k;
vector<int>ans;
vector<int>cur;

bool cmp(){
	if(!ans.size())return 1;
	if(ans.size() > cur.size())return 1;
	else if(ans.size() < cur.size())return 0;
	for(rg int i = ans.size() - 1;i >= 0;i--){
		if(ans[i] > cur[i])return 1;
		else if(ans[i] < cur[i])return 0;
	}
	return 0;
}

void solve(ll s,int opt,int n9,int x){
	cur.resize(0);
	if(s < 0)return;
	cur.push_back(x);
	for(rg int i = 1;i <= n9;i++)cur.push_back(9);
	if(opt && s){
		if(s <= 8)cur.push_back(s),s = 0;
		else cur.push_back(8),s -= 8;
	}
	while(s){
		if(s <= 9)cur.push_back(s),s = 0;
		else cur.push_back(9),s -= 9;
	}
//for(rg int i = cur.size() - 1;i >= 0;i--)cout<<cur[i];cout<<endl;
	if(cmp())ans = cur;
}

int main(){
//	freopen("E.in","r",stdin);
//	freopen("E.out","w",stdout);
	
	t = read();
	while(t--){
		n = read(),k = read();
		ans.resize(0);
//cout<<endl;
		for(rg int i = 0;i <= 9 - k;i++){
			ll cur = (i + i + k) * (k + 1) / 2;
			ll res = n - cur;
			if(res % (k + 1) != 0)continue;
			solve(res / (k + 1),0,0,i);
		}
		for(rg int i = 1;i <= 17;i++)
			for(rg int x = 10 - k;x <= 9;x++){
				ll cur = (i - 1) * 9 * (10 - x) + (x + k - 9) * (x + k - 8) / 2 + (x + 9) * (10 - x) / 2;
				ll res = n - cur;
				if(res % (k + 1) != 0)continue;
				solve(res / (k + 1),1,i - 1,x);
			}
		if(!ans.size())puts("-1");
		else{
			for(rg int i = ans.size() - 1;i >= 0;i--)putchar(ans[i]+'0');
			putchar('\n');
		}
	}	
	
	return 0;
}