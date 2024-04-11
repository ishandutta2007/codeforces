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
int dp[123456],pre[123456];
int compute(int val){
	int i=2;
	int j,value,lol,haha;
	set<int> seti;
	while(i<max(10,2*(int)sqrt(val)+4)){
		if(i%2==0){
			j=i/2;
			if(val%j==0){
				value=val/j;
				if(value%2){
					value/=2;
					if(value-(j-1)<=0){
						break;
					}
					else{
						seti.insert(pre[value+j]^pre[value-j]);
					}
				}
			}
		}
		else{
			if(val%i==0){
				value=val/i;
				if(value-i/2 >0){
					seti.insert(pre[value+i/2]^pre[value-i/2 -1]);
				}
				else{
					break;
				}
			}
		}
		i++;
	}
	rep(i,val+10){
		if(seti.count(i)==0){
			return i;
		}
	}
	return 0;


}



int computenew(int val){
	int i=2;
	int j,value,lol,haha;
	while(i<max(10,2*(int)sqrt(val)+4)){
		if(i%2==0){
			j=i/2;
			if(val%j==0){
				value=val/j;
				if(value%2){
					value/=2;
					if(value-(j-1)<=0){
						break;
					}
					else{
						
						haha=pre[value+j]^pre[value-j];
						
						if(!haha)
							return i;
					}
				}
			}
		}
		else{
			if(val%i==0){
				value=val/i;
				if(value-i/2 >0){
					haha=(pre[value+i/2]^pre[value-i/2 -1]);
					if(!haha)
							return i;
				}
				else{
					break;
				}
			}
		}
		i++;
	}
	


}



int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    dp[0]=0;
    dp[1]=0;
    pre[0]=0;
    pre[1]=0;
    int i;
    f(i,2,n+1){
    	dp[i]=compute(i);
    	
    	pre[i]=pre[i-1]^dp[i];
    }
    if(dp[n]==0){
    	cout<<-1<<endl;
    }
    else{

   		cout<<computenew(n)<<endl;
    }
}