//raja1999
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
//setbase - cout << setbase (16)a; cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 <<endl;prints xxx77
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

vl v;
ll a[500010],a1[200010],c[500010];
//vector< set<ll > >se(500010);
ll cnt[500005];
ll get(ll x){
	while(x>0){
		if(a[x]==0&&x!=1){
			v.pb(x);
		}
		if(a[x]==0){
			break;
		}
		v.pb(a[x]);
		x/=a[x];
	}
}
ll compute(ll x){
	ll j=0,ans=0,res=1,i;
	vi v1;
	while(x>0){
		if(x%2){
			v1.pb(j);
		}
		j++;
		x/=2;
	}
	rep(i,v1.size()){
		res*=v[v1[i]];
	}
	ans=cnt[res];
	if(v1.size()%2){
		return ans;
	}
	return -1LL*ans;
}

ll add_elem(ll x,ll y){
	ll j=0,res=1;
	while(y>0){
		if(y%2){
			res*=v[j];
		}
		j++;
		y/=2;
	}
	cnt[res]++;
}

ll remove_elem(ll x,ll y){
	ll j=0,res=1;
	while(y>0){
		if(y%2){
			res*=v[j];
		}
		j++;
		y/=2;
	}
	cnt[res]--;
}
ll add(ll x){
	ll i,val;
	val=(1LL<<v.size());
	f(i,1,val){
		add_elem(x,i);
	}
}
ll remove(ll x){
	ll i,val;
	val=(1LL<<v.size());
	f(i,1,val){
		remove_elem(x,i);
	}
}
int main(){
	//std::ios::sync_with_stdio(false);
	int n,q,i,j,x;
	ll fin=0,val,pres=0,ans=0;
	scanf("%d%d",&n,&q);
	rep(i,n){
		scanf("%d",&a1[i]);
	}	
	for(i=2;i<=500005;i++){
		if(a[i]!=0){
			continue;
		}
		for(j=i;j<=500005;j+=i){
			if(a[j]==0){
				a[j]=i;
			}
		}
	}
	while(q--){
		scanf("%d",&x);
		ans=0;
		x--;
		c[x]++;
		v.clear();
		get(a1[x]);
		v.resize(unique(v.begin(),v.end())-v.begin());
		val=(1LL<<v.size());
		for(i=1;i<val;i++){
			ans+=compute(i);
		}
		if(c[x]%2){
			fin+=(pres-ans);
			add(x);
			pres++;
		}
		else{
			fin-=(pres-ans);
			remove(x);
			if(a1[x]==1)
				fin++;
			pres--;
		}
		printf("%lld\n",fin);
	}
	//cout<<(1<<31)-24055<<endl;
}