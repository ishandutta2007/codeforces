#include <bits/stdc++.h>
using namespace std;


#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void pre(){


}

void solve(){


}
int q(int x1,int y1,int x2,int y2){
	cout<<"? "<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
	int x;cin>>x;
	assert(x!=-1);
	return x;
}
int a[109][109];
int dx[6] = {2,0,-1,-2,0,1};
int dy[6] = {0,-2,-1,0,2,1};
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n;cin>>n;
	repA(i,1,n) repA(j,1,n) a[i][j] = -1;
	a[1][1]= 1,a[n][n] = 0;
	repA(i,2,n){
		if(i%2){
			int x = q(1,i-2,1,i);
			if(x==0) a[1][i] = 1-a[1][i-2];
			else a[1][i] = a[1][i-2];
		}
	}
	repA(j,2,n){
		repA(i,1,n){
			if(i==n&&j==n) continue;
			if((i+j)%2==0){
				if(j==2){
					int x = q(j-1,i-1,j,i);
					if(x==0) a[j][i] = 1-a[j-1][i-1];
					else a[j][i] = a[j-1][i-1];
				}
				else{
					int x = q(j-2,i,j,i);
					if(x==0) a[j][i] = 1-a[j-2][i];
					else a[j][i] = a[j-2][i];
				}
			}
		}
	}
	queue<pii> v;
	repA(i,2,n-1){
		if(a[i-1][i-1]!=a[i+1][i+1]){
			int x = q(i-1,i,i,i+1);
			if(x==0){
				if(a[i-1][i-1]!=a[i][i]){
					int y = q(i-1,i-1,i,i+1);
					if(y){
						a[i][i+1] = a[i-1][i-1];
						a[i-1][i] = 1-a[i][i+1];		
					}
					else {
						a[i][i+1] = 1-a[i-1][i-1];
						a[i-1][i] = 1-a[i][i+1];		
					
					}
				}
				else{
					int y = q(i-1,i,i+1,i+1);
					if(y){
						a[i-1][i] = a[i+1][i+1];
						a[i][i+1] = 1-a[i-1][i];
					}
					else{
						a[i-1][i] = 1-a[i+1][i+1];
						a[i][i+1] = 1-a[i-1][i];
					}
				}
			}
			else{
				if(a[i-1][i-1]==a[i][i]){
					int y = q(i-1,i-1,i,i+1);
					if(y){
						a[i][i+1] = a[i-1][i-1];
						a[i-1][i] = a[i][i+1];		
					}
					else {
						a[i][i+1] = 1-a[i-1][i-1];
						a[i-1][i] = a[i][i+1];		
					
					}
				}
				else{
					int y = q(i-1,i,i+1,i+1);
					if(y){
						a[i-1][i] = a[i+1][i+1];
						a[i][i+1] = a[i-1][i];
					}
					else{
						a[i-1][i] = 1-a[i+1][i+1];
						a[i][i+1] = a[i-1][i];
					}
				}
			
			}
			v.push(mp(i-1,i));
			v.push(mp(i,i+1));
			break;
		}
	}
	while(!v.empty()){
		pii z = v.front();
		v.pop();
		rep(j,6){
			pii y = z;
			y.fst+=dx[j],y.snd+=dy[j];
			if(y.fst>=1&&y.snd>=1&&y.fst<=n&&y.snd<=n&&a[y.fst][y.snd]==-1){
				if(y.fst<=z.fst&&y.snd<=z.snd){
					int x = q(y.fst,y.snd,z.fst,z.snd);
					if(x==0) a[y.fst][y.snd] = 1-a[z.fst][z.snd];
					else a[y.fst][y.snd] = a[z.fst][z.snd];
					v.push(y);
				}
				else if(y.fst>=z.fst&&y.snd>=z.snd){
					int x = q(z.fst,z.snd,y.fst,y.snd);
					if(x==0) a[y.fst][y.snd] = 1-a[z.fst][z.snd];
					else a[y.fst][y.snd] = a[z.fst][z.snd];
					v.push(y);
				
				}
			}
		}
	}
	cout<<"!\n";
	repA(i,1,n){
		repA(j,1,n) {
			assert(a[i][j]==1||a[i][j]==0);
			cout<<a[i][j];
		}
		cout<<'\n';
	}
	cout<<endl;
	return 0;
}