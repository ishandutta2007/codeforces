#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define PB push_back
typedef long long LL;
const LL MOD = 998244353;
const LL INF = 1e17;
const int N = 100010;

int n,cnt=0,flip[300],from[3000],a[N];
vector<int> c[N],q,w;

bool check(int n, int to){
	int cnt=0;
	rep(x,0,n-1)rep(y,x+1,n-1){
		int z=y*2-x;
		if(z>=n)break;
		flip[++cnt]=(1<<x)+(1<<y)+(1<<z);
	}
	queue<int> reach;
	memset(from,-1,sizeof(from));
	reach.push(0);from[0]=0;
	while(!reach.empty()){
		int x = reach.front();
		reach.pop();
		rep(i,1,cnt){
			int y=x^flip[i];
			if(from[y]<0){
				reach.push(y);
				from[y]=x;
			}
		}
	}
	return from[to]>=0;
}

outans(int to){
	cout<<"YES\n";
	for(++cnt;to;to=from[to],++cnt)
		rep(i,0,11)if((to^from[to])>>i&1)c[cnt].PB(i+1);
	--cnt;
	cout<<cnt<<endl;
	rep(i,1,cnt)cout<<c[i][0]<<" "<<c[i][1]<<" "<<c[i][2]<<endl;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n;
	rep(i,1,n)cin>>a[i];
	if(n<=11){
		int to=0;
		rep(i,1,n)to+=a[i]?(1<<i-1):0;
		check(n,to) ? outans(to) : puts("NO\n");
	}else{
		while(n>11){
			int x = (a[n-2]<<2)+(a[n-1]<<1)+a[n];
			if(x!=3){
				q.clear();
				if(x==1)q={n-6,n-3,n};
				if(x==2)q={n-5,n-3,n-1};
				if(x==4)q={n-4,n-3,n-2};
				if(x==5)q={n-4,n-2,n};
				if(x==6)q={n-3,n-2,n-1};
				if(x==7)q={n-2,n-1,n};
				if(x)++cnt;
				for(auto e:q)c[cnt].PB(e),a[e]=1-a[e];
				n -= 3;
			}else{
				int y = (a[n-5]<<2)+(a[n-4]<<1)+a[n-3];
				q.clear();w.clear();
				if(y==0)q={n-2,n-1,n},w={n-10,n-6,n-2};
				if(y==1)q={n-6,n-3,n},w={n-11,n-6,n-1};
				if(y==2)q={n-8,n-4,n},w={n-11,n-6,n-1};
				if(y==3)q={n-2,n-1,n},w={n-4,n-3,n-2};
				if(y==4)q={n-10,n-5,n},w={n-11,n-6,n-1};
				if(y==5)q={n-6,n-3,n},w={n-9,n-5,n-1};
				if(y==6)q={n-8,n-4,n},w={n-9,n-5,n-1};
				if(y==7)q={n-8,n-4,n},w={n-5,n-3,n-1};
				++cnt;
				for(auto e:q)c[cnt].PB(e),a[e]=1-a[e];
				++cnt;
				for(auto e:w)c[cnt].PB(e),a[e]=1-a[e];
				n -= 6;
			}
		}
		n = 11;
		int to=0;
		rep(i,1,n)to+=a[i]?(1<<i-1):0;
		check(n, to);
		outans(to);
	}
	return 0;
}