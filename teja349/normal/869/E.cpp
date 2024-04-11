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
ll bit[2704][2704],bitw[2704][2704];
int bitupdate(int x,int y,int val){
	while(y<2700){
		bit[x][y]+=val;
		y+=y&(-y);
	}
	return 0;
}  
int update(int x,int y,int val){
	while(x<2700){
		bitupdate(x,y,val);
		x+=x&(-x);
	}
	return 0;
}
ll bitq(int x,int y){
	ll ans=0;
	while(y>0){
		ans+=bit[x][y];
		y-=y&(-y);
	}
	return ans;
}
ll query(int x,int y){
	ll ans=0;
	while(x>0){
		ans+=bitq(x,y);
		x-=x&(-x);
	}

	return ans;
}
int bitupdate1(int x,int y,int val){
	while(y<2700){
		bitw[x][y]+=val;
		y+=y&(-y);
	}
	return 0;
}  
int update1(int x,int y,int val){
	while(x<2700){
		bitupdate1(x,y,val);
		x+=x&(-x);
	}
	return 0;
}
ll bitq1(int x,int y){
	ll ans=0;
	while(y>0){
		ans+=bitw[x][y];
		y-=y&(-y);
	}
	return ans;
}
ll query1(int x,int y){
	ll ans=0;
	while(x>0){
		ans+=bitq1(x,y);
		x-=x&(-x);
	}

	return ans;
}
int main(){
    //std::ios::sync_with_stdio(false);
    int n,m,q;
    //cin>>n>>m>>q;
    scanf("%d",&n);
    scanf("%d",&m);
    scanf("%d",&q);
    int i,r1,c1,r2,c2,j;
    rep(i,q){
    	int t;
    	scanf("%d",&t);
    	//cin>>r1>>c1>>r2>>c2;
    	scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
    	int val1,val2;
    	if(t==1){
    		update(r1,c1,1);
    		update(r1,c2+1,-1);
    		update(r2+1,c1,-1);
    		update(r2+1,c2+1,1);
    		val1=(r1+213)*(c1+497);
    		val2=(r2+213)*(c2+497);
    		val1+=val2;
    		update1(r1,c1,val1);
    		update1(r1,c2+1,-1*val1);
    		update1(r2+1,c1,-1*val1);
    		update1(r2+1,c2+1,1*val1);

    	}
    	else if(t==2){
    		update(r1,c1,-1);
    		update(r1,c2+1,1);
    		update(r2+1,c1,1);
    		update(r2+1,c2+1,-1);
    		val1=(r1+213)*(c1+497);
    		val2=(r2+213)*(c2+497);
    		val1+=val2;
    		//val1%=547;
    		update1(r1,c1,-1*val1);
    		update1(r1,c2+1,1*val1);
    		update1(r2+1,c1,1*val1);
    		update1(r2+1,c2+1,-1*val1);
    	}
    	else{
    		// f(i,1,n+1){
    		// 	f(j,1,m+1){
    		// 		cout<<query(i,j)<<" ";
    		// 	}
    		// 	cout<<endl;
    			
    		// }
    		//return 0;
    		if(query(r1,c1)==query(r2,c2) && query1(r1,c1)==query1(r2,c2))
    			printf("Yes\n");
    		else
    			printf("No\n");
    	}
    }
    return 0;  
    
}