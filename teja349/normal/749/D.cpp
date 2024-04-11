
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
vector<vi> vec(200002);
vi vectu,vectord;
vi::iterator it1,it2;
vii arr(200100,mp(0,0));
int countingt(int val1,int val2,int alue){
	it1=upper_bound(vec[alue].begin(),vec[alue].end(),val1);
	it2=lower_bound(vec[alue].begin(),vec[alue].end(),val2);
	return it2-it1;
}

int main(){
	std::ios::sync_with_stdio(false); 
	int n,u,v,i,j;
	cin>>n;
	rep(i,n){
		cin>>u>>v;
		vec[u].pb(v);
		vectu.pb(v);
		arr[u]=mp(i+1,u);
	}

	sort(arr.begin(),arr.begin()+n+1);
	rep(i,n+1){
		if(arr[i].ff!=0)
			break;
	}
	while(i<n+1){
		vectord.pb(arr[i].ss);
		i++;
	}



	int q;
	cin>>q;
	//cout<<"hii"<<endl;
	while(q--){
		//cout<<"hii"<<endl;
		int k,ans=-1,rem[200100];
		set<int> set1;
		cin>>k;
		rep(i,k){
			cin>>rem[i];
			set1.insert(rem[i]);

		}
		

		fd(i,vectord.size()-1,0){
			if(set1.find(vectord[i])==set1.end()){
				
				ans=vectord[i];
				break;
			}

		}
		//cout<<"ssfdsfd"<<ans<<endl;
		fflush(stdout);

		if(ans==-1){
			cout<<0<<" "<<0<<endl;
			continue;
		}
		i=vec[ans].size();
		i--;
		//int val2=vec[ans][i];
		int answer=0,low=0,high=i-1,mid;
		while(low<=high){
			mid=(low+high)/2;
			//int val1=vec[ans][i];

			int val2=vec[ans][i];
			int val1=vec[ans][mid];
			int sumi=0;
			rep(j,k){
				sumi+=countingt(val1,val2,rem[j]);
			}
			sumi+=countingt(val1,val2,ans);
			it1=upper_bound(vectu.begin(),vectu.end(),val1);
			it2=lower_bound(vectu.begin(),vectu.end(),val2);
			sumi=it2-it1-sumi;
			if(sumi!=0){
				answer=mid+1;
				low=mid+1;
			}
			else{
				high=mid-1;
			}
			//i--;
		}
		cout<<ans<<" "<<vec[ans][answer]<<endl;
		

	}

}