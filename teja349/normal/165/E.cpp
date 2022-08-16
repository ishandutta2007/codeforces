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
vector < vi > seti(100);  
int haha[(1<<22)+10],a[1234567]; 
int hushhush(int val){
	int i=21,lolo;
	while(i>=0){
		if(val&(1<<i)){
			i--;
			continue;
		}
		lolo=val+(1<<i);
		//set1.insert(lolo);
		if(!haha[lolo])
			haha[lolo]=haha[val];
		i--;
	}
	return 0;
}
int boo(int val){
	int i=21;
	int ans=0;
	while(i>=0){
		if(val&(1<<i))
			ans++;
		i--;
	}
	return ans;
}
int main(){
    //std::ios::sync_with_stdio(false);
    int n,i;
    //cin>>n;
    scanf("%d",&n);
    rep(i,n){
    	//cin>>a[i];
    	scanf("%d",&a[i]);
    	haha[a[i]]=a[i];
    }
    int val=(1<<22);
    val--;
    //seti.insert(0);
    vector<int>::iterator it;
    rep(i,(1<<22)){
    	seti[boo(i)].pb(i);
    }
   // return 0;
    i=0;
    while(!seti[i].empty()){
    	for(it=seti[i].begin();it!=seti[i].end();it++){
    		//cout<<*it<<" ";
    		hushhush(*it);
    	}
    	//cout<<endl;
    	//seti.clear();
    	// for(it=set1.begin();it!=set1.end();it++){
    	// 	seti.insert(*it);
    	// }
    	//set1.clear();
    	i++;
    }
    //cout<<haha[90]<<endl;
    rep(i,n){
    	if(haha[(val^a[i])]){
    		//cout<<haha[(val^a[i])]<<endl;
    		printf("%d\n",haha[(val^a[i])]);
    	}
    	else
    		//cout<<-1<<endl;
    		printf("-1\n");
    }




    return 0;  
    
}