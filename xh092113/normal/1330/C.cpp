#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const int N = 1e5;

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

pii seg[N+5];
int ans[N+5],suf[N+5],pre[N+5];
int n,m;

In bool cmp(pii a,pii b){
	return a.first > b.first;
}

int main(){
//	freopen("A.in","r",stdin);
//	freopen("A.out","w",stdout);
	n = read(),m = read();
	for(rg int i = 1;i <= m;i++){
		seg[i] = make_pair(read(),i);
	}
//	sort(seg + 1,seg + m + 1,cmp);
	int minn = 0;ll maxn = 0;
	for(rg int i = 1;i <= m;i++){	
		maxn += seg[i].first;
		minn = max(minn,i + seg[i].first - 1);
	}
//cout<<"minn="<<minn<<" maxn="<<maxn<<endl;
	if(n < minn || n > maxn){
		puts("-1");
		return 0;
	}
	suf[m] = seg[m].first;
	for(rg int i = m - 1;i >= 1;i--)suf[i] = max(suf[i+1] + 1,seg[i].first);
//for(rg int i = 1;i <= m;i++)cout<<suf[i]<<" ";cout<<endl;
//for(rg int i = 1;i <= 10;i++)cout<<endl;
	int cur = minn;
	pre[0] = 1;
	for(rg int i = 1;i <= m;i++){
		int loc = n - suf[i] + 1;
		if(loc > pre[i-1])ans[i] = pre[i-1],pre[i] = pre[i-1] + seg[i].first;
		else{
//cout<<"i="<<i<<" loc="<<loc<<" first="<<seg[i].first<<endl;
			ans[i] = loc;
//for(rg int j = i + 1;j <= m;j++)cout<<seg[j].first<<" ";cout<<endl;
			for(rg int j = i + 1;j <= m;j++)ans[j] = ans[j-1] + 1;
			break;
		} 
	}
	for(rg int i = 1;i <= m;i++){
		write(ans[i]);
		putchar(i == m ? '\n' : ' ');
	}
	return 0;
}