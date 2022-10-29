#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define CL(a,x) memset(a, x, sizeof(a))
#define MP make_pair
#define PB push_back
#define PII pair<int, int>
typedef long long LL;
const LL P = 998244353;
const int N = 1005;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n=666,k,x1,y1,x[N],y[N];
int dx[]={0,-1,-1,-1, 0, 0, 1, 1, 1};
int dy[]={0,-1, 0, 1,-1, 1,-1, 0, 1};
bool v[N][N];

int which(int x,int y,int x0,int y0){
	if(x==x0 && y==y0) return cout<<"???\n", 0;
	if(y0==y){
		return x0<x ? 2 : 7; 
	}else if(x0<x){
		return y0<y ? 1 : 3;
	}else if(x0==x){
		return y0<y ? 4 : 5;
	}else if(x0>x){
		return y0<y ? 6 : 8;
	}
	cout<<"???\n";
}

int main(){
	//freopen("test.in","r",stdin);
	ios_base::sync_with_stdio(false);cin.tie(nullptr); 
	cin>>x1>>y1;
	memset(v,false,sizeof v);
	rep(i,1,n) cin>>x[i]>>y[i], v[x[i]][y[i]] = true;
	while(x1!=500 || y1!=500){
		int z = which(x1, y1, 500, 500);
		int fx = dx[z], fy = dy[z];
		if(v[x1+fx][y1+fy]){
			x1 += fx;
		}else{
			x1 += fx, y1 += fy;
		}
		cout<<x1<<" "<<y1<<endl<<flush;
		
		int newx, newy;
		cin>>k>>newx>>newy;
		if(k==-1) return 0;
		v[x[k]][y[k]] = false;
		x[k] = newx, y[k] = newy;
		v[x[k]][y[k]] = true;
	}
	
	int cnt[4];
	memset(cnt,0,sizeof cnt);
	rep(i,1,n){
		cnt[(x[i]>500)*2+(y[i]>500)]++;
	}
	int j = min_element(cnt,cnt+4) - cnt, z;
	//cout<<cnt[0]<<" "<<cnt[1]<<" "<<cnt[2]<<" "<<cnt[3]<<" "<<j<<endl;
	if(j==0) z=8;
	if(j==1) z=6;
	if(j==2) z=3;
	if(j==3) z=1;
	int fx = dx[z], fy = dy[z];
	while(true){
		if(v[x1+fx][y1+fy]){
			x1 += fx;
		}else{
			x1 += fx, y1 += fy;
		}
		cout<<x1<<" "<<y1<<endl<<flush;
		
		int newx, newy;
		cin>>k>>newx>>newy;
		if(k==-1) return 0;
		v[x[k]][y[k]] = false;
		x[k] = newx, y[k] = newy;
		v[x[k]][y[k]] = true;
	}
	return 0;
}