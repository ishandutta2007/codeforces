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
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val
 
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
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
#define flush fflush(stdout) 
#define primeDEN 727999983
#define int ll 


int bit[512345];
int update(int pos,int val){
	pos++;
	while(pos<512345){
		bit[pos]+=val;
		pos+=pos&(-pos);
	}
	return 0;
} 
int query(int pos){
	pos++;
	int ans=0;
	while(pos>0){
		ans+=bit[pos];
		pos-=pos&(-pos);
	}
	return ans;
}
int a[512345],p[512345],dp[512345],b[512345],pre[512345];
int foo[512345],pfoo[512345];
vector<vi> vec(512345);
signed main(){
	std::ios::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin>>n;
	int i;
	f(i,1,n+1){
		cin>>a[i];
		vec[a[i]].pb(i);
	}
	f(i,1,n+1){
		cin>>p[i];
		if(p[i]<0){
			
			foo[i]=p[i];
			p[i]=0;
		}
	}
	f(i,1,n+1){
		pfoo[i]=pfoo[i-1]+foo[i];
	}
	int m;
	cin>>m;
	rep(i,m){
		cin>>b[i];
	}
	b[m]=inf;
	int j=0;
	f(i,1,n+1){
		if(b[j]==a[i])
			j++;
	}
	if(j!=m){
		cout<<"NO"<<endl;
		return 0;
	}
	int gg=m-1;
	fd(i,n,1){
		if(gg>=0 && b[gg]==i){
			if(gg==m-1){
				rep(j,vec[i].size()){
					if(gg==m-1){
						dp[vec[i][j]]=query(n)-query(vec[i][j])+pfoo[n]-pfoo[vec[i][j]];
					}
				}
			}
			else{
				int k=vec[b[gg+1]].size();
				j=vec[i].size();
				k--;
				j--;
				int mini=inf;
				mini*=inf;
				while(j>=0){
					if(k>=0 && vec[b[gg+1]][k]>vec[i][j]){
						int ind=vec[b[gg+1]][k];
						mini=min(mini,dp[ind]+query(ind-1)+pfoo[ind-1]);
						k--;
						continue;
					}
					// if(gg==0){
					// 	cout<<vec[i][j]<<" "<<foo[vec[i][j]]<<endl;
					// }
					//cout<<mini<<endl;
					dp[vec[i][j]]=mini-query(vec[i][j])-pfoo[vec[i][j]];
					j--;
				}
			}
			gg--;
		}
		rep(j,vec[i].size()){
			update(vec[i][j],p[vec[i][j]]);
			//cout<<query(vec[i][j])<<endl;
		}
	}
	cout<<"YES"<<endl;
	pre[0]=0;
	f(i,1,n+1){
		pre[i]=pre[i-1]+p[i];
	}
	int ans=inf;
	ans*=inf;
	rep(j,vec[b[0]].size()){
		int ind=vec[b[0]][j];
		//cout<<dp[ind]<<endl;
		ans=min(dp[ind]+pre[ind-1]+pfoo[ind-1],ans);
	}
	cout<<ans<<endl;
}