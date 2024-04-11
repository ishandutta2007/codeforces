#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define X first
#define Y second
#define rep(i,a) for(int i=0;i<(int)a;i++)
#define repp(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define fill(a,x) memset(a,x,sizeof(a))
#define foreach( gg, itit) for( typeof(gg.begin()) itit=gg.begin();itit!=gg.end();itit++ )
#define mp make_pair
#define pb push_back
#define all(s) s.begin(),s.end()
#define present(c,x) ((c).find(x) != (c).end())
typedef vector<int> VI;
const int mod  = 1e9+7;
const int N = 1e6+10;
const ll INF = 1e18;
#define E5 100005

#define ld long double
//#define double long double

const ld EPS=1e-12;

int d,s;

bool vis[5105][515];
int pa[5105][515];
int parem[5105][515];

vector<int> ans;
vector<pair<int, vector<int> > > fin;

void go(int sum, int rem, int dig, int len){
	if(len == 0){
		reverse(all(ans));
		fin.pb(mp(ans.size(),ans));
		return;
	}
	ans.pb(dig);
	int dd = pa[sum][rem];
	int remm = parem[sum][rem];
	go(sum-dig, remm, dd, len-1);
}

queue<vector<int> > qu;

void solve(int dii){
	while(not qu.empty())qu.pop();
	//memset(vis,0,sizeof(vis));
	//vis[dii][dii%d][dii]=1;
	vis[dii][dii%d]=1;
	qu.push({dii,dii%d,dii,0});
	while(not qu.empty()){
		auto vec = qu.front();
		qu.pop();
		int sum=vec[0], rem=vec[1], dig=vec[2], len=vec[3];
		if(sum > s)continue;
		if(sum>5001)continue;
		if(len > 50001)continue;
		for(int i=0;i<=9;i++){
			if(sum == 0 && i == 0)continue;
			int sumi = sum + i;
			int remi = (rem*10+i)%d;
			if(not vis[sumi][remi]){
				pa[sumi][remi]=dig;
				parem[sumi][remi]=rem;
				vis[sumi][remi]=1;
				qu.push({sumi, remi, i, len+1});
			}
			if(sumi == s && remi == 0){
				ans.clear();
				go(sumi,remi,i,len+1);
				return;
			}
		}
	}

}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	//cin>>d>>s;
	scanf("%d%d", &d, &s);
	vis[0][0]=1;
	/*
	 *for(int i=1;i<=9;i++){
	 *    solve(i);
	 *}
	 */
	solve(0);
	if(not fin.empty()){
		sort(all(fin));
		for(int i=0;i<fin[0].X;i++){
			//cout<<fin[0].Y[i];
			printf("%d", fin[0].Y[i]);
		}
		//cout<<endl;
		printf("\n");
		return 0;
	}
	cout<<"-1"<<endl;
	return 0;
}