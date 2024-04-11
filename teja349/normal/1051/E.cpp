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
#define mod (998244353)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
#define flush fflush(stdout) 
#define primeDEN 727999983
//cout<<fixed<<setprecision(15)<<ans;
 
template <typename T>
void printvec(vector<T>& vec){
	for(int i=0;i<vec.size();i++){
		cout<<vec[i]<<" ";
	}
	cout<<endl;
}
string a,l,r;
int z[2123456];
int lower[1234567],higher[1234567];

void Zalgo(string s){
	int L = 0, R = 0;
	int n=s.length();
	for (int i = 1; i < n; i++) {
	  if (i > R) {
	    L = R = i;
	    while (R < n && s[R-L] == s[R]) R++;
	    	z[i] = R-L; R--;
	  	} else {
	    int k = i-L;
	    if (z[k] < R-i+1) z[i] = z[k];
	    else {
	      L = i;
	      while (R < n && s[R-L] == s[R]) R++;
	      z[i] = R-L; R--;
	    }
	  }
	}
}
ll pre[2123456];
ll update(ll pos,ll val){
	pre[pos]=pre[pos+1]+val;
	pre[pos]%=mod;
}
// ll query(ll pos){
// 	ll ans=0;
// 	while(pos){
// 		ans+=bit[pos];
// 		pos-=pos&(-pos);
// 	}
// 	//ans%=mod;
// 	return ans;
// }
ll compute(ll l,ll r){
	if(l>r)
		return 0;
	ll val=pre[l]-pre[r+1];
	val%=mod;
	return val;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin>>a>>l>>r;
    string s1,s2;
    s1=l+"$"+a;
    s2=r+"$"+a;
    Zalgo(s1);
    int i,j=0;
    f(i,l.length()+1,s1.length()){
    	lower[j]=z[i];
    	j++;
    }
    Zalgo(s2);
    j=0;
    f(i,r.length()+1,s2.length()){
    	higher[j]=z[i];
    	j++;
    }
    int n=a.length();
    int llen=l.length();
    int rlen=r.length();
    update(n,1);
    int len;
    //dp[n]=1;
    int flag;
    ll ans=0;
    fd(i,n-1,0){
    	ans=0;
    	if(a[i]=='0'){
    		if(l=="0"){
    			ans=compute(i+1,i+1);
    		}
    		update(i,ans);
    		continue;
    	}
    	len=n-i;
    	if(len<llen){
    		update(i,0);
    		continue;
    	}
    	
    	if(llen==rlen){
    		flag=0;
    		if(lower[i]<llen){
    			if(a[i+lower[i]]>l[lower[i]]){
    				flag++;
    			}
    		}
    		else{
    			flag++;
    		}
    		if(higher[i]<rlen){
    			if(a[i+higher[i]]<r[higher[i]]){
    				flag++;
    			}
    		}
    		else{
    			flag++;
    		}
    		if(flag==2){
    			ans+=compute(i+llen,i+llen);
    		}
    	}
    	else{
    		flag=0;
    		if(lower[i]<llen){
    			if(a[i+lower[i]]>l[lower[i]]){
    				flag++;
    			}
    		}
    		else{
    			flag++;
    		}
    		if(flag){
    			ans+=compute(i+llen,i+llen);
    		}
    		ans+=compute(i+llen+1,i+min(rlen-1,len));
    		if(len>=rlen){
    			flag=0;
    			if(higher[i]<rlen){
	    			if(a[i+higher[i]]<r[higher[i]]){
	    				flag++;
	    			}
	    		}
	    		else{
	    			flag++;
	    		}
	    		if(flag){
	    			ans+=compute(i+rlen,i+rlen);
	    		}
    		}
    	}
    	ans%=mod;
    	update(i,ans);
    }
    ans+=mod;
    ans%=mod;
    cout<<ans<<endl;
    
    return 0;   
}