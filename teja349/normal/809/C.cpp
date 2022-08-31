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

ll compute(ll x,ll y,ll k){
	if(x<0 || y<0){
		return 0;
	}
	//cout<<"hii "<<x<<" "<<y<<endl;
	int i,j,jiji,jaja;
	ll arr1[50]={0},arr2[50]={0},value1;
	fd(i,31,0){
		arr1[i]=arr1[i+1]+(x&(1LL<<i));
		arr2[i]=arr2[i+1]+(y&(1LL<<i));
	}
	ll biga,value,sumi=0,ans1,ans2;
	fd(i,31,-1){
		if(i!=-1 && !(x&(1LL<<i))){
			continue;
		}
		//cout<<(x&(1LL<<i))<<" "<<i<<" "<<x<<endl;
		fd(j,31,-1){
			if(j!=-1 && !(y&(1LL<<j))){
				continue;
			}
			//cout<<"boo"<<endl;
			jiji=max(j,i);
			jaja=min(j,i);
			if(jiji==i){
				ans1=arr1[i+1];
				//cout<<i+1<<"   "<<arr1[i+1]<<" ";
			}
			else{
				ans1=arr1[jiji];
			}
			if(jiji==j){
				ans2=arr2[j+1];
			}
			else{
				ans2=arr2[jiji];
				//cout<<jiji<<"   "<<arr2[jiji]<<" ";
			}

			biga=ans2^ans1;
			value=k-biga;
			biga=max(biga,(ll)0);
			//cout<<biga<<endl;
			biga%=mod;
			if(jiji==-1){
				jiji=0;
			}
			value=min(value,((1LL<<jiji)-1));
			value++;
			//cout<<biga<<" ";
			value=max(value,(ll)0);
			biga*=value;
			biga%=mod;
			value1=value;
			value--;
			//cout<<value<<endl;
			value*=(value+1);
			value/=2;

			value%=mod;
			jaja=max(jaja,0);
			value*=(1LL<<jaja);
			biga*=(1LL<<jaja);
			value1*=(1LL<<jaja);
			value1%=mod;
			biga%=mod;
			value%=mod;
			sumi+=value;
			sumi+=biga;
			sumi+=value1;
			sumi%=mod;
			//ans2+=(1LL<<j);
			//cout<<value<<" "<<i<<" "<<j<<" "<<sumi<<endl;
		}

		//ans1+=(1LL<<i);
	}
	//cout<<sumi<<endl;
	return sumi;
}
int main(){
    std::ios::sync_with_stdio(false);
    int q;
    cin>>q;
    while(q--){
    	ll x1,x2,y1,y2,k;
    	cin>>x1>>y1>>x2>>y2>>k;
    	x2--;
    	x1--;
    	y1--;
    	y2--;
    	k--;
    	ll ans=compute(x2,y2,k)-compute(x2,y1-1,k)-compute(x1-1,y2,k)+compute(x1-1,y1-1,k);
    	ans%=mod;
    	ans+=mod;
    	ans%=mod;
    	cout<<ans<<endl;

    }
    
}