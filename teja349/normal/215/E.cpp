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
ll computebit(ll num){
	ll haha=0;
	while(num>0){
		haha++;
		num/=2;
	}
	return haha;
} 


int checker(ll val,ll repbit,ll num,ll reach){
	ll poss =computebit(val);
	if(poss*repbit<reach){
		return 1;
	}
	if(poss*repbit>reach){
		return 0;
	}
	ll ans=0;
	ll poss1=0;
	while(repbit>0){
		ans+=(val<<poss1);
		poss1+=poss;
		repbit--;
	}
	return (ans<=num);



}
int binser(ll repbit,ll num,ll reach){
	
	ll low=1;
	ll high=num;
	ll mid=(low+high)/2;
	ll ans=0;
	while(low<=high){
		if(checker(mid,repbit,num,reach)){
			ans=mid;
			low=mid+1;
		}
		else{
			high=mid-1;
		}
		mid=(high+low)/2;
	}
	return ans;
}
int prime[200];
ll compute(ll num){
	int i,j;
	ll ans=0;
	int arr[200]={0};
	ll reach=computebit(num);
	f(i,2,100){
		//cout<<i<<endl;
		
		

		int val=binser(i,num,reach);
		if(val==0)
			break;
		//cout<<prime[i]<<" "<<val<<endl;
			int haha=1-arr[i];
			ans+=haha*val;
			for(j=2*i;j<100;j+=i){
				arr[j]+=haha;
				// if(j==8){
				// 	cout<<i<<" "<<haha<<endl;
				// }
			}

			
		
		

	}
	return ans;

}
int initprim(){
	int i,j;
	int arr[200]={0};
	for(i=2;i<102;i++){
		if(arr[i])
			continue;
		for(j=i*2;j<102;j+=i){

			arr[j]=1;
			
				
				prime[j]++;
			
		}
	}
	//cout<<prime[4]<<endl;
	return 0;
}
int main(){
	std::ios::sync_with_stdio(false);
	//initprim();
	ll l;
	ll r;
	cin>>l>>r;
	ll ans1=0;
	ans1=compute(l-1);
	//cout<<"dadssd    "<<ans1<<endl;
	ll ans2=compute(r);
	cout<<ans2-ans1<<endl;

}