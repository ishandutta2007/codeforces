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
int dp[2010][10][10][10];
int a[2123],b[2123],arr[100],bb[100];
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i,j,k,p,ans,cur,drop,dd,flag;
    rep(i,n){
    	cin>>a[i]>>b[i];
    }

    rep(i,n){
    	rep(j,10){
    		rep(k,10){
    			rep(p,10){
    				dp[i][j][k][p]=inf;
    			}
    		}
    	}
    }
    dp[0][0][0][0]=a[0]-1;
    rep(i,n-1){
    	rep(j,10){
    		f(k,j,10){
    			f(p,k,10){
    				if(dp[i][j][k][p]==inf)
    					continue;
    				arr[0]=b[i];
    				arr[1]=j;
    				arr[2]=k;
    				arr[3]=p;
    				sort(arr,arr+4);
    				if(arr[0]==0){
    					dp[i+1][arr[1]][arr[2]][arr[3]]=min(dp[i+1][arr[1]][arr[2]][arr[3]],dp[i][j][k][p]+abs(a[i+1]-a[i]));
    				}
    				while(1){
    					
    					cur=a[i];
    					flag=0;
    					f(drop,1,5){
    						flag=0;
    						rep(dd,drop){
    							if(arr[dd]==0){
    								flag=1;
    							}
    						}
    						if(flag)
    							break;
    						ans=0;
    						cur=a[i];
    						rep(dd,drop){
    							ans+=abs(arr[dd]-cur);
    							cur=arr[dd];
    						}
    						rep(dd,4){
    							bb[dd]=arr[dd];
    						}
    						rep(dd,drop){
    							bb[dd]=0;
    						}
    						sort(bb,bb+4);
    						if(drop==1){
    							dp[i+1][bb[1]][bb[2]][bb[3]]=min(dp[i+1][bb[1]][bb[2]][bb[3]],dp[i][j][k][p]+ans+abs(a[i+1]-cur));
    						}
    						else if(drop==2){
    							dp[i+1][0][bb[2]][bb[3]]=min(dp[i+1][0][bb[2]][bb[3]],dp[i][j][k][p]+ans+abs(a[i+1]-cur));
    						}
    						else if(drop==3){
    							dp[i+1][0][0][bb[3]]=min(dp[i+1][0][0][bb[3]],dp[i][j][k][p]+ans+abs(a[i+1]-cur));
    						}
    						else{
    							dp[i+1][0][0][0]=min(dp[i+1][0][0][0],dp[i][j][k][p]+ans+abs(a[i+1]-cur));
    						}

    					}
    					if(!next_permutation(arr,arr+4)){
    						break;
    					}
    				}
    			}
    		}
    	}
    }

    int mini=inf;
    rep(j,10){
    	rep(k,10){
    		rep(p,10){
    			if(dp[n-1][j][k][p]==inf)
    				continue;
    			//cout<<j<<" "<<k<<" "<<p<<" "<<dp[n-1][j][k][p]<<endl;
				arr[0]=b[n-1];
				arr[1]=j;
				arr[2]=k;
				arr[3]=p;
				sort(arr,arr+4);
				rep(i,4){
					if(arr[i]!=0){
						break;
					}
				}

				while(1){
    					
					cur=a[n-1];
					flag=0;
					//drop=4-i+1;
					{
						
						
						ans=0;
						cur=a[n-1];
						f(dd,i,4){
							ans+=abs(arr[dd]-cur);
							cur=arr[dd];
						}

						mini=min(dp[n-1][j][k][p]+ans,mini);
						

					}
					if(!next_permutation(arr+i,arr+4)){
						break;
					}
				}
    		}
    	}
    }
    cout<<mini+2*n<<endl;
    return 0;  
    
}