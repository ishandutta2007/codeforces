#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int>> vvi;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back

vvi v(100005);
vi k(100005);

std::vector<std::pair<int, int>> kandi;

int comp(int x){
	int ans=0;
	int votes=k[0];
	vi prices;
	for(int i=0; i<kandi.size(); i++){
		int c=0;
		int j=kandi[i].second;
		if(v[j].size()>x){
			for(int k=0; k<v[j].size()-x;k++){
				ans+=v[j][c];
				c++;
				votes++;
			}

		}
		while(c<v[j].size()){
			prices.pb(v[j][c]);
			c++;
		}

	}
	if(votes<=x){
		std::sort(prices.begin(), prices.end());
		int cnt=0;
		while(votes<=x){
			ans+=prices[cnt];
			cnt++;
			votes++;
		}
	}
	return ans;

}

void go(int & x, int & y){
	int x1=(2*x+y)/3;
	int x2=(2*y+x)/3;
	if((y-x)==2){
		int a=x;
		int res=comp(x);
		int res1=comp(x+1);
		int res2=comp(x+2);
		if(res1<res){
			a=x+1;
			res=res1;
		}
		if(res2<res) a=x+2;
		x=a;
		y=a;
		return;
	}
	if((y-x)==1){
		int a=x;
		if(comp(x+1)<comp(x)) a=x+1;
		x=a; y=a;
		return;
	}
	if(comp(x1)<=comp(x2)) y=x2;
	else x=x1;
}

int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif

int ans=0;
int n,m;
cin >> n;

for(int i=0; i<n; i++){
	int a,b;
	cin>>a>>b;
	v[a].push_back(b);
	k[a]++;
}
for(int i=1; i<=100000; i++){
	std::sort(v[i].begin(), v[i].end());
	if(v[i].size()>0) kandi.pb(make_pair(v[i].size(),i));
}
std::sort(kandi.begin(), kandi.end());
std::reverse(kandi.begin(), kandi.end());
int x=0; int y=n-1;
while(x<y) go(x,y);
cout<<comp(x);
//cout<<ans;
return 0;


}