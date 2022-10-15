#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
#define rint register int
#define rep(i,l,r) for(rint i=l;i<=r;i++)
#define per(i,l,r) for(rint i=l;i>=r;i--)
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define fir first
#define sec second
template<typename T1,typename T2>void ckmin(T1 &a,T2 b){if(a>b)a=b;}
template<typename T1,typename T2>void ckmax(T1 &a,T2 b){if(a<b)a=b;}
template<typename T>T gcd(T a,T b){return b?gcd(b,a%b):a;}
int read(){
  int x=0,f=0;
  char ch=getchar();
  while(!isdigit(ch))f|=ch=='-',ch=getchar();
  while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
  return f?-x:x;
}
const int N=105;
char ans[N];
int cnt[26],n;
string str;
void solve1(int n){
  if(n==1){
    cout<<"? 1 1\n";
    cin>>str;
    ans[1]=str[0]-'a';
    return;
  }
  cout<<"? 1 "<<n<<'\n';
  int len=n*(n+1)/2;
  multiset<string>s;
  while(len--){
    cin>>str;
    sort(str.begin(),str.end());
    s.insert(str);
  }
  cout<<"? 1 "<<n-1<<'\n';
  len=(n-1)*n/2;
  while(len--){
    cin>>str;
    sort(str.begin(),str.end());
    s.erase(s.find(str));
  }
  vector<string>tmp;
  for(auto v:s)tmp.pb(v);
  sort(tmp.begin(),tmp.end(),[&](string a,string b){
    return a.size()<b.size();
  });
  for(int i=n,j=0;i>=1;i--,j++){
    memset(cnt,0,sizeof(cnt));
    for(auto v:tmp[j])cnt[v-'a']++;
    for(int j=i+1;j<=n;j++)cnt[ans[j]]--;
    for(int j=0;j<26;j++)if(cnt[j])ans[i]=j;
  }
}
int f[N][26];
void solve2(int n){
  int k=n/2;
  cout<<"? 1 "<<n<<'\n';
  vector<string>tmp;
  int len=n*(n+1)/2;
  while(len--){
    cin>>str;
    tmp.pb(str);
  }
  sort(tmp.begin(),tmp.end(),[&](string a,string b){
    return a.size()>b.size();
  });
  for(auto v:tmp){
    int len=v.size();
    for(auto t:v){
      f[len][t-'a']++;
    }
  }
  for(int i=n/2;i>=0;i--){
    memset(cnt,0,sizeof(cnt));
    for(int j=0;j<26;j++)cnt[j]=f[i+1][j]-f[i][j];
    for(int j=i+1;j<n-i;j++)cnt[ans[j]]--;
    for(int j=0;j<26;j++)if(cnt[j]>0)ans[n-i]=j;
  }
}
int main(){
  cin>>n;
  if(n==1){
    cout<<"? 1 1\n";
    cin>>str;
    cout<<"! "<<str<<'\n';
    return 0; 
  }
  solve1(n/2);
  solve2(n);
  cout<<"! ";
  for(int i=1;i<=n;i++)cout<<char(ans[i]+'a');
  cout<<'\n';
  return 0;
}