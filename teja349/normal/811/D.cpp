//teja349
#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx


using namespace std;
#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

//std::ios::sync_with_stdio(false);   
int m,n;
map<char,char> mapi;
pii par[150][150];
int visit[150][150];
int remema,rememb;
char arr[150][150];
vector<char> vec;
int valid(int u,int v){
	if(u==0 || u==n+1 || v==0 || v==m+1){
		return 0;
	}
	if(arr[u][v]=='*'){
		return 0;
	}
	return 1;
}
int dfs(int u,int v){
	visit[u][v]=1;
	if(arr[u][v]=='F'){
		remema=u;
		rememb=v;
	}
	if(valid(u+1,v)&& !visit[u+1][v]){
		par[u+1][v]=mp(u,v);
		dfs(u+1,v);
	}
	if(valid(u-1,v)&& !visit[u-1][v]){
		par[u-1][v]=mp(u,v);
		dfs(u-1,v);
	}
	if(valid(u,v-1)&& !visit[u][v-1]){
		par[u][v-1]=mp(u,v);
		dfs(u,v-1);
	}
	if(valid(u,v+1)&& !visit[u][v+1]){
		par[u][v+1]=mp(u,v);
		dfs(u,v+1);
	}
	return 0;

}
int moved(int &x,int &y){
	if(par[x][y].ff<x){
		x--;
		vec.pb('D');
		return 0;
	}
	if(par[x][y].ff>x){
		x++;
		vec.pb('U');
		return 0;
	}
	if(par[x][y].ss<y){
		y--;
		vec.pb('R');
		return 0;
	}
	if(par[x][y].ss>y){
		y++;
		vec.pb('L');
		return 0;
	}

}
int compute(int x,int y){
	//cout<<x<<" "<<y<<endl;
	//return 0;
	dfs(x,y);
	//return 0;
	int nx,ny;
	nx=remema;
	ny=rememb;
	while(nx!=x || ny!=y){
		//cout<<nx<<" "<<ny<<endl;
		moved(nx,ny);

	}
	int i;
	fd(i,vec.size()-1,0){
		cout<<mapi[vec[i]]<<endl;
		cin>>nx>>ny;
	}
	//exit(0);
	return 0;

}

int main(){
    std::ios::sync_with_stdio(false);
    //int n,m;
    cin>>n>>m;
    int i,j;
    f(i,1,n+1){
    	f(j,1,m+1){
    		cin>>arr[i][j];
    	}
    }
    mapi['L']='X';
    mapi['R']='X';
    mapi['U']='X';
    mapi['D']='X';
    int x=1,y=1;
    int nx,ny;
    if(m==1){
    	cout<<'D'<<endl;
    	cin>>nx>>ny;
    	if(nx==x && ny==y){
    		mapi['D']='U';
    		mapi['U']='D';
    	}
    	else{
    		mapi['D']='D';
    		mapi['U']='U';
    	}
    	x=nx;
    	y=ny;
    	if(arr[nx][ny]=='F'){
    		return 0;
    	}
    	while(1){
    		cout<<mapi['D']<<endl;
    		cin>>nx>>ny;
    		if(arr[nx][ny]=='F'){
    			return 0;
    		}
    	}

    }
    else if(n==1){
    	cout<<'R'<<endl;
    	cin>>nx>>ny;
    	if(nx==x && ny==y){
    		mapi['R']='L';
    		mapi['L']='R';
    	}
    	else{
    		mapi['R']='R';
    		mapi['L']='L';
    	}
    	x=nx;
    	y=ny;
    	if(arr[nx][ny]=='F'){
    		return 0;
    	}
    	while(1){
    		cout<<mapi['R']<<endl;
    		cin>>nx>>ny;
    		if(arr[nx][ny]=='F'){
    			return 0;
    		}
    	}
    }
    if(arr[1][2]!='*'){
    	cout<<'R'<<endl;
    	cin>>nx>>ny;
    	if(nx==x && ny==y){
    		mapi['R']='L';
    		mapi['L']='R';
    	}
    	else{
    		mapi['R']='R';
    		mapi['L']='L';
    	}
    	if(arr[nx][ny]=='F')
    	{
    		return 0;
    	}
    	cout<<mapi['L']<<endl;
    	cin>>nx>>ny;
    	while(1){
    		if(arr[nx+1][ny]!='*'){
    			cout<<'D'<<endl;
    			cin>>x>>y;
    			if(x==nx){
    				mapi['D']='U';
    				mapi['U']='D';

    			}
    			else{
    				mapi['U']='U';
    				mapi['D']='D';
    			}
    			if(arr[x][y]=='F'){
    				return 0;
    			}
    			//cout<<"lol"<<endl;
    			compute(x,y);
    			return 0;
    		}
    		else{
    			cout<<mapi['R']<<endl;
    			cin>>nx>>ny;
    			if(arr[nx][ny]=='F'){
    				return 0;
    			}
    		}


    	}

    }
    else{
    	cout<<'D'<<endl;
    	cin>>nx>>ny;
    	if(nx==x && ny==y){
    		mapi['D']='U';
    		mapi['U']='D';
    	}
    	else{
    		mapi['D']='D';
    		mapi['U']='U';
    	}
    	if(arr[nx][ny]=='F')
    	{
    		return 0;
    	}
    	cout<<mapi['U']<<endl;
    	cin>>nx>>ny;
    	while(1){
    		if(arr[nx][ny+1]!='*'){
    			cout<<'R'<<endl;
    			cin>>x>>y;
    			if(y==ny){
    				mapi['R']='L';
    				mapi['L']='R';

    			}
    			else{
    				mapi['L']='L';
    				mapi['R']='R';
    			}
    			if(arr[x][y]=='F'){
    				return 0;
    			}
    			compute(x,y);
    			return 0;
    		}
    		else{
    			cout<<mapi['D']<<endl;
    			cin>>nx>>ny;
    			if(arr[nx][ny]=='F'){
    				return 0;
    			}
    		}

    	}
    }
    


}