
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
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx


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
bitset<1000006> b;
vi vec;
int a[1000006];
int visited[1000006]={0}; 
int cnt[1000006]={0};


int dfs(int present){
	visited[present]=1;
	if(visited[a[present]]==1)
		return 1;
	return 1+dfs(a[present]);
}



int main(){
	std::ios::sync_with_stdio(false);  
	b.reset();
	int n,k,i,val;
	cin>>n>>k;
	f(i,1,n+1){
		cin>>a[i];
	}
	f(i,1,n+1){
		if(!visited[i]){
			val=dfs(i);
			//cout<<val<<endl;
			cnt[val]++;
			vec.pb(val);
		}
	}
	int j;
	int temp;
	int sum=0;
	int flag=0;
	int mini=0;
	//sort(vec.begin(),vec.end());
	int k1=min(k,n-k);
	b.flip(0);
	rep(i,k1+1){
		if(cnt[i]==0)
			continue;
		j=1;
		
		while(cnt[i]>0){
			j=min(j,cnt[i]);
			temp=i*j;
			b|=(b<<temp);
			//cout<<b<<" "<<j<<endl;
			cnt[i]-=j;
			j*=2;
		}
	}
	//cout<<b<<endl;
	if(b[k1]==0)
		cout<<k+1<<" ";
	else 
		cout<<k<<" ";
	
	sum=0;

	rep(i,vec.size()){
		sum+=(vec[i]/2);
		mini+=vec[i]-(vec[i]%2) ;
		//cout<<sum<<endl;
		if(sum>=k){

			mini-=2*(sum-k);
			cout<<mini<<endl;
			flag=1;
			break;
		}
	}
	if(flag==0)
		cout<<min(mini+k-sum,n)<<endl;


}