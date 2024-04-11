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
bool look(string& s,int i){
	rep(j,s.size()){
		if (s[j]==char(int('a')+i))
		{
			return true;
		}
	}
	return false;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;cin>>n;
  string t;cin>>t;
  int count[100]={0};
  rep(i,t.size()){
  	count[t[i]-'0']++;
  }
  std::vector<int> v;
  rep(i,100){
  	if (count[i]%2==1)
  	{
  		v.pb(i);
  		count[i]--;
  	}
  }
  if (int(v.size())!=0&&(n-int(v.size()))%(2*int(v.size()))!=0)
  {
  	bool flag =false;
  	rep(i,100){
  		while (count[i]>0)
  		{
  			count[i]-=2;
  			v.pb(i);v.pb(i);
  			if ((n-int(v.size()))%(2*int(v.size()))==0)
  			{
  				flag = true;
  				break;
  			}
  		}
  		if (flag)
  		{
  			break;
  		}
  	}
  }
  cout<<max(1,int(v.size()))<<endl;
  int tot = n - int(v.size());
  tot/=2;
  tot/=int(v.size());
  if(v.size()==0){
	  rep(i,100){
	  	rep(j,count[i]/2){
	  		cout<<char(int('0')+i);
	  	}
	  }
	  repD(i,99,0){
	  	rep(j,count[i]/2){
	  		cout<<char(int('0')+i);
	  	}
	  }
	}
	else{
		int i =0;
		rep(k,int(v.size())){
			std::vector<int> st;
			i = max(i,0);
			while(st.size()<tot){
				while(count[i]>0){
					st.pb(i);
					cout<<char(int('0')+i);
					count[i]-=2;
					if (int(st.size())==tot)
					{
						i-=2;

						break;
					}
				}
				i++;
			}
			cout<<char(int('0')+v[k]);
			repD(j,st.size()-1,0){
				cout<<char(int('0')+st[j]);
			}
			cout<<" ";
		}

	}	

 
  return 0;
}