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
ll x,k,n,q,iinf,counter=0,c[100];
map<ll,ll> inv,mapi,special;
ll dp[75][75],res[75],res1[75],reserv[75][75],haha[75][75];
ll hshit(ll i){
	ll jj=i,cnt=0;
	while(i>0){
		if(i%2)
			cnt++;
		i/=2;
	}
	i=jj;
	if(cnt!=x){
		return 0;
	}
	mapi[i]=counter;
	inv[counter]=i;
	counter++;
	return 0;
}
ll updatedp(){
	ll i,j,k;
	rep(i,counter){
		rep(j,counter){
			haha[i][j]=iinf;
		}
	}
	rep(i,counter){
		rep(j,counter){
			rep(k,counter){
				haha[i][k]=min(haha[i][k],dp[i][j]+dp[j][k]);
			}
		}
	}
	rep(i,counter){
		rep(j,counter){
			dp[i][j]=haha[i][j];
		}
	}
}  
ll updateres(){
	ll i,j;
	rep(i,counter){
		res1[i]=iinf;
	}
	rep(i,counter){
		rep(j,counter){
			res1[j]=min(res1[j],res[i]+dp[i][j]);
		}
	}
	rep(i,counter){
		res[i]=res1[i];
	}
	return 0;
}
ll updatefrom(ll s,ll e){

	e=min(e,n);
	if(e<=s){
		return 0;
	}
	//cout<<s<<"fdf "<<e<<endl;
	//return 0;
	//cout<<"boo"<<endl;
	ll i,j;
	ll len=e-s;
	rep(i,counter){
		rep(j,counter){
			dp[i][j]=reserv[i][j];
		}
	}
	while(len>0){
		if(len%2){
			//cout<<"Dasd"<<endl;

			updateres();
		}
	
			//cout<<"Dsasd"<<endl;
			// rep(i,counter){
			// 	rep(j,counter){
			// 		cout<<inv[i]<<" "<<inv[j]<<" "<<dp[i][j]<<endl;
			// 	}
			// }
			updatedp();
		
		len/=2;
	}
	return 0;
}
ll initiall(ll val){
	//cout<<val<<endl;
	ll wow1,wow=inv[val];
	if(wow%2==0){
		reserv[val][mapi[wow/2]]=0;
		return 0;
	}
	wow1=wow;
	wow/=2;
	ll i,j;
	rep(i,k){
		if(wow&(1LL<<i)){
			continue;
		}
		wow1=wow+(1<<i);
		reserv[val][mapi[wow1]]=c[i+1];
		//cout<<i<<"dsd "<<c[i+1]<<endl;
	}
	return 0;
}
ll manual(ll s,ll e){
	e=min(e,n);
	if(e<=s)
		return 0;
	//cout<<s<<" "<<e<<endl;
	//return 0;
	ll i,j,p,wow,wow1,wow2;
	f(i,s,e){
		rep(j,counter){
			res1[j]=iinf;
			//cout<<res[j]<<"dsd "<<endl;
		}
		//return 0;
		rep(j,counter){
			//cout<<"Dasd"<<endl;
			wow=inv[j];
			if(wow%2==0){
				res1[mapi[wow/2]]=min(res1[mapi[wow/2]],res[j]);
				continue;
			}
			wow2=wow;
			wow2=mapi[wow2];
			wow/=2;
			//cout<<res[1]<<endl;
			rep(p,k){
				//cout<<p<<endl;
				if((wow&(1LL<<p))==0){

					if(special.find(i+p+1)!=special.end()){
						//cout<<"dasdsa"<<endl;
						wow1=wow+(1<<p);
						wow1=mapi[wow1];
						
						res1[wow1]=min(res1[wow1],res[wow2]+c[p+1]+special[i+p+1]);
					}
					else{
						wow1=wow+(1<<p);
						//cout<<res[wow2]+c[p+1]<<endl;
						wow1=mapi[wow1];
						//wow2=mapi[wow2];
						res1[wow1]=min(res1[wow1],res[wow2]+c[p+1]);

					}
				}
			}
			//return 0;
		}
		//return 0;
		rep(j,counter){
			res[j]=res1[j];
		}
	}
	return 0;
}
ll sp[123],wt[123];
vll vec;
int main(){
    std::ios::sync_with_stdio(false);
    iinf =inf;
    iinf*=inf;
    cin>>x>>k>>n>>q;
    n-=x;
   	n++;
   	ll i,j;
    f(i,1,k+1){
    	cin>>c[i];
    	//cout<<c[i]<<endl;
    }
    ll init=(1<<x)-1;
    rep(i,(1<<k)){
    	hshit(i);
    }
    //return 0;
    rep(i,counter){
    	rep(j,counter){
    		reserv[i][j]=iinf;
    		res[j]=iinf;
    	}
    }

    rep(i,counter){
    	initiall(i);
    }
    // rep(i,counter){
    // 	rep(j,counter){
    // 		cout<<inv[i]<<" "<<inv[j]<<" "<<reserv[i][j]<<endl;
    // 	}
    // }
    res[mapi[init]]=0;
   	q++;
   	sp[0]=inf;
   	wt[0]=inf;
   	special[inf]=inf;
   	vec.pb(mp(sp[0],wt[0]));
   	f(i,1,q){
   		cin>>sp[i]>>wt[i];
   		special[sp[i]]=wt[i];
   		vec.pb(mp(sp[i],wt[i]));
   	}
   	sort(all(vec));
   	rep(i,q){
   		sp[i]=vec[i].ff;
   		wt[i]=vec[i].ss;
   	}
   	ll previ=1;
   	//return 0;
   	//updatefrom(1,n);
   	//manual(1,4);
   	//cout<<res[mapi[init]]<<endl;
   	//return 0;
   	rep(i,q){
   		//cout<<"Dsads"<<endl;
   		updatefrom(previ,sp[i]-k);
   		//cout<<previ<<" "<<sp[i]-k<<endl;
   		previ=max(previ,sp[i]-k);
   		//cout<<previ<<" "<<sp[i]<<endl;
   		manual(max(previ,sp[i]-k),sp[i]);
   		previ=max(previ,sp[i]);
   	}

   	cout<<res[mapi[init]]<<endl;

    return 0;  
    
}