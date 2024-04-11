#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
    int n;
    cin>>n;
    if(n==1){
        cout<<"? "<<1<<" "<<1<<endl;
        string s;
        cin>>s;
        cout<<"! "<<s<<endl;
        return 0;
    }
    if(n==2){
        cout<<"? "<<1<<" "<<1<<endl;
        string a;
        cin>>a;
        cout<<"? "<<1<<" "<<2<<endl;
        string ans;
        rep(j,3){
            string s;
            cin>>s;
            if(s.size()==2){
                if(s[0]!=a[0])swap(s[0],s[1]);
                ans = s;
            }
        }
        cout<<"! "<<ans<<endl;
        return 0;
    }
    int m = (n+1)/2;
    cout<<"? "<<1<<" "<<m<<endl;
    vector<string> v1[n+1];
    rep(i,m*(m+1)/2){
        string s;
        cin>>s;
        sort(s.begin(),s.end());
        int k=s.size();
        v1[k].push_back(s);
    }
    rep(i,n+1)sort(v1[i].begin(),v1[i].end());
    cout<<"? "<<2<<" "<<m<<endl;
    vector<string> v2[n+1];
    rep(i,m*(m-1)/2){
        string s;
        cin>>s;
        sort(s.begin(),s.end());
        int k=s.size();
        v2[k].push_back(s);
    }
    rep(i,m+1){
        sort(v2[i].begin(),v2[i].end());
        v2[i].push_back("#");
    }
    string ans = "";
    vector<int> cnt(26);
    REP(i,1,m+1){
        string ret;
        rep(j,v1[i].size()){
            if(v1[i][j]!=v2[i][j]){
                ret=v1[i][j];
                break;
            }
        }
        vector<int> nc(26);
        for(auto c:ret)nc[c-'a']++;
        rep(k,26){
            if(cnt[k]!=nc[k])ans += 'a'+k;
        }
        nc.swap(cnt);
    }
    cout<<"? "<<1<<" "<<n<<endl;
    vector<string> v3[n+1];
    rep(i,n*(n+1)/2){
        string s;
        cin>>s;
        sort(s.begin(),s.end());
        int k=s.size();
        v3[k].push_back(s);
    }
    rep(i,n+1)sort(v3[i].begin(),v3[i].end());
    vector<int> pc = cnt;
    rep(i,26)cnt[i]=0;
    rep(i,n)cnt[v3[n][0][i]-'a']++;
    string ans2="";
    rep(i,n-m){
        auto& v = v3[n-i-1];
        vector<vector<int>> cc(i+1,vector<int>(26));
        rep(j,i+1){
            rep(k,j)cc[j][ans2[k]-'a']++;
            rep(k,i+1-j)cc[j][ans[k]-'a']++;
        }
        int s = v.size();
        vector<int> used(s);
        vector<vector<int>> tc(s,vector<int>(26));
        rep(j,s)rep(k,v[j].size())tc[j][v[j][k]-'a']++; 
        rep(j,i+1){
            rep(k,s){
                if(used[k])continue;
                bool ok=true;
                rep(l,26){
                    if(cc[j][l]+tc[k][l]!=cnt[l]){
                        ok=false;
                        break;
                    }
                }
                if(ok){
                    used[k]=true;
                    break;
                }
            }
        }
        rep(k,s){
            if(!used[k]){
                rep(j,ans2.size())tc[k][ans2[j]-'a']++;
                rep(l,26){
                    if(tc[k][l]!=cnt[l])ans2 += 'a'+l;
                }
                break;
            }
        }
    }
    reverse(ans2.begin(),ans2.end());
    cout<<"! "<<ans<<ans2<<endl;
    return 0;
}