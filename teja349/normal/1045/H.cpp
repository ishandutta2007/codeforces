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
#define flush fflush(stdout) 
#define primeDEN 727999983
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct total{
	ll c[2][2];
	total(){
		int i,j;
		rep(i,2){
			rep(j,2){
				c[i][j]=0;
			}
		}
	}
};
total aa[123456],bb[123456];
int a[123456],b[123456],c[12][12],d[12][12];
int n,m;
int check1(){
	int i,j;
	rep(i,2){
		rep(j,2){
			if(aa[0].c[i][j]!=c[i][j])
				return 0;
		}
	}

	return 1;
}

int check2(){
	int i,j;
	rep(i,2){
		rep(j,2){
			if(bb[0].c[i][j]!=c[i][j])
				return 0;
		}
	}

	return 1;
}
int fact[212345],invfact[212345],inv[123456];
int precomp(){
	int i;
	fact[0]=1;
	f(i,1,123456){
		fact[i]=fact[i-1]*i;
		fact[i]%=mod;
	}
	inv[1]=1;
	int p=mod;
	f(i,2,123456){
		inv[i]=(p-p/i)*inv[p%i];
		inv[i]%=mod;
	}
	invfact[0]=1;
	invfact[1]=1;
	f(i,2,123456){
		invfact[i]=invfact[i-1]*inv[i];
		invfact[i]%=mod;
	}
	return 0;
}
int nCr(int n,int r){
	//cout<<n<<" "<<r<<endl;
	if(n<r)
		return 0;
	if(r<0)
		return 0;
	ll ans=fact[n];
	//cout<<fact[1]<<endl;
	ans*=invfact[r];
	ans%=mod;
	ans*=invfact[n-r];
	ans%=mod;
	return ans;
}
int computeans1(int pos){

	int i,j;
	 rep(i,2){
	 	rep(j,2){
	 		d[i][j]=c[i][j]-aa[pos+1].c[i][j];
	 	}
	 }
	 if(pos!=n-1){
	 	d[a[pos+1]][a[pos]^1]--;
	 }
	 int cur=a[pos]^1;
	 int ans=1;
	 if(d[cur][cur^1]==d[cur^1][cur]){
	 	ans= nCr(d[cur][cur]+d[cur][cur^1],d[cur][cur^1]);
	 	if(d[cur][cur^1]>=1)
			ans*=nCr(d[cur^1][cur^1]+d[cur][cur^1]-1,d[cur][cur^1]-1);
		else if(d[cur^1][cur^1]!=0)
			ans=0;
	 }
	 else if(d[cur][cur^1]==d[cur^1][cur]+1){
	 	ans= nCr(d[0][0]+d[cur][cur^1]-1,d[cur][cur^1]-1);
	 	ans*=nCr(d[1][1]+d[cur][cur^1]-1,d[cur][cur^1]-1);
	 }
	 else{
	 	ans=0;
	 }
	 ans%=mod;
	 return ans;
}
int computeans2(int pos){

	//cout<<pos<<endl;
	int i,j;
	rep(i,2){
		rep(j,2){
			d[i][j]=c[i][j]-bb[pos+1].c[i][j];
		}
	}
	if(pos!=m-1){
		d[b[pos+1]][b[pos]^1]--;
	}
	int cur=b[pos]^1;
	int ans=1;
	if(d[cur][cur^1]==d[cur^1][cur]){
		ans= nCr(d[cur][cur]+d[cur][cur^1],d[cur][cur^1]);
		if(d[cur][cur^1]>=1)
			ans*=nCr(d[cur^1][cur^1]+d[cur][cur^1]-1,d[cur][cur^1]-1);
		else if(d[cur^1][cur^1]!=0)
			ans=0;
		
	}
	else if(d[cur][cur^1]==d[cur^1][cur]+1){

		ans= nCr(d[0][0]+d[cur][cur^1]-1,d[cur][cur^1]-1);
		ans*=nCr(d[1][1]+d[cur][cur^1]-1,d[cur][cur^1]-1);
	}
	else{
		ans=0;
	}
	ans%=mod;
	return ans;


}
int visit[123456][2][2],dp[123456][2][2];
int compute(int pos,int f1,int f2){
	if(pos==-1){
		if(f1){
			return check1();
		}
		else{
			return check2();
		}
	}
	if(visit[pos][f1][f2]==1){
		return dp[pos][f1][f2];
	}
	visit[pos][f1][f2]=1;
	ll ans=0;

	int nodo=0;
	int newf1,newf2;
	if(f1){
		if(a[pos]==1){
			nodo=1;
		}
		else{
			newf1=1;
		}
	}
	else{
		newf1=0;
	}
	if(f2){
		if(b[pos]==1){
			newf2=0;
		}
		else{
			newf2=1;
		}
	}
	else{
		newf2=0;
	}
	if(!nodo && pos!=m-1){
		if(newf1+newf2){
			ans+=compute(pos-1,newf1,newf2);
		}
		else{

			if(f1){
				ans+=computeans1(pos);
			}
			else{
				ans+=computeans2(pos);
			}
		}
	}
	nodo=0;
	if(f1){
		if(a[pos]==1){
			newf1=1;
		}
		else{
			newf1=0;
		}
	}
	else{
		newf1=0;
	}
	if(f2){
		if(b[pos]==1){
			newf2=1;
		}
		else{
			nodo=1;
		}
	}
	else{
		newf2=0;
	}
	if(!nodo){
		//cout<<newf2<<endl;
		if(newf1+newf2){

			ans+=compute(pos-1,newf1,newf2);
			
		}
		else{
			if(f1){

				ans+=computeans1(pos);
			}
			else{
				
				ans+=computeans2(pos);
			}
		}
	}
	// if(pos==8){
	// 	cout<<ans<<endl;
	// }
	ans%=mod;
	dp[pos][f1][f2]=ans;
	return ans;
}
signed main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int i,j;
    string s,t;
    int sumi=0;
    cin>>s>>t;
    precomp();
    rep(i,2){
    	rep(j,2){
    		cin>>c[i][j];
    		sumi+=c[i][j];
    	}
    }
    sumi++;
    rep(i,s.length()){
    	a[s.length()-1-i]=s[i]-'0';
    }
    rep(i,t.length()){
    	b[t.length()-1-i]=t[i]-'0';
    }
    n=s.length();
    m=t.length();
    if(sumi<n || m<sumi){
    	cout<<0<<endl;
    	return 0;
    }
    if(m>sumi){
    	rep(i,sumi){
    		b[i]=1;
    	}
    	f(i,sumi,m){
    		b[i]=0;
    	}
    	m=sumi;
    }
    rep(i,m+10){
    	aa[i]=total();
    	bb[i]=total();
    }
    fd(i,n-2,0){
    	aa[i]=aa[i+1];
    	aa[i].c[a[i+1]][a[i]]++;
    }
    fd(i,m-2,0){
    	bb[i]=bb[i+1];
    	bb[i].c[b[i+1]][b[i]]++;
    }
    //cout<<m<<endl;
    cout<<compute(sumi-1,1,1)<<endl;



    return 0;   
}