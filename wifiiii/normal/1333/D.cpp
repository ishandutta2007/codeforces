#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'

int main()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int mx=0,mn=0;
    int cnt=0;
    for(int i=0;i<s.size();++i) {
        if(s[i]=='R') ++cnt;
        else
        {
            mx+=cnt;
            if(cnt) mn=max(mn+1,cnt);
        }
    }
//    cout << mn << " " << mx << endl;
    if(mn <= k && k <= mx)
    {
        int tmp = mx - k;
        for(int i=1;i<=k;++i)
        {
            if(tmp)
            {
                vector<int> ans;
                int f = 1;
                for(int j=0;j<s.size();++j)
                {
                    if(j && s[j] == 'L' && s[j-1] == 'R')
                    {
                        if(f)
                        {
                            f = 0;
                            ans.push_back(j-1);
                            swap(s[j-1],s[j]);
                            ++j;
                        }
                        else
                        {
                            if(tmp) --tmp,ans.push_back(j-1),swap(s[j-1],s[j]),++j;
                        }
                    }
                }
                printf("%d ",ans.size());
                for(int i : ans) printf("%d ",i+1);
                puts("");
            }
            else
            {
                int cnt = 0;
                for(int j=0;j<s.size();++j)
                {
                    if(s[j] == 'R') ++cnt;
                    else
                    {
                        for(int p=j,c=0;c<cnt;++c,--p)
                        {
                            printf("1 %d\n",p);
                        }
                    }
                }
                return 0;
            }
        }
    }
    else cout << -1 << endl;
}