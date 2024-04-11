#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
const ll mod=92233720368547753;
int value(char c)
{
    if(c<'0')
    {
        return 1;
    }
    if(c<'a')
    {
        return c-'0'+2;
    }
    return c-'a'+12;
}
ll Hash(string s)
{
    ll tr=0;
    for(int i=0;i<s.size();i++)
    {
        tr=(tr*38)%mod;
        tr=(tr+value(s[i]))%mod;
    }
    return tr;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<string> niz(n);
    for(int i=0;i<n;i++)
        cin >> niz[i];
    map<ll,string> mapaS;
    map<ll,int> cnt;
    for(int i=0;i<n;i++)
    {
        int m=niz[i].size();
        map<ll,int> dodao;
        for(int j=0;j<m;j++)
        {
            for(int k=j;k<m;k++)
            {
                string s=niz[i].substr(j,k-j+1);
                ll t=Hash(s);
                //cout << s << " "<<t << endl;
                if(cnt[t]==0)
                {
                    mapaS[t]=niz[i];
                    cnt[t]++;
                    dodao[t]=1;
                }
                else
                {
                    if(!dodao[t])
                    {
                        cnt[t]++;
                        dodao[t]=1;
                    }
                }

            }
        }
    }
    int q;
    cin >> q;
    //scanf("%i",&q);
    for(int i=0;i<q;i++)
    {
        string s;
        cin >> s;
        ll t=Hash(s);
        if(cnt[t]==0)
        {
            cout << cnt[t] << " -\n";
        }
        else
            cout << cnt[t] << " " << mapaS[t] << "\n";
    }
    return 0;
}