#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,k;
int dis[505];
pii opt[505];
bool vis[505];
queue<int> q;

int ask(vector<int> vec){
	printf("? ");
	for(auto r:vec) printf("%d ",r);
	printf("\n");
	fflush(stdout);
	return readint();
}

int print(int x){
	if(x==0) return 0;
	int res=print(opt[x].fi);
	vector<int> vec(0);
	int c1=opt[x].se,c2=k-c1;
	for(int i=1;i<=n;i++){
		if(vis[i]&&c1) vec.pb(i),c1--,vis[i]^=1;
		else if(!vis[i]&&c2) vec.pb(i),c2--,vis[i]^=1;
	}
	return res^ask(vec);
}

int main(){
	n=readint(); k=readint();
	memset(dis,0x3f,sizeof(dis));
	dis[0]=0;
	q.push(0);
	while(!q.empty()){
		int t=q.front(); q.pop();
		for(int i=max(0,k-(n-t));i<=min(t,k);i++)
			if(chkmin(dis[t-i+(k-i)],dis[t]+1))
				opt[t-i+(k-i)]=mp(t,i),q.push(t-i+(k-i));
	}
	if(dis[n]==0x3f3f3f3f) return printf("-1\n"),0;
	printf("! %d\n",print(n));
	return 0;
}