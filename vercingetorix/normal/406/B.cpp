#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int>> vvi;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back

int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif

  int n,m,k;
//int ans=0;
  //cin >> a >> k;
  k=0;
cin>>n;
int s=1000001;
vb a(1000001,false);
vi b(500001,0);

for(int i=1;i<=n;i++){
    int x;
    scanf("%d",&x);
    a[x]=true;
    int y=s-x;
    if(a[y]==true) k++;
    b[min(x,y)]++;
}
cout<<n<<endl;
for(int i=1;i<=500000;i++){
    if(b[i]==1){
        if(a[i]) printf("%d ",s-i);
        else printf("%d ",i);
        continue;
    }
    if(b[i]==2) continue;
    if(k>0) {
        printf("%d %d ",i,s-i);
        k--;
    }
}

//std::string s;
//long long ans=1;

 // cout << ans;
  //cout<<coll;
 //cout << s << s.length() << s[2];
  return 0;
}