#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
//random_device rng;
//mt19937 rd(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'
 
void no() {
    cout << "NO" << endl;
    exit(0);
}
vector<int> ans,pre;
void yes() {
    cout << "YES" << endl;
    for(int i : pre) cout << i << " ";
    for(int i : ans) cout << i-1 << " "; cout << endl;
    exit(0);
}
int f(int a,int b,int c,int d)
{
    ans.clear();
    while(a)
    {
        ans.push_back(1);
        a--;
        if(!a && !b && !c && !d) return 1;
        if(a && !b && !c && !d) return 0;
        ans.push_back(2);
        b--;
        if(b<0) return 0;
    }
    if(!b && !c && !d) return 1;
    for(int i=1;i<=b;++i)
    {
        ans.push_back(3);
        ans.push_back(2);
    }
    c -= b;
    if(!c && !d) return 1;
    ans.push_back(3);
    c--;
    if(c < 0) return 0;
    for(int i=1;i<=c;++i)
    {
        ans.push_back(4);
        ans.push_back(3);
    }
    d -= c;
    if(d == 1) {ans.push_back(4);return 1;}
    else if(d == 0) return 1;
    return 0;
}
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a+b+c+d == 1)
    {
        cout << "YES" << endl;
        if(a) cout<<0;
        if(b) cout<<1;
        if(c) cout<<2;
        if(d) cout<<3;
        return 0;
    }
    if(a)
    {
        if(a==1 && !b && !c && !d)
        {
            ans.push_back(1);
            yes();
        }
        if(f(a,b,c,d)) yes();
        if(b)
        {
            b--;
            if(f(a,b,c,d))
            {
                pre.push_back(1);
                yes();
            }
            if(c)
            {
                c--;
                if(f(a,b,c,d))
                {
                    pre.push_back(2);
                    pre.push_back(1);
                    yes();
                }
                if(d)
                {
                    d--;
                    if(f(a,b,c,d))
                    {
                        pre.push_back(3);
                        pre.push_back(2);
                        pre.push_back(1);
                        yes();
                    }
                }
            }
        }
    }
    else if(b)
    {
        if(f(b,c,d,0))
        {
            for(int &i:ans) i++;
            yes();
        }
        if(c)
        {
            c--;
            if(f(b,c,d,0))
            {
                pre.push_back(2);
                for(int &i:ans) i++;
                yes();
            }
            if(d)
            {
                d--;
                if(f(b,c,d,0))
                {
                    pre.push_back(3);
                    pre.push_back(2);
                    for(int &i:ans) i++;
                    yes();
                }
            }
        }
    }
    else if(c)
    {
        if(c == d)
        {
            cout << "YES" << endl;
            for(int i=1;i<=c;++i) cout<<2<<" "<<3<<" ";
            cout<<endl;
        }
        else if(c == d+1)
        {
            cout << "YES" << endl;
            for(int i=1;i<=d;++i) cout<<2<<" "<<3<<" ";
            cout<<2;
            cout<<endl;
        }
        else if(d == c+1)
        {
            cout << "YES" << endl;
            for(int i=1;i<=c;++i) cout<<3<<" "<<2<<" ";
            cout<<3;
            cout<<endl;
        }
        else cout << "NO" << endl;
        return 0;
    }
    else if(d)
    {
        if(d==1)
        {
            cout<<"YES"<<endl;
            cout<<3<<endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        return 0;
    }
    cout << "NO" << endl;
}