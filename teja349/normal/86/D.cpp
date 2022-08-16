
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
struct total{
	int l,r,ind;
};
ll ans=0,N;
ll arr[1234567]={0},a[212345],anwe[212345];
total query[212345];
int add(int ind){
	//ans-=arr[a[ind]]*arr[a[ind]]*a[ind];
	//arr[a[ind]]++;
	ans+=(arr[a[ind]]*2+1)*a[ind];
	arr[a[ind]]++;
	return 0;
}


int deleted(int ind){
	//ans-=arr[a[ind]]*arr[a[ind]]*a[ind];
	arr[a[ind]]--;
	ans-=(2*arr[a[ind]]+1)*a[ind];
	return 0;
}
int comp(total a,total b){
	if(a.l/N !=b.l/N)
		return (a.l < b.l);
	return (a.r<b.r);
}
int main(){
	//std::ios::sync_with_stdio(false);
	int n,t,i,in,j;
	cin>>n>>t;
	N=2*sqrt(n);
	rep(i,n){
		scanf("%lld",&a[i]);
	}
	rep(i,t){
		scanf("%d%d",&query[i].l,&query[i].r);
		query[i].l--;
		query[i].r--;

		query[i].ind=i;
	}
	sort(query,query+t,comp);
	i=0;
	j=-1;
	rep(in,t){
		while(j<query[in].r){
			add(j+1);
			j++;
		}
		while(j>query[in].r){
			deleted(j);
			j--;
		}
		while(i<query[in].l){
			deleted(i);
			i++;
		}
		while(i>query[in].l){
			add(i-1);
			i--;
		}
		//cout<<query[in].ind<<"   ";
		anwe[query[in].ind]=ans;

	}
	//cout<<endl;
	rep(i,t){
		printf("%lld\n",anwe[i]);
	}
}