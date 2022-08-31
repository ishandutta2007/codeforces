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
vi prim;
map<int,int> mapi;
set<int> booo;
set<int>::iterator it;

int factorize(int val){
	int i;
	rep(i,prim.size()){
		if(prim[i]*prim[i]>val)
			break;
		while(val%prim[i]==0){
			mapi[prim[i]]++;
			booo.insert(prim[i]);
			val/=prim[i];
		}
	}
	if(val!=1){
		mapi[val]++;
		booo.insert(val);
	}
	return 0;
}
int pr[123459];
vi fact;
int req[100];
int a[123456];
int lol[123456][16];
int papa[100],match=0;
int add(int ind){

	int i;
	rep(i,fact.size()){
		if(papa[i]<req[i]){
			papa[i]+=lol[ind][i];
			if(papa[i]>=req[i])
				match++;
		}
		else{
			papa[i]+=lol[ind][i];
		}
	}
	//cout<<lol[ind][0]<<endl;
	return 0;
}
int remover(int ind){
	int i;
	rep(i,fact.size()){
		if(papa[i]>=req[i]){
			papa[i]-=lol[ind][i];
			if(papa[i]<req[i])
				match--;
		}
		else{
			papa[i]-=lol[ind][i];
		}
	}
	return 0;
}
int main(){
    std::ios::sync_with_stdio(false);
    ll n,k;
    cin>>n>>k;
    if(k==1){
    	cout<<n*(n+1)/2<<endl;
    	return 0;
    }
    int i,j;
    for(i=2;i*i<=123456;i++){
    	if(pr[i])
    		continue;
    	for(j=i*i;j<=123456;j+=i){
    		pr[j]=1;
    	}
    }
    for(i=2;i<=123456;i++){
    	if(!pr[i])
    		prim.pb(i);
    }
    factorize(k);
    for(it=booo.begin();it!=booo.end();it++){
    	fact.pb(*it);

    }
    rep(i,fact.size()){
    	req[i]=mapi[fact[i]];
    }
    rep(i,n){
    	cin>>a[i];
    	rep(j,fact.size()){
    		while(a[i]%fact[j]==0){
    			lol[i][j]++;
    			a[i]/=fact[j];
    		}
    	}
    	
    }
    i=0;
    j=0;
    //int match=0;
    //cout<<req[0]<<endl;
    ll ans=0;
    while(1){
    	//cout<<match<<endl;
    	if(match==fact.size()){
    		//cout<<i<<" "<<n-j+1<<endl;
    		ans+=n-j+1;
    		remover(i);
    		i++;
    		continue;
    	}
    	if(j==n)
    		break;
    	add(j);
    	j++;

    }
    cout<<ans<<endl;
    return 0;


}