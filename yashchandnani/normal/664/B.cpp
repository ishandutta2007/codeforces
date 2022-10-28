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

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  char c;
  int p=1,n=0;
  int a[100],st=0;
  while(cin>>c&&c!='='){
  	if (c=='+')
  	{
  		a[st]=1;
  		st++;
  		p++;
  	}
  	else if (c=='-')
  	{
  		a[st]=0;
  		st++;
  		n++;
  	}
  }
  int f;cin>>f;
  if (f>p*f-n||f<p-n*f)
  {
  	cout<<"Impossible";
  }
  else{
  	cout<<"Possible\n";
  	if (p-n>f)
  	{
  		int vn=1;
  		while(p-vn*n>f){
  			vn++;
  		}
  		int nn=-(p-vn*n-f);
  		cout<<1<<" ";
  		rep(i,st){
  			if (a[i]==1)
  			{
  				cout<<"+ "<<1<<" ";
  			}
  			else{
  				if (nn>0)
  				{
  					cout<<"- "<<vn-1<<" ";
  					nn--;
  				}
  				else{
  					cout<<"- "<<vn<<" ";
  				}
  			}
  		}
  		cout<<"= "<<f<<"\n";

  	}
  	else{
  		int vn=1;
  		while(p*vn-n<f){
  			vn++;
  		}
  		int nn=(p*vn-n-f);
  		if (nn!=0)
  		{
  			cout<<vn-1<<" ";
  			nn--;
  		}
  		else{
  			cout<<vn<<" ";
  		}
  		rep(i,st){
  			if (a[i]==0)
  			{
  				cout<<"- "<<1<<" ";
  			}
  			else{
  				if (nn>0)
  				{
  					cout<<"+ "<<vn-1<<" ";
  					nn--;
  				}
  				else{
  					cout<<"+ "<<vn<<" ";
  				}
  			}
  		}
  		cout<<"= "<<f<<"\n";
  	}

  }

  return 0;
}