#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
random_device rng;
mt19937 urng(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int le = 0, ri = 0;
    for(int i=0;i<s.size();++i) if(s[i]=='(') le++;else ri++;
    if(le!=ri) return cout<<"0\n1 1\n",0;
    int ans = 0, mi = 0, mj = 0;
    {
        int minn = 1e9, mmi = 0;
        int tmpcnt = 0;
        for(int i=0;i<s.size();++i)
        {
            if(s[i] == '(') tmpcnt++;
            else tmpcnt--;
            if(tmpcnt < minn)
            {
                minn = tmpcnt;
                mmi = i;
            }
        }
        int tmp = 0;
        int cnt = 0;
        int ok = 1;
        for(int i=mmi+1;i<s.size();++i)
        {
            if(s[i] == '(') ++cnt;
            else --cnt;
            if(cnt < 0) {ok=0;break;}
            if(cnt == 0) tmp++;
        }
        for(int i=0;i<=mmi;++i)
        {
            if(s[i] == '(') ++cnt;
            else --cnt;
            if(cnt < 0) {ok=0;break;}
            if(cnt == 0) tmp++;
        }
        if(ok && tmp > ans)
        {
            ans = tmp;
            mi = 0;
            mj = 0;
        }
    }
    for(int i=0;i<s.size();++i) {
        for(int j=i+1;j<s.size();++j) {
            if(s[i] == s[j]) continue;
            swap(s[i], s[j]);
            int minn = 1e9, mmi = 0;
            int tmpcnt = 0;
            for(int i=0;i<s.size();++i)
            {
                if(s[i] == '(') tmpcnt++;
                else tmpcnt--;
                if(tmpcnt < minn)
                {
                    minn = tmpcnt;
                    mmi = i;
                }
            }
            int tmp = 0;
            int cnt = 0;
            int ok = 1;
            for(int i=mmi+1;i<s.size();++i)
            {
                if(s[i] == '(') ++cnt;
                else --cnt;
                if(cnt < 0) {ok=0;break;}
                if(cnt == 0) tmp++;
            }
            for(int i=0;i<=mmi;++i)
            {
                if(s[i] == '(') ++cnt;
                else --cnt;
                if(cnt < 0) {ok=0;break;}
                if(cnt == 0) tmp++;
            }
            if(ok && tmp > ans)
            {
                ans = tmp;
                mi = i;
                mj = j;
            }
            swap(s[i], s[j]);
        }
    }
    cout << ans << endl << mi+1 << " " << mj+1 << endl;
}