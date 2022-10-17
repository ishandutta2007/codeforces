#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define fe(i,n) for(int i=1;i<=n;++i)
#define ff(i,n) for(int i=0;i<n;++i)
#define fs(i,s) for(int i=0;i<s.size();++i)
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

vector<int> g[3];
int cnt[1000005][3];
int main()
{
    string s;
    cin>>s;
    int a=0,b=0,c=0;
    fs(i,s)
    {
        if(s[i]=='a')
        {
            a++,g[0].push_back(i);
            if(i) cnt[i][0]=cnt[i-1][0]+1;
            else cnt[i][2]=1;
        }
        else if(s[i]=='b')
        {
            b++,g[1].push_back(i);
            if(i) cnt[i][1]=cnt[i-1][1]+1;
            else cnt[i][2]=1;
        }
        else
        {
            c++,g[2].push_back(i);
            if(i) cnt[i][2]=cnt[i-1][1]+1;
            else cnt[i][2]=1;
        }
    }
    
    for(int mg=0;mg<=2;++mg)
    {
        char mc='a'+mg;
        if(!g[mg].size()) continue;
        if(g[mg].size()%2)
        {
            string ans;
            int l=0,r=g[mg].size()-1;
            int pos=s.size()-1;
            for(int i=0;i<g[mg][0];++i)
            {
                int c=s[i]-'a';
                if(cnt[pos][c]==cnt[g[mg].back()][c]) continue;
                while(pos>g[mg].back()) if(s[i]==s[pos]) {ans+=s[i];pos--;break;} else pos--;
                if(pos<=g[mg].back()) break;
            }
            while(l<r)
            {
                ans+=mc;
                int pos=g[mg][r]-1;
                for(int i=g[mg][l]+1;i<g[mg][l+1];++i)
                {
                    int c=s[i]-'a';
                    if(cnt[pos][c]==cnt[g[mg][r-1]][c]) continue;
                    while(pos>g[mg][r-1]) if(s[i]==s[pos]) {ans+=s[i];pos--;break;}else pos--;
                    if(pos<=g[mg][r-1]) break;
                }
                l++,r--;
            }
            ans+=mc;
            string ans2=ans;
            reverse(all(ans2));
            ans.erase(ans.end()-1);
            ans+=ans2;
            if(ans.size()>=s.size()/2) return cout<<ans<<endl,0;
        }
        else
        {
            string ans;
            int l=0,r=g[mg].size()-1;
            int pos=s.size()-1;
            for(int i=0;i<g[mg][0];++i)
            {
                int c=s[i]-'a';
                if(cnt[pos][c]==cnt[g[mg].back()][c]) continue;
                while(pos>g[mg].back()) if(s[i]==s[pos]) {ans+=s[i];pos--;break;} else pos--;
                if(pos<=g[mg].back()) break;
            }
            int f=1;
            while(l<r)
            {
                if(r-l==1)
                {
                    ans+=mc;
                    int pos=g[mg][r]-1;
                    for(int i=g[mg][l]+1;i<g[mg][r];++i)
                    {
                        int c=s[i]-'a';
                        if(cnt[i+1][c]==cnt[pos][c]) continue;
                        while(pos>i) if(s[i]==s[pos]) {ans+=s[i];pos--;f=0;break;}else pos--;
                        if(pos<=i) break;
                    }
                    if(f) ans+=s[g[mg][l]+1];
                    break;
                }
                ans+=mc;
                int pos=g[mg][r]-1;
                for(int i=g[mg][l]+1;i<g[mg][l+1];++i)
                {
                    int c=s[i]-'a';
                    if(cnt[pos][c]==cnt[g[mg][r-1]][c]) continue;
                    while(pos>g[mg][r-1]) if(s[i]==s[pos]) {ans+=s[i];pos--;break;}else pos--;
                    if(pos<=g[mg][r-1]) break;
                }
                l++,r--;
            }
            string ans2=ans;
            reverse(all(ans2));
            if(f) ans.erase(ans.end()-1);
            ans+=ans2;
            if(ans.size()>=s.size()/2) return cout<<ans<<endl,0;
        }
    }
    cout<<"IMPOSSIBLE\n";
}