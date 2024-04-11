#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long double ld; 

typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;

#define _  %  MOD
#define __ %= MOD

#define      each(it,s)        for(auto it = s.begin(); it != s.end(); ++it)
#define      sortA(v)          sort(v.begin(), v.end())
#define      sortD(v)          sort(v.rbegin(), v.rend())
#define      fill(a)           memset(a, 0, sizeof (a))

#define      rep(i, n)         for(int i = 0; i < (n); ++i)
#define      repA(i, a, n)     for(int i = a; i <= (n); ++i)
#define      repD(i, a, n)     for(int i = a; i >= (n); --i)
#define 	 pq(x)			   priority_queue<x,std::vector<x>,compare>
#define 	 rpq(x)			   priority_queue<x,std::vector<x>,Rcompare>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define fbo find_by_order
#define ook order_of_key
struct Rcompare
{
  bool operator()(ii lhs,ii rhs){
    return lhs.fi>rhs.fi;
  }
};
struct compare
{
  bool operator()(ii lhs,ii rhs){
    return lhs.fi<rhs.fi;
  }
};
std::map<int, int> map1,map2;
std::map<ii,int> map3;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;cin>>n;
  int a,b,t;cin>>a>>b>>t;
  char c;
  int w[n];
  rep(i,n){
  	cin>>c;
  	if (c=='w')
  	{
  		w[i]=1+b;
  	}
  	else{
  		w[i]=1;
  	}
  }
  if (t<w[0])
  	{
  		cout<<0;
  		return 0;
  	}
  if (n==1)
  {
  	
  	
  		cout<<1;return 0;
  	
  }
  t-=w[0];
  ll t1[n+1],t2[n+1],t3[n+1],t4[n+1];
  t1[0]=t2[0]=t3[0]=t4[0]=t1[n]=t2[n]=t3[n]=t4[n]=0;
  repA(i,1,n-1){
  	t1[i]=t1[i-1]+a+w[i];
  	t2[i]=t2[i-1]+2*a+w[i];
  }
  t3[n-1]=a+w[n-1];
  t4[n-1]=t3[n-1]+a;
  repD(i,n-2,1){
  	t3[i]=t3[i+1]+a+w[i];
  	t4[i]=t4[i+1]+2*a+w[i];
  }
  int ans=1;
  int j=1;
  repA(i,0,n-1){
  	int tt = t-t2[i];
  	if (tt<0)
  	{
  		break;
  	}
  	else{
  		while(t3[j]>tt){
  			j++;
  			
  		}
  		ans=max(ans,i+n-j+1);
  		
  	}
  }
  j = n-1;
  repD(i,n,0){
  	int tt = t-t4[i];
  	if (tt<0)
  	{
  		break;
  	}
  	else{
  		while(t1[j]>tt){
  			j--;
  			
  		}
  		//cout<<j<<" "<<t1[j]<<endl;
  		ans=max(ans,j+1+n-i);
  		
  	}
  }
  cout<<min(ans,n);
  return 0;
}