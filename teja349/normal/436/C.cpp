
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


int dsu[1234];
viii vec;
vii vec1;
char arr[1002][11][11];
ll total=0;


int root(int p){
	if(dsu[p]<0)
		return p;
	dsu[p]=root(dsu[p]);
	return dsu[p];
}
int merge(int p,int q){
	p=root(p);
	q=root(q);
	if(dsu[p]>dsu[q]){
		dsu[p]=q;
	}
	else if(dsu[p]<dsu[q]){
		dsu[q]=p;
	}
	else{
		dsu[q]=p;
		dsu[p]--;
	}
} 



int compute_mst(){
	int i;
	//cout<<vec.size()<<endl;	
	rep(i,vec.size()){
		//cout<<
		int x=vec[i].ss.ff;
		int y=vec[i].ss.ss;
		//cout<<root(x)<<endl;
		if(root(x)!=root(y)){
			total+=vec[i].ff;
			vec1.pb(mp(min(x,y),max(x,y)));
			merge(x,y);
		}
	}


}


int  main(){
	fill(dsu,dsu+1007,-1);
	//std::ios::sync_with_stdio(false); 
	int n,m,k,w,i,j,p,q,sum;
	cin>>n>>m>>k>>w;
	f(i,1,k+1){
		rep(j,n){
			rep(q,m){
				cin>>arr[i][j][q];
			}
		}
	}
	f(i,1,k+1){
		//cout<<"hii";
		vec.pb(mp(n*m,mp(i,0)));
		f(j,i+1,k+1){
			sum=0;
			rep(q,n){
				rep(p,m){
					if(arr[i][q][p]!=arr[j][q][p])
						sum++;
				}
			}
			//cout<<sum*w<<" "<<i<<" "<<j<<endl;
			vec.pb(mp(sum*w,mp(i,j)));
		}
	}
	//cout<<"hiii"<<endl;	
	sort(vec.begin(),vec.end());
	
	compute_mst();
	cout<<total<<endl;
	sort(vec1.begin(),vec1.end());
	int arrq[1100]={0};
	rep(i,vec1.size()){
		int x=vec1[i].ff;
		int y=vec1[i].ss;
		if(x==0){
			cout<<vec1[i].ss<<" "<<vec1[i].ff<<endl;
			arrq[y]++;
		}
		else{
			if(arrq[x]){
				cout<<y<<" "<<x<<endl;
				arrq[y]++;
			}
			else if(arrq[y]){
				cout<<x<<" "<<y<<endl;
				arrq[x]++;
			}
			else{
				vec1.pb(mp(x,y));
			}
		}
		
	}
}