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
ll BLOCK=350;
struct total{
	ll l,r, ind;
	ll bloc;
};
total quer[123456];
ll a[123456],pre[123456],k;
ll mapi[1234567];
ll ans=0,answ[123456];
ll gg[123456],hh[123467],ee[123456],sue,fue;
ll comp(total a,total b){
	if(a.bloc!=b.bloc)
		return a.bloc<b.bloc;
	if(a.bloc%2==0){
		return a.r<b.r;
	}
	return a.r>b.r;
}

ll addfront(ll i){
	ll haha,goo;
	mapi[hh[i]]++;
	if(i==0)
		haha=sue;
	else
		haha=ee[i-1];
	
		ans+=mapi[haha];
	return 0;
}
ll delfront(ll i){
	ll haha,goo;
	if(i==0)
		haha=sue;
	else
		haha=ee[i-1];
	//if(mapi.find(haha+k)!=mapi.end())
		ans-=mapi[haha];
	mapi[hh[i]]--;
	return 0;
}

ll addback(ll i,ll j){
	ll haha,goo;
	haha=gg[i];
	if(j==0)
		goo=sue;
	else
		goo=ee[j-1];
	//if(mapi.find(haha-k)!=mapi.end())
		ans+=mapi[haha];
	//cout<<i<<" "<<j<<haha<<endl;
	if(hh[i]==goo)
		ans++;
	mapi[hh[i]]++;
}
ll delback(ll i,ll j){
	ll haha,goo;
	mapi[hh[i]]--;
	haha=gg[i];
	if(j==0)
		goo=sue;
	else
		goo=ee[j-1];
	//if(mapi.find(haha-k)!=mapi.end())
		ans-=mapi[haha];
	if(hh[i]==goo)
		ans--;
	
}
ll t[123456];
map<ll,ll> chin;
int main(){
    //std::ios::sync_with_stdio(false);
    ll n;
    //cin>>n>>k;
    scanf("%lld%lld",&n,&k);
    ll i,j;

    rep(i,n){
    	//cin>>t[i];
    	scanf("%lld",t+i);
    	if(t[i]==2)
    		t[i]=-1;
    }
    rep(i,n){
    	//cin>>a[i];
    	scanf("%lld",a+i);
    }
    pre[0]=a[0]*t[0];
    chin[pre[0]]++;
    chin[0]++;
    chin[pre[0]+k]++;
    chin[pre[0]-k]++;
    chin[k]++;
    chin[-k]++;

    f(i,1,n){
    	pre[i]=a[i]*t[i]+pre[i-1];
    	chin[pre[i]]++;
	    //chin[0]++;
	    chin[pre[i]+k]++;
	    chin[pre[i]-k]++;
    }
    int counti=3;
    map<ll,ll>::iterator it;
    for(it=chin.begin();it!=chin.end();it++)
    	it->ss=counti++;
    rep(i,n){
    	gg[i]=chin[pre[i]-k];
    	ee[i]=chin[pre[i]+k];
    	hh[i]=chin[pre[i]];
    }
    sue=chin[k];
    fue=chin[-k];
    mapi[hh[0]]++;
    if(pre[0]==k)
    	ans++;
    ll q;
    //cin>>q;
    scanf("%lld",&q);
    rep(i,q){
    	//cin>>quer[i].l>>quer[i].r;
    	scanf("%lld",&quer[i].l);
    	scanf("%lld",&quer[i].r);
    	quer[i].l--;
    	quer[i].r--;
    	quer[i].ind=i;
    	quer[i].bloc=quer[i].l/BLOCK;
    }
    ll kr;
    sort(quer,quer+q,comp);
    //cout<<ans<<endl;
    i=0;
    j=0;
    rep(kr,q){

    	while(i>quer[kr].l){
    		i--;
    		addfront(i);
    	}
    	while(j<quer[kr].r){
    		j++;
    		//cout<<i<<" "<<j<<" tuss    "<<ans<<endl;
    		addback(j,i);
    		//cout<<i<<" "<<j<<" "<<ans<<endl;
    	}
    	while(i<quer[kr].l){
    		delfront(i);
    		i++;
    	}
    	while(j>quer[kr].r){
    		delback(j,i);
    		j--;
    	}
    	//cout<<i<<" "<<j<<ans<<endl;
    	//cout<<quer[kr].ind<<endl;
    	answ[quer[kr].ind]=ans;
    }
    rep(i,q){
    	//cout<<answ[i]<<endl;
    	printf("%lld\n",answ[i]);
    }
    return 0;  
    
}