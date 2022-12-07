#include<bits/stdc++.h>



using namespace std;



#define rg register

#define In inline

#define ll long long

#define rep(i,l,r) for(rg int i = (l);i <= (r);i++)

#define dwn(i,r,l) for(rg int i = (r);i >= (l);i--)

#define mp make_pair

#define pb push_back

#define fi first

#define se second



namespace IO{

	In char gc(){

		static char buf[100000],*p1 = buf,*p2 = buf;

		if(p1 == p2)p2 = buf + fread(p1 = buf,1,100000,stdin);

		return p1 == p2 ? EOF : *p1++;

	}

	In ll read(){

		ll s = 0,ww = 1;

		char ch = gc();

		while(ch < '0' || ch > '9'){if(ch == '-')ww = -1;ch = gc();}

		while('0' <= ch && ch <= '9'){s = 10 * s + ch - '0';ch = gc();}

		return s * ww;

	}

	In void write(ll x){

		if(x < 0)putchar('-'),x = -x;

		if(x > 9)write(x / 10);

		putchar('0' + x % 10);

	}

};

using namespace IO;


const int N = 20;
typedef pair<int,int> pii;


template<typename T> void chkmin(T &x,T y){if(y < x)x = y;}

template<typename T> void chkmax(T &x,T y){if(y > x)x = y;}

int h,w,top;
bool vis[N+5][N+5];	
pii p[N*N+5];
int mx[8] = {-1,-1,0,1,1,1,0,-1};
int my[8] = {0,-1,-1,-1,0,1,1,1};

In int check(int st){
	int ans = 0;
	memset(vis,0,sizeof(vis));
	rep(i,st,top){
		bool bo = 1;
		rep(j,0,7)if(vis[p[i].fi+mx[j]][p[i].se+my[j]])bo = 0;
		if(bo == 1)ans++,vis[p[i].fi][p[i].se] = 1;
	}
	return ans;
}
In void print(int st){
	check(st);
	rep(i,1,h){
		rep(j,1,w)putchar('0'+vis[i][j]);putchar('\n');
	}
	putchar('\n');
}
void solve(){
	h = read(),w = read();
	top = 0;
	rep(i,1,w - 1)p[++top] = mp(1,i);
	rep(i,1,h - 1)p[++top] = mp(i,w);
	dwn(i,w,2)p[++top] = mp(h,i);
	dwn(i,h,2)p[++top] = mp(i,1);
//rep(i,1,top)cout<<p[i].fi<<" "<<p[i].se<<endl;
//cout<<endl;
	int ans = 0,pos = 0;
	rep(i,1,3){
		int cur = check(i);
		if(cur > ans)ans = cur,pos = i;
	}
	print(pos);
}


int main(){

//	freopen("B.in","r",stdin);
//	freopen("B.out","w",stdout);
	int Tc = read();
	while(Tc--)solve();	

	return 0;

}