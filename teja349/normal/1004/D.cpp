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
//setbase - cout << setbase (16); cout << 100 << endl; Prlls 64
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
ll side,tot=0,t;
ll poss[1234567],cnt[1234567],woww[2234567];
ll check(ll rows,ll cols){
	ll i,j;
	rep(i,t+1){
		woww[i]=0;
	}
	ll flag;
	ll ans=0,x,y;
	if(rows>=2*side+1){
		x=side;
		ans=0;
		rep(i,rows){
			ans+=abs(i-side)*cols;
		}
		rep(i,cols){
			ans+=i*rows;
		}
		i=0;
		if(ans!=tot)
			f(i,1,cols){
				ans+=i*rows-(cols-i)*rows;
				if(ans==tot){
					break;
				}
			}

		if(ans==tot){
			y=i;
			//cout<<x<<" "<<y<<endl;
			rep(i,rows){
				rep(j,cols){
					woww[abs(i-x)+abs(j-y)]++;
				}
			}
			flag=0;
			rep(i,t+1){
				if(woww[i]!=cnt[i]){
					//cout<<i<<endl;
					flag=1;
					break;
				}
			}

			if(!flag){
				cout<<rows<<" "<<cols<<endl;
				cout<<x+1<<" "<<y+1<<endl;
				exit(0);
			}
		}
		
	}
	rep(i,t+1){
		woww[i]=0;
	}
	swap(rows,cols);
		if(rows>=2*side+1){
		x=side;
		ans=0;
		rep(i,rows){
			ans+=abs(i-side)*cols;
		}
		rep(i,cols){
			ans+=i*rows;
		}
		i=0;
		if(ans!=tot)
		f(i,1,cols){
			ans+=i*rows-(cols-i)*rows;
			if(ans==tot){
				break;
			}
		}
		if(ans==tot){
			y=i;
			rep(i,rows){
				rep(j,cols){
					woww[abs(i-x)+abs(j-y)]++;
				}
			}
			flag=0;
			rep(i,t+1){
				if(woww[i]!=cnt[i]){
					flag=1;
					break;
				}
			}
			if(!flag){
				cout<<rows<<" "<<cols<<endl;
				cout<<x+1<<" "<<y+1<<endl;
				exit(0);
			}
		}
		
	}

}


int main(){
    std::ios::sync_with_stdio(false);
    cin>>t;
    ll i,val;
    rep(i,t){
    	cin>>val;
    	tot+=val;
    	cnt[val]++;
    }
    poss[0]=1;
    poss[1]=4;
    f(i,2,1234567){
    	poss[i]=poss[i-1]+4;
    }
    rep(i,1234567){
    	if(cnt[i]>poss[i]){
    		cout<<-1<<endl;
    		return 0;
    	}
    }
    if(cnt[0]==0){
    	cout<<-1<<endl;
    	return 0;
    }
    rep(i,1234567){
    	if(cnt[i]!=poss[i])
    		break;
    }
    side=i-1;
    for(i=1;i*i<=t;i++){
    	if(t%i==0){
    		//cout<<i<<endl;
    		check(i,t/i);
    	}
    }
    cout<<-1<<endl;
    return 0;  
    
}