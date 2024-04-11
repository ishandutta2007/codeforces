#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'
 
int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        string s;
        cin>>s;
        vector<int> v;
        int l=0;
        for(int i=0;i<s.size();++i)
        {
            if(s[i] == 'X')
            {
                if(i-l>0 && i-l>=b) v.push_back(i-l);
                l=i+1;
            }
        }
        if(s.size()-l>0 && s.size()-l>=b) v.push_back(s.size()-l);
        if(!s.size())
        {
            cout << "NO" << endl;
            continue;
        }
        // case 1:
        int ok = 0;
        for(int i:v)
            if( (i>=b && i<a) || i>=4*b+a )
            {
                ok = 1;
                break;
            }
        if(ok)
        {
            cout << "NO" << endl;
            continue;
        }
        // case 2:
        int cnt = 0;
        for(int i:v)
            if(i>=a) cnt++;
        if(!cnt)
        {
            cout << "NO" << endl;
            continue;
        }
        // case 3:
        int cntt = 0;
        for(int i:v) if(i>=2*b) cntt++;
        if(cntt >= 2)
        {
            cout << "NO" << endl;
            continue;
        }
        else if(cntt == 1)
        {
            int mx = 0;
            for(int i:v) mx=max(mx,i);
            assert(mx >= 2*b && mx >= a);
            if( (mx-a+1) / 2 >= 2*b)
            {
                cout << "NO" << endl;
                continue;
            }
            int other = v.size() - 1;
            int ok = 0;
            for(int i=0;i<=mx-a;++i)
            {
                int cut1 = i, cut2 = mx-a-i;
                if(cut1 >= 2*b || cut2 >= 2*b || (cut1>=b && cut1<a) || (cut2>=b && cut2<a)) continue;
                int cnt = 0;
                if(cut1>=a) cnt++;
                if(cut2>=a) cnt++;
                if((other+cnt) % 2 == 0)
                {
                    ok = 1;
                    break;
                }
            }
            if(ok) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else
        {
            if(v.size() % 2) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}